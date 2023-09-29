import argparse
import dataclasses
import collections
import functools
import hashlib
import json
import multiprocessing
import requests
import sys
import tqdm
import time
from pathlib import Path
from requests.adapters import HTTPAdapter
from requests.packages.urllib3.util.retry import Retry
from tqdm.contrib.concurrent import process_map
from typing import TextIO, Union
from helper import codeforce_call
from helper import init_process
from helper import Submission
from helper import TimeoutHTTPAdapter


CONTEST_LIST = 'contest.list'
CONTEST_STATUS = 'contest.status'
SUBMISSION_BATCH_SIZE = 10000
session = None


def check_submission_fields_exists(submission_json: dict) -> bool:
    fields = ['id', 'creationTimeSeconds', 'problem', 'author',
              'programmingLanguage', 'verdict', 'timeConsumedMillis',
              'memoryConsumedBytes']
    if not all(field in submission_json for field in fields):
        return False

    if 'name' not in submission_json['problem']:
        return False

    if 'teamId' in submission_json['author']:
        if 'teamName' not in submission_json['author']:
            return False
    else:
        if 'members' not in submission_json['author']:
            return False

        if len(submission_json['author']['members']) == 0:
            return False

        if 'handle' not in submission_json['author']['members'][0]:
            return False

    return True


def check_if_done(log_file_path: Path) -> bool:
    with log_file_path.open() as f:
        for line in f:
            if line.startswith('WARNING') and 'failed with status code "503"' in line:
                return False
        last_line = line
        if last_line.startswith('Done'):
            return True
    return False


def remove_all_submissions(contest_dir: Path):
    for file in contest_dir.glob('*'):
        file.unlink()


def process_contest(contest: dict, output_dir: Path=Path('/tmp')):
    contest_dir = output_dir / str(contest['id'])
    contest_dir.mkdir(exist_ok=True)
    log_file_path = contest_dir / 'log.txt'

    if log_file_path.exists():
        if check_if_done(log_file_path):
            return

    log_file = log_file_path.open('w')
    all_user_submissions = {}
    all_user_submissions_count = 0
    submission_from = 1
    while True:
        submission_jsons, success = codeforce_call(
            CONTEST_STATUS,
            {
                'contestId': contest['id'],
                'from': submission_from,
                'count': SUBMISSION_BATCH_SIZE
            },
            True,
            log_file)
        for _ in range(4):
            if success:
                break
            time.sleep(60)
            submission_jsons, success = codeforce_call(
                CONTEST_STATUS,
                {
                    'contestId': contest['id'],
                    'from': submission_from,
                    'count': SUBMISSION_BATCH_SIZE
                },
                True,
                log_file)
        if submission_jsons:
            for submission_json in submission_jsons:
                if not check_submission_fields_exists(submission_json):
                    log_file.write(f'WARNING: submissionId {submission_json["id"]} is missing some fields.\n')
                    log_file.flush()
                    continue
                
                if submission_json['id'] > 128_000_000:
                    log_file.write(f'INFO: submissionId {submission_json["id"]} skiped, since it is larger than 128M.\n')
                    log_file.flush()
                    continue

                if submission_json['verdict'] != 'OK':
                    log_file.write(f'INFO: submissionId {submission_json["id"]} has verdict {submission_json["verdict"]} is dropped.\n')
                    log_file.flush()
                    continue

                if 'teamId' in submission_json['author']:
                    author = 'TEAM' + '_' + str(submission_json['author']['teamId']) + '_' + submission_json['author']['teamName']
                else:
                    author = submission_json['author']['members'][0]['handle']

                problem = submission_json['problem']['name']

                submission = Submission(
                    origin="Codeforces",
                    author=author,
                    contest_id=contest['id'],
                    submission_id=submission_json['id'],
                    creation_time_seconds=submission_json['creationTimeSeconds'],
                    problem=problem,
                    programming_language=submission_json['programmingLanguage'],
                    time_consumed_millis=submission_json['timeConsumedMillis'],
                    memory_consumed_bytes=submission_json['memoryConsumedBytes']
                )

                if author not in all_user_submissions:
                    all_user_submissions[author] = {}
                if problem not in all_user_submissions[author]:
                    all_user_submissions[author][problem] = []
                all_user_submissions[author][problem].append(dataclasses.asdict(submission))
                all_user_submissions_count += 1
                if all_user_submissions_count == SUBMISSION_BATCH_SIZE:
                    save_submissions_to_file(all_user_submissions, contest_dir)
                    all_user_submissions.clear()
                    all_user_submissions_count = 0
            submission_from += SUBMISSION_BATCH_SIZE
            time.sleep(10)
        else:
            break
    save_submissions_to_file(all_user_submissions, contest_dir)
    log_file.write('Done\n')
    log_file.close()


def save_submissions_to_file(all_user_submissions: dict, contest_dir: Path):
    for author in all_user_submissions:
        author_hash = hashlib.sha1(author.encode('utf-8')).hexdigest()
        output_file = contest_dir / (author_hash+'.json')
        if output_file.exists():
            with open(output_file) as f:
                user_submissions = json.load(f)
            for problem in all_user_submissions[author]:
                if problem in user_submissions:
                    existing_submission_ids = {submission['submission_id'] for submission in user_submissions[problem]}
                    crawled_submission_ids = {submission['submission_id'] for submission in all_user_submissions[author][problem]}
                    new_submission_ids = crawled_submission_ids - existing_submission_ids
                    for submission in user_submissions[problem]:
                        if submission['submission_id'] in new_submission_ids:
                            user_submissions[problem].append(submission)
                else:
                    user_submissions[problem] = all_user_submissions[author][problem]
        else:
            user_submissions = all_user_submissions[author]

        with open(output_file, 'w') as f:
            json.dump(user_submissions, f)
            f.write('\n')


def main():
    parser = argparse.ArgumentParser(
        description='Crawl codeforeces submissions to all contests.')
    parser.add_argument('-o', '--output_dir', action='store',
                        dest='output_dir', help='Path to store the output.')
    parser.add_argument('--number_of_processes', type=int, default=4,
                        dest='number_of_processes',
                        help='Number of processes, default to 4.')
    args = parser.parse_args()

    output_dir = Path(args.output_dir).resolve()
    output_dir.mkdir(parents=True, exist_ok=True)

    init_process()
    contests, success = codeforce_call(CONTEST_LIST, {'gym': False}, True, sys.stdout)
    if not success:
        print('Failed to get contest list.')
        sys.exit(1)
    contests.sort(key=lambda x: x['id'])

    with multiprocessing.Pool(processes=args.number_of_processes, initializer=init_process) as p:
        with tqdm.tqdm(total=len(contests), desc='Processing all contests.') as pbar:
            for _ in p.imap_unordered(functools.partial(process_contest, output_dir=output_dir), contests):
                pbar.update()


if __name__ == "__main__":
    main()
