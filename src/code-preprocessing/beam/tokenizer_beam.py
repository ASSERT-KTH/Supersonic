import argparse
import apache_beam as beam
import json
import logging
import timeout_decorator
from typing import Sequence
from apache_beam.options.pipeline_options import PipelineOptions

from google.cloud import storage


class JsonCoder(beam.coders.Coder):
  def encode(self, x):
    return json.dumps(x).encode('utf-8')

  def decode(self, x):
    return json.loads(x).decode('utf-8')


class ExtractFuncDiffTokensFn(beam.DoFn):
    def __init__(self):
        self.clang_index = None

    def setup(self):
        import clang.cindex
        self.clang_index = clang.cindex.Index.create()

    @timeout_decorator.timeout(30, use_signals=False, timeout_exception=TimeoutError)
    def get_function_diff_tokens(self, func_diff_str: str):
        from unidiff import PatchSet
        patch = PatchSet(func_diff_str)

        before_version_function = [line[1:] for line in patch[0][0].source]
        after_version_function = [line[1:] for line in patch[0][0].target]

        before_version_function_str = ''.join(before_version_function)
        after_version_function_str = ''.join(after_version_function)

        if ''.join(before_version_function_str) == ''.join(after_version_function_str):
            return None, None

        tu_before = self.clang_index.parse(patch[0].source_file, unsaved_files=[(patch[0].source_file, before_version_function_str)])
        tu_after = self.clang_index.parse(patch[0].target_file, unsaved_files=[(patch[0].target_file, after_version_function_str)])

        before_version_tokens = []
        after_version_tokens = []
        for token in tu_before.cursor.get_tokens():
            before_version_tokens.append(repr(token.spelling.replace(' ', '<__whitespace_in_literal__>'))[1:-1])
        for token in tu_after.cursor.get_tokens():
            after_version_tokens.append(repr(token.spelling.replace(' ', '<__whitespace_in_literal__>'))[1:-1])
        return before_version_tokens, after_version_tokens

    def process(self, submission_pair: dict):
        before_version_function_token_list = []
        after_verison_function_token_list = []
        for func_diff_str in submission_pair['func_diffs']:
            try:
                before_version_function_tokens, after_version_function_tokens = self.get_function_diff_tokens(func_diff_str)
                if before_version_function_tokens and after_version_function_tokens:
                    before_version_function_token_list.append(before_version_function_tokens)
                    after_verison_function_token_list.append(after_version_function_tokens)
            except Exception as e:
                continue
        if before_version_function_token_list and after_verison_function_token_list:
            submission_pair['before']['function_diff_tokens'] = before_version_function_token_list
            submission_pair['after']['function_diff_tokens'] = after_verison_function_token_list
            yield submission_pair

def main_pipeline(root: beam.Pipeline, input_files: Sequence[str],
                  output_pattern: str):
    _ = (
        root
        | 'Create input file pCollection' >> beam.Create(input_files)
        | 'Read files' >> beam.io.textio.ReadAllFromText()
        | 'Reshuffle after read' >> beam.Reshuffle()
        | 'Parse as json' >> beam.Map(json.loads)
        | 'Extract function pair tokens' >> beam.ParDo(ExtractFuncDiffTokensFn())
        | f'Write to {output_pattern}' >> beam.io.textio.WriteToText(output_pattern, file_name_suffix='.jsonl', coder=JsonCoder())
    )


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument(
        '--bucket_id', required=True, help='GCS bucket id.')
    parser.add_argument(
        '--input_prefix', required=True, help='Filename prefix on GCS.')
    parser.add_argument(
        '--output_pattern', required=True, help='Output files pattern.')
    args, beam_args = parser.parse_known_args()
    beam_options = PipelineOptions(beam_args)

    storage_client = storage.Client()
    blobs = storage_client.list_blobs(args.bucket_id, prefix=args.input_prefix)
    input_files = [
        blob.name
        for blob in blobs
        if blob.name.endswith('.jsonl')
    ]

    with beam.Pipeline(options=beam_options) as pipeline:
        main_pipeline(pipeline, input_files, args.output_pattern)

if __name__ == "__main__":
    main()
