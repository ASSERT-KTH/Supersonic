""" Extract changed code inside a function.

Example usage:

python3 extract_func_pairs_beam.py \
  --region europe-west4 \
  --runner DataflowRunner \
  --project assert-experiments \
  --temp_location gs://zimin-bucket/tmp/ \
  --bucket_id zimin-bucket \
  --input_prefix code-optimization/codeforces_memory \
  --deps_path gs://zimin-bucket/libs/extract_func_pairs_beam-0.1.0.tar.gz \
  --output_pattern gs://zimin-bucket/code-optimization/codeforces_memory_diffs/data \
  --worker_machine_type n1-standard-4 \
  --no_use_public_ips \
  --network default \
  --subnetwork regions/europe-west4/subnetworks/default
"""

import argparse
import apache_beam as beam
import json
import logging
import os
from typing import Sequence
from apache_beam.options.pipeline_options import PipelineOptions

from google.cloud import storage


class JsonCoder(beam.coders.Coder):
  def encode(self, x):
    return json.dumps(x).encode('utf-8')

  def decode(self, x):
    return json.loads(x).decode('utf-8')


class ExtractFuncDiffFn(beam.DoFn):
    def __init__(self, deps_path: str, max_file_size: int = 20000):
        self.clang_index = None
        self.deps_path = deps_path
        self.max_file_size = max_file_size

    def setup(self):
        import subprocess

        logging.info('Start installing python deps.')
        subprocess.call(['sudo', 'apt-get', 'update'])
        subprocess.call(['gsutil', 'cp', self.deps_path, '.'])
        subprocess.call(['pip', 'install', '--user',
                         os.path.basename(self.deps_path)])
        logging.info('Installing python deps finished.')

        import clang.cindex

        self.clang_index = clang.cindex.Index.create()

    def walk_with_depth(self, root, depth=0, max_depth=2):
        if depth < max_depth:
            for node in root.get_children():
                yield node
                self.walk_with_depth(node, depth=depth+1, max_depth=max_depth)

    def get_func_pair_diff(self, before_source_code: str, after_source_code: str, programming_language: str):
        if (len(before_source_code.encode('utf-8')) > self.max_file_size or
            len(after_source_code.encode('utf-8')) > self.max_file_size):
            return

        import difflib
        from clang.cindex import CursorKind
        if 'C++' in programming_language:
            before_tmp_filename = './tmp_before.cpp'
            after_tmp_filename = './tmp_after.cpp'
        else:
            before_tmp_filename = './tmp_before.c'
            after_tmp_filename = './tmp_after.c'
        before_tu = self.clang_index.parse(before_tmp_filename, unsaved_files=[(before_tmp_filename, before_source_code)])
        after_tu = self.clang_index.parse(after_tmp_filename, unsaved_files=[(after_tmp_filename, after_source_code)])

        before_func_decl_cursor_list = []
        after_func_decl_cursor_list = []

        for cursor in self.walk_with_depth(before_tu.cursor):
            if (cursor.kind == CursorKind.FUNCTION_DECL or cursor.kind == CursorKind.CXX_METHOD) and cursor.is_definition():
                before_func_decl_cursor_list.append(cursor)
        for cursor in self.walk_with_depth(after_tu.cursor):
            if (cursor.kind == CursorKind.FUNCTION_DECL or cursor.kind == CursorKind.CXX_METHOD) and cursor.is_definition():
                after_func_decl_cursor_list.append(cursor)

        func_decl_cursor_key = lambda c: (c.spelling, c.location.line)

        before_func_decl_cursor_list.sort(key=func_decl_cursor_key)
        after_func_decl_cursor_list.sort(key=func_decl_cursor_key)

        before_index = 0
        after_index = 0
        before_max_index = len(before_func_decl_cursor_list)
        after_max_index = len(after_func_decl_cursor_list)

        func_diffs = []
        before_func_diffs_start_char_indices = []
        before_func_diffs_end_char_indices = []
        after_func_diffs_start_char_indices = []
        after_func_diffs_end_char_indices = []
        while(before_index < before_max_index):
            before_func_decl_cursor = before_func_decl_cursor_list[before_index]
            for index in range(after_index, after_max_index):
                after_func_decl_cursor = after_func_decl_cursor_list[index]
                if(before_func_decl_cursor.spelling == after_func_decl_cursor.spelling):
                    before_func_diffs_start_char_index = before_func_decl_cursor.extent.begin_int_data-2
                    before_func_diffs_end_char_index = before_func_decl_cursor.extent.end_int_data-2
                    after_func_diffs_start_char_index = after_func_decl_cursor.extent.begin_int_data-2
                    after_func_diffs_end_char_index = after_func_decl_cursor.extent.end_int_data-2
                    before_func_decl_cursor_str = before_source_code[before_func_diffs_start_char_index:before_func_diffs_end_char_index]
                    after_func_decl_cursor_str = after_source_code[after_func_diffs_start_char_index:after_func_diffs_end_char_index]
                    before_func_decl_cursor_str = before_func_decl_cursor_str.rstrip('\n') + '\n'
                    after_func_decl_cursor_str = after_func_decl_cursor_str.rstrip('\n') + '\n'
                    diff = list(difflib.unified_diff(before_func_decl_cursor_str.splitlines(True), after_func_decl_cursor_str.splitlines(True),
                                                     fromfile=before_tmp_filename, tofile=after_tmp_filename, n=1000000))
                    if diff:
                        func_diffs.append(''.join(diff))
                        before_func_diffs_start_char_indices.append(before_func_diffs_start_char_index)
                        before_func_diffs_end_char_indices.append(before_func_diffs_end_char_index)
                        after_func_diffs_start_char_indices.append(after_func_diffs_start_char_index)
                        after_func_diffs_end_char_indices.append(after_func_diffs_end_char_index)
                    after_index = index + 1
            before_index += 1
        return (func_diffs, before_func_diffs_start_char_indices,
                before_func_diffs_end_char_indices,
                after_func_diffs_start_char_indices,
                after_func_diffs_end_char_indices)

    def process(self, submission_pair: dict):
        before_source_code = submission_pair['before']['before_formatted_source_code']
        after_source_code = submission_pair['after']['after_formatted_source_code']
        programming_language = submission_pair['before']['programming_language']
        try:
            (func_diffs, before_func_diffs_start_char_indices,
             before_func_diffs_end_char_indices,
             after_func_diffs_start_char_indices,
             after_func_diffs_end_char_indices) = self.get_func_pair_diff(
                before_source_code, after_source_code, programming_language)
            if func_diffs:
                submission_pair['func_diffs'] = func_diffs
                submission_pair['before']['func_diffs_start_char_indices'] = before_func_diffs_start_char_indices
                submission_pair['before']['func_diffs_end_char_indices'] = before_func_diffs_end_char_indices
                submission_pair['after']['func_diffs_start_char_indices'] = after_func_diffs_start_char_indices
                submission_pair['after']['func_diffs_end_char_indices'] = after_func_diffs_end_char_indices
                yield submission_pair
        except Exception as e:
            pass

