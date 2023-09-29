import argparse
import json
import tqdm

from datasets import load_dataset
from pathlib import Path


def main():
    parser = argparse.ArgumentParser(
        description='Check if the training data exists in the pre-training dataset.')
    parser.add_argument('--data_dirs', action='store', nargs='+', required=True,
                        dest='data_dirs', help='All directories to create the dataset.')
    parser.add_argument('--cache_dir', action="store", default='~/.cache/huggingface/datasets',
                        dest='cache_dir', help="The huggingface cache dir")
    args = parser.parse_args()

    pre_train_dataset = load_dataset("codeparrot/github-code-clean", "C++-all", split="train", cache_dir=args.cache_dir)

    train_data_hash = set()

    for data_dir in tqdm.tqdm(
        args.data_dirs, desc='Iterating all data dirs', position=0):
        data_dir = Path(data_dir)
        for jsonl_file in tqdm.tqdm(
            data_dir.rglob('*.jsonl'), desc='Iterating all jsonl files', position=1, leave=False):
            with jsonl_file.open() as f:
                for line in f:
                    submission_pair = json.loads(line)
                    train_data_hash.add(submission_pair['before']['source_code'])

    found = 0
    for pre_train_example in tqdm.tqdm(
        pre_train_dataset, desc='Checking for duplicate', position=0):
        if pre_train_example['code'] in train_data_hash:
            found += 1
            print(f'Current count: {found}')
    print(f'Found {found} examples in the pre-train dataset.')



if __name__ == "__main__":
    main()