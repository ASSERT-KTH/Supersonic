import argparse
import json
import tqdm
from pathlib import Path


def generate_submission_dir(dir_path, pred, metadata, submissions):
    if 'C++' in metadata['before']['programming_language'] or metadata['before']['programming_language'] == 'cpp':
        extension = '.cpp'
    else:
        extension = '.c'

    original_file = dir_path / ('original' + extension)
    with original_file.open('w', encoding='utf-8') as f:
        f.write(pred['input'])
    improved_file = dir_path / ('improved' + extension)
    with improved_file.open('w', encoding='utf-8') as f:
        f.write(metadata['after']['formatted_source_code'])
    context_file = dir_path / 'context.json'
    with context_file.open('w', encoding='utf-8') as f:
        json.dump({
            'author': metadata['before']['author'],
            'contest_id': metadata['before']['contest_id'],
            'submission_id': metadata['before']['submission_id'],
            'problem': metadata['before']['problem'],
            'programming_language': metadata['before']['programming_language'],
        }, f)

    for index, predicted_submission in enumerate(submissions):
        if not predicted_submission:
            continue

        pred_file = dir_path / (str(index) + extension)
        with pred_file.open('w', encoding='utf-8') as f:
            f.write(predicted_submission)


def main():
    parser = argparse.ArgumentParser(
        description='Format the prediction.')
    parser.add_argument('--test_metadata_file', action="store", required=True,
                        dest='test_metadata_file', help="The test metadata jsonl file")
    parser.add_argument('--prediction_submission_file', action="store", required=True,
                        dest='prediction_submission_file', help="The prediction submission jsonl file")
    parser.add_argument('--output_dir', action="store", required=True,
                        dest='output_dir', help="The output directory")
    args = parser.parse_args()

    test_metadata_file = Path(args.test_metadata_file).resolve()
    prediction_submission_file = Path(args.prediction_submission_file).resolve()
    output_dir = Path(args.output_dir).resolve()

    tm_file = test_metadata_file.open()
    ps_file = prediction_submission_file.open()

    for tm_line, ps_line in tqdm.tqdm(zip(tm_file, ps_file)):
        metadata = json.loads(tm_line)
        pred = json.loads(ps_line)

        if metadata['before']['origin'] == 'Codeforces':
            pred_dir = output_dir / 'Codeforces' / str(metadata['before']['contest_id']) / str(metadata['before']['submission_id'])
        else:
            pred_dir = output_dir / 'Codenet' / metadata['before']['problem'] / str(metadata['before']['submission_id'])

        pred_dir.mkdir(parents=True, exist_ok=True)
        generate_submission_dir(pred_dir, pred, metadata, pred['beam_search_submissions'])


if __name__ == "__main__":
    main()