def main_pipeline(root: beam.Pipeline, input_files: Sequence[str],
                  output_pattern: str, deps_path: str):
    _ = (
        root
        | 'Create input file pCollection' >> beam.Create(input_files)
        | 'Read files' >> beam.io.textio.ReadAllFromText()
        | 'Parse as json' >> beam.Map(json.loads)
        | 'Extract function pair diffs' >> beam.ParDo(ExtractFuncDiffFn(deps_path))
        | f'Write to {output_pattern}' >> beam.io.textio.WriteToText(output_pattern, file_name_suffix='.jsonl', coder=JsonCoder())
    )


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument(
        '--bucket_id', required=True, help='GCS bucket id.')
    parser.add_argument(
        '--input_prefix', required=True, help='Filename prefix on GCS.')
    parser.add_argument(
        '--deps_path', required=True, help='pip tar.gz file on GCS.')
    parser.add_argument(
        '--output_pattern', required=True, help='Output files pattern.')
    args, beam_args = parser.parse_known_args()
    beam_options = PipelineOptions(beam_args)

    storage_client = storage.Client()
    blobs = storage_client.list_blobs(args.bucket_id, prefix=args.input_prefix)
    input_files = [
        os.path.join('gs://', args.bucket_id, blob.name)
        for blob in blobs
        if blob.name.endswith('.jsonl')
    ]

    with beam.Pipeline(options=beam_options) as pipeline:
        main_pipeline(pipeline, input_files, args.output_pattern,
                      args.deps_path)

if __name__ == "__main__":
    main()
