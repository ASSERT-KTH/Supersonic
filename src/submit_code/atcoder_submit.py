import argparse
import atcoder.auth
import atcoder.submission
import atcoder.user_agent
import csv
import getpass
import itertools
import json
import logging
import sys
import time
import tqdm
from pathlib import Path

C_GCC_LANGUAGE_ID = 4001
C_CLANG_LANGUAGE_ID = 4002
CPP_GCC_LANGUAGE_ID = 4003
CPP_CLANG_LANGUAGE_ID = 4004

ID_TO_STATUS = {
    1: 'Accepted',
    2: 'Wrong Answer',
    3: 'Runtime Error',
    4: 'Time Limit Exceeded',
    5: 'Memory Limit Exceeded',
    6: 'Query Limit Exceeded',
    7: 'Compilation Error',
    8: 'Output Limit Exceeded',
    9: 'Internal Error',
    10: 'Waiting for Judging',
    11: 'Waiting for Re-judging',
    12: 'Judging'
}

SLEEP_TIME = 45


def delete_verdict_if_original_fail(prediction_dir):
    original_verdict_file = prediction_dir / 'original_verdict.json'
    if not original_verdict_file.exists():
        return
    
    with original_verdict_file.open() as f:
        original_verdict = json.load(f)
    
    if original_verdict['status'] != 'Accepted':
        for verdict_file in prediction_dir.glob('*verdict*'):
            verdict_file.unlink()


def submit_predictions(prediction_dir, user_agent, contest_id, task_id):
    c_files = list(prediction_dir.glob('*.c'))
    cpp_files = list(prediction_dir.glob('*.cpp'))

    if c_files:
        code_files = c_files
    else:
        code_files = cpp_files

    context_file = prediction_dir / 'context.json'
    with context_file.open() as f:
        context = json.load(f)
        programming_language = context['programming_language']

    if programming_language.startswith('C ') and 'GCC' in programming_language:
        language_id = C_GCC_LANGUAGE_ID
    elif programming_language.startswith('C ') and 'Clang' in programming_language:
        language_id = C_CLANG_LANGUAGE_ID
    elif programming_language.startswith('C++') and 'GCC' in programming_language:
        language_id = CPP_GCC_LANGUAGE_ID
    elif programming_language.startswith('C++') and 'Clang' in programming_language:
        language_id = CPP_CLANG_LANGUAGE_ID
    else:
        raise ValueError(f'Unknown programming language {programming_language}')

    #delete_verdict_if_original_fail(prediction_dir)

    submitted_source_code = []

    for code_file in code_files:
        verdict_file = code_file.parent / (code_file.stem + '_verdict.json')

        if verdict_file.exists():
            previous_status = json.load(verdict_file.open())['status']
            if previous_status:
                logging.info(f'{str(verdict_file)} already exists and is non empty, skipped')
                continue

        source_code = code_file.open().read()

        user_agent.submit(contest_id, task_id, source_code, language_id)
        logging.info(f'Submitted {code_file} to contest id {contest_id}, task id {task_id} and language_id {language_id}.')

        time.sleep(SLEEP_TIME)
        submissions = list(user_agent.fetch_my_submissions(contest_id))
        submissions.sort(key=lambda x: x.summary.datetime, reverse=True)
        while submissions[0].summary.status.value in (10, 11, 12):
            logging.info(f'The latest submission is still running, sleeping for {SLEEP_TIME} seconds.')
            time.sleep(SLEEP_TIME)
            submissions = list(user_agent.fetch_my_submissions(contest_id))
            submissions.sort(key=lambda x: x.summary.datetime, reverse=True)
        submitted_source_code.append((source_code, verdict_file))
    
    if not submitted_source_code:
        return

    submissions = list(filter(lambda x: x.summary.task_id==task_id, submissions))
    for index, (source_code, verdict_file) in enumerate(reversed(submitted_source_code)):
        submission_summary = submissions[index].summary
        if submission_summary.code_size_kb == len(source_code):
            logging.warning(f'Skipping {prediction_dir} because of code size miss match')
            return

        verdict_json = {
            'status': '',
            'exec_time_ms': -1,
            'memory_usage_kb': -1,
        }

        verdict_json['status'] = ID_TO_STATUS[submissions[0].summary.status.value]
        verdict_json['exec_time_ms'] = submissions[0].summary.exec_time_ms
        verdict_json['memory_usage_kb'] = submissions[0].summary.memory_usage_kb

        with verdict_file.open('w') as f:
            json.dump(verdict_json, f)
            f.write('\n')


def read_codenet_problem_csv(codenet_problem_csv_path):
    atcoder_problems = {}
    with codenet_problem_csv_path.open() as f:
        csv_reader = csv.reader(f, delimiter=',')
        next(csv_reader)
        for line in csv_reader:
            if line[2] == 'AtCoder':
                atcoder_problems[line[0]] = line[1]
    return atcoder_problems


def main():
    parser = argparse.ArgumentParser(
        description='Submit to AtCoder.')
    parser.add_argument('--submission_dir', action='store', required=True,
                        dest='submission_dir', help='The directory to all submissions.')
    parser.add_argument('--codenet_problem_csv', action='store', required=True,
                        dest='codenet_problem_csv', help='The codenet problem_list.csv file.')
    parser.add_argument('--atcoder_problem_file', action='store', required=True,
                        dest='atcoder_problem_file', help='The AtCoder problems list file.')
    parser.add_argument('--logging_file', action='store', default='',
                        dest='logging_file', help='The logging file, else it will use stdout.')
    parser.add_argument('--atcoder_username', action='store', required=True,
                        dest='atcoder_username', help='AtCoder username.')
    args = parser.parse_args()

    submission_dir = Path(args.submission_dir).resolve()
    atcoder_problem_file = Path(args.atcoder_problem_file).resolve()
    codenet_problem_csv = Path(args.codenet_problem_csv).resolve()

    if args.logging_file:
        logging.basicConfig(filename=args.logging_file, filemode='w', level=logging.DEBUG)
    else:
        logging.basicConfig(stream=sys.stdout, level=logging.DEBUG)

    with atcoder_problem_file.open() as f:
        atcoder_problem_metadata = json.load(f)

    password = getpass.getpass(prompt=f'Password for {args.atcoder_username}: ')

    credentials = atcoder.auth.LoginCredentials(args.atcoder_username, password)
    user_agent = atcoder.user_agent.UserSessionAgent(credentials)

    atcoder_problems = read_codenet_problem_csv(codenet_problem_csv)

    codenet_submission_dir = submission_dir / 'Codenet'
    for problem_dir in tqdm.tqdm(codenet_submission_dir.iterdir(), position=0):
        if problem_dir.name not in atcoder_problems:
            continue

        if problem_dir.name in ('p02618', 'p02871', 'p02872'):
            continue

        problem_name = atcoder_problems[problem_dir.name].split('-')[-1].strip()
        contest_id = None
        task_id = None
        for metadata in atcoder_problem_metadata:
            if problem_name == metadata['name']:
                contest_id = metadata['contest_id']
                task_id = metadata['id']
                break
        if contest_id is None or task_id is None:
            logging.warning(f'{problem_name} not found in the AtCoder metadata')
            continue

        for original_file in tqdm.tqdm(itertools.chain(problem_dir.rglob('original.cpp'), problem_dir.rglob('original.c')), position=1, leave=False):
            prediction_dir = original_file.parent
            submit_predictions(prediction_dir, user_agent, contest_id, task_id)


if __name__ == "__main__":
    main()