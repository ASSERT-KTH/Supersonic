import argparse
import difflib
import json
import random
import tqdm
from pathlib import Path
from unidiff import PatchSet


def main():
    parser = argparse.ArgumentParser(
        description='Generate datasets for training with Huggingface.')
    parser.add_argument('--data_dirs', action='store', nargs='+', required=True,
                        dest='data_dirs', help='All directories to create the dataset.')
    parser.add_argument('--valid_dataset_size', action='store', default=1000,
                        type=int, dest='valid_dataset_size',
                        help='The validation dataset size, default 1000.')
    parser.add_argument('--test_dataset_size', action='store', default=10000,
                        type=int, dest='test_dataset_size',
                        help='The test dataset size, default 10000.')
    parser.add_argument('--output_dir', action='store', required=True,
                        dest='output_dir', help='Dataset output dir.')
    args = parser.parse_args()

    output_dir = Path(args.output_dir)
    output_dir.mkdir(parents=True, exist_ok=True)

    unique_set = set()

    dummy_filename = '/foo/bar.cpp'

    all_samples = []
    all_metadatas = []

    for data_dir in tqdm.tqdm(
        args.data_dirs, desc='Iterating all data dirs', position=0):
        data_dir = Path(data_dir)
        for jsonl_file in tqdm.tqdm(
            data_dir.rglob('*.jsonl'), desc='Iterating all jsonl files', position=1, leave=False):
            with jsonl_file.open() as f:
                for line in f:
                    submission_pair = json.loads(line)
                    before = submission_pair['before']['formatted_source_code']
                    after = submission_pair['after']['formatted_source_code']

                    if (before, after) in unique_set:
                        continue

                    unique_set.add((before, after))

                    before_lines = before.splitlines(True)
                    after_lines = after.splitlines(True)

                    if abs(len(before_lines)-len(after_lines)) / len(before_lines) > 0.2:
                        continue

                    diff = ''.join(list(difflib.unified_diff(
                        before_lines, after_lines, fromfile=dummy_filename, tofile=dummy_filename, n=1)))

                    try:
                        patch = PatchSet(diff)
                    except:
                        continue

                    if not patch:
                        continue

                    if patch[0].added + patch[0].removed > 20:
                        continue

                    if difflib.SequenceMatcher(None, before, after).ratio() < 0.8:
                        continue


                    output = ''
                    for diff_hunk in patch[0]:
                        diff_hunk_str = str(diff_hunk)
                        output += ''.join(diff_hunk_str.splitlines(True)[1:])
                        output += '\n'

                    sample = {
                        'input': before,
                        'output': output,
                    }
                    all_samples.append(sample)
                    all_metadatas.append(submission_pair)

    zipped_list = list(zip(all_samples, all_metadatas))
    random.shuffle(zipped_list)
    all_samples, all_metadatas = zip(*zipped_list)

    train_file = output_dir / 'train.jsonl'
    valid_file = output_dir / 'valid.jsonl'
    test_file = output_dir / 'test.jsonl'
    test_metadata_file = output_dir / 'test_metadata.jsonl'

    with valid_file.open('w') as f:
        for sample in all_samples[:args.valid_dataset_size]:
            json.dump(sample, f)
            f.write('\n')
    
    with test_file.open('w') as f:
        for sample in all_samples[args.valid_dataset_size:args.valid_dataset_size+args.test_dataset_size]:
            json.dump(sample, f)
            f.write('\n')
    with test_metadata_file.open('w') as f:
        for metadata in all_metadatas[args.valid_dataset_size:args.valid_dataset_size+args.test_dataset_size]:
            json.dump(metadata, f)
            f.write('\n')

    with train_file.open('w') as f:
        for sample in all_samples[args.valid_dataset_size+args.test_dataset_size:]:
            json.dump(sample, f)
            f.write('\n')


if __name__ == "__main__":
    main()
