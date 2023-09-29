import argparse
import csv
import dataclasses
import functools
import hashlib
import json
import sys
import tqdm
from concurrent.futures import TimeoutError
from pathlib import Path
from pebble import ProcessPool

sys.path.insert(1, str(Path(__file__).parent.parent / 'codeforces-crawler'))

from helper import Submission


SUBMISSION_BATCH_SIZE = 10000


def parse_submissions(csv_file_path: Path, output_dir: Path):
    contest_dir = output_dir / str(csv_file_path.stem)
    contest_dir.mkdir(exist_ok=True)

    all_user_submissions = {}
    all_user_submissions_count = 0
    with csv_file_path.open() as csv_file:
        csv_reader = csv.reader(csv_file, delimiter=',')
        next(csv_reader)
        for row in csv_reader:
            if row[7] == 'Accepted':
                submission = Submission(
                    origin="Codenet",
                    author=row[2],
                    contest_id=int(row[1][1:]),
                    submission_id=int(row[0][1:]),
                    creation_time_seconds=int(row[3]),
                    problem=row[1],
                    programming_language=row[5],
                    time_consumed_millis=int(row[8]),
                    memory_consumed_bytes=int(row[9])
                )

                if submission.author not in all_user_submissions:
                    all_user_submissions[submission.author] = {}
                if submission.problem not in all_user_submissions[submission.author]:
                    all_user_submissions[submission.author][submission.problem] = []
                all_user_submissions[submission.author][submission.problem].append(dataclasses.asdict(submission))
                all_user_submissions_count += 1
                if all_user_submissions_count == SUBMISSION_BATCH_SIZE:
                    save_submissions_to_file(all_user_submissions, contest_dir)
                    all_user_submissions.clear()
                    all_user_submissions_count = 0
    save_submissions_to_file(all_user_submissions, contest_dir)


def save_submissions_to_file(all_user_submissions: dict, contest_dir: Path):
    for author in all_user_submissions:
        author_hash = hashlib.sha1(author.encode('utf-8')).hexdigest()
        output_file = contest_dir / (author_hash+'.json')
        if output_file.exists():
            with open(output_file) as f:
                user_submissions = json.load(f)
            for problem in all_user_submissions[author]:
                if problem in user_submissions:
                    user_submissions[problem].extend(all_user_submissions[author][problem])
                else:
                    user_submissions[problem] = all_user_submissions[author][problem]
        else:
            user_submissions = all_user_submissions[author]

        with open(output_file, 'w') as f:
            json.dump(user_submissions, f)


def main():
    parser = argparse.ArgumentParser(
        description='Parse codenet csv files.')
    parser.add_argument('-d', '--data_dir', action='store',
                        dest='data_dir', help='Path to the submission data.')
    parser.add_argument('-o', '--output_dir', action='store',
                        dest='output_dir', help='Path to store the output.')
    parser.add_argument('--number_of_processes', type=int, default=4,
                        dest='number_of_processes',
                        help='Number of processes, default to 4.')
    parser.add_argument('--timeout', type=int, default=600,
                        dest='timeout',
                        help='Timeout per process, default to 600s.')
    args = parser.parse_args()

    data_dir = Path(args.data_dir).resolve()
    output_dir = Path(args.output_dir).resolve()
    output_dir.mkdir(parents=True, exist_ok=True)
    metadata_dir = data_dir / 'metadata'
    metadata_files = list(metadata_dir.glob('p*.csv'))

    pbar = tqdm.tqdm(total=len(metadata_files), desc='Iterating over all csv files.')
    with ProcessPool(max_workers=args.number_of_processes) as pool:
        future = pool.map(functools.partial(parse_submissions, output_dir=output_dir), metadata_files, timeout=args.timeout)
        iterator = future.result()
        while True:
            try:
                next(iterator)
            except StopIteration:
                break
            except TimeoutError as error:
                pass
            except Exception as error:
                print(f'Function raised {str(error)}')
            pbar.update()
        pbar.close()


if __name__ == "__main__":
    main()
