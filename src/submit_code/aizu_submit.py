import argparse
import csv
import json
import logging
import itertools
import getpass
import requests
import sys
import tqdm
import time
from pathlib import Path
from typing import Tuple


session = None
END_POINT = 'https://judgeapi.u-aizu.ac.jp'
MAX_TRIES = 3
SLEEP_TIME = 30

ID_TO_STATES = {
    -1: 'STATE_UNKNOWN',
    0: 'STATE_COMPILEERROR',
    1: 'STATE_WRONGANSWER',
    2: 'STATE_TIMELIMIT',
    3: 'STATE_MEMORYLIMIT',
    4: 'STATE_ACCEPTED',
    5: 'STATE_WAITING',
    6: 'STATE_OUTPUTLIMIT',
    7: 'STATE_RUNTIMEERROR',
    8: 'STATE_PRESENTATIONERROR',
    9: 'STATE_RUNNING',
}
STATES_TO_ID = {v: k for k, v in ID_TO_STATES.items()}


def login(username: str, password: str) -> bool:
    current_try = 0
    while(current_try < MAX_TRIES):
        response = session.post(
            END_POINT + '/session',
            json={
                'id': username,
                'password': password,
            }
        )
        if response.ok:
            logging.info('Login sucessful')
            return True

        current_try += 1
        time.sleep(SLEEP_TIME)
    logging.warning('Login failed')
    return False


def find_problem_id(problem_name: str, time_limit: int, memory_limit: int) -> Tuple[bool, str]:
    current_try = 0
    while(current_try < MAX_TRIES):
        response = session.get(END_POINT + f'/problems/titles/{problem_name}')

        if response.ok:
            response_json = response.json()
            logging.info(f"Found {response_json['numberOfProblems']} problems with name {problem_name}")
            if response_json['numberOfProblems'] > 0:
                for problem_json in response_json['problems']:
                    same_name = problem_json['name'] == problem_name
                    same_time = time_limit == -1 or problem_json['problemTimeLimit']*1000 == time_limit
                    same_memory = memory_limit == -1 or problem_json['problemMemoryLimit'] == memory_limit
                    if same_name and same_time and same_memory:
                        return True, problem_json['id']
            return False, ''

        current_try += 1
        time.sleep(SLEEP_TIME)
    logging.warning(f'Find problem id failed for {problem_name}')
    return False, ''


def submit(problem_id: str, language: str, source_code: str) -> Tuple[bool, str]:
    current_try = 0
    while(current_try < MAX_TRIES):
        response = session.post(
            END_POINT + '/submissions',
            json={
                'problemId': problem_id,
                'language': language,
                'sourceCode': source_code,
            }
        )

        if response.ok:
            logging.info(f"Submit sucessful, got token: {response.json()['token']}")
            return True, response.json()['token']

        current_try += 1
        time.sleep(SLEEP_TIME)
    logging.warning('Submit failed')
    return False, ''
    

def get_judge_id(token: str) -> int:
    current_try = 0
    while(current_try < MAX_TRIES):
        response = session.get(
            END_POINT + '/submission_records/recent'
        )

        if response.ok:
            for submission in response.json():
                if submission['token'] == token:
                    logging.info(f"Get judgeId sucessful: {submission['judgeId']}")
                    return True, submission['judgeId']

        current_try += 1
        time.sleep(SLEEP_TIME)
    logging.warning('Get judgeId failed')
    return False, -1


def get_verdict(judge_id: int) -> Tuple[bool, int, int, int]:
    current_try = 0
    while(current_try < MAX_TRIES):
        response = session.get(
            END_POINT + f'/verdicts/{judge_id}'
        )

        if response.ok:
            submission_record = response.json()['submissionRecord']
            if submission_record['status'] == STATES_TO_ID['STATE_RUNNING'] or submission_record['status'] == STATES_TO_ID['STATE_WAITING']:
                time.sleep(SLEEP_TIME)
                continue

            logging.info(f"Get verdit sucessful for judgeId {judge_id}. status: {submission_record['status']}, "
                         f"cpu_time: {submission_record['cpuTime']}, memory: {submission_record['memory']}")
            return True, submission_record['status'], submission_record['cpuTime'], submission_record['memory']


        current_try += 1
        time.sleep(SLEEP_TIME)

    logging.warning("Get verdit failed for judgeId {judge_id}")
    return False, -1, -1, -1


def delete_verdict_if_original_fail(prediction_dir):
    original_verdict_file = prediction_dir / 'original_verdict.json'
    if not original_verdict_file.exists():
        return
    
    with original_verdict_file.open() as f:
        original_verdict = json.load(f)
    
    if original_verdict['status'] != 'STATE_ACCEPTED':
        for verdict_file in prediction_dir.glob('*verdict*'):
            verdict_file.unlink()


def submit_predictions(prediction_dir, problem_id_successful, problem_id):
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

    delete_verdict_if_original_fail(prediction_dir)

    for code_file in code_files:
        verdict_json = {
            'problem_id_successful': problem_id_successful,
            'problem_id': problem_id,
            'submit_sucess': False,
            'token': '',
            'get_judge_sucess': False,
            'judge_id': '',
            'get_verdict_sucess': False,
            'status': '',
            'cpu_time': -1,
            'memory': -1,
        }
        verdict_file = code_file.parent / (code_file.stem + '_verdict.json')

        if verdict_file.exists() and json.load(verdict_file.open())['get_verdict_sucess']:
            continue

        if not problem_id_successful:
            with verdict_file.open('w') as f:
                json.dump(verdict_json, f)
                f.write('\n')
            continue

        try:
            with code_file.open() as f:
                source_code = f.read()
        except UnicodeDecodeError as e:
            logging.warning(f'Failed to open and read {code_file}')
            with verdict_file.open('w') as f:
                json.dump(verdict_json, f)
                f.write('\n')
            continue
        submit_sucess, token = submit(problem_id, programming_language, source_code)
        if not submit_sucess:
            with verdict_file.open('w') as f:
                json.dump(verdict_json, f)
                f.write('\n')
            continue
        verdict_json['submit_sucess'] = True
        verdict_json['token'] = token
        
        get_judge_sucess, judge_id = get_judge_id(token)
        if not get_judge_sucess:
            with verdict_file.open('w') as f:
                json.dump(verdict_json, f)
                f.write('\n')
            continue
        verdict_json['get_judge_sucess'] = True
        verdict_json['judge_id'] = judge_id

        get_verdict_sucess, status, cpu_time, memory = get_verdict(judge_id)
        if not get_verdict_sucess:
            with verdict_file.open('w') as f:
                json.dump(verdict_json, f)
                f.write('\n')
            continue
        verdict_json['get_verdict_sucess'] = get_verdict_sucess
        verdict_json['status'] = ID_TO_STATES[status]
        verdict_json['cpu_time'] = cpu_time
        verdict_json['memory'] = memory

        with verdict_file.open('w') as f:
            json.dump(verdict_json, f)
            f.write('\n')



def read_codenet_problem_csv(codenet_problem_csv_path):
    aizu_problems = {}
    with codenet_problem_csv_path.open() as f:
        csv_reader = csv.reader(f, delimiter=',')
        next(csv_reader)
        for line in csv_reader:
            if line[2] == 'AIZU':
                if line[3]:
                    time_limit = int(line[3])
                else:
                    time_limit = -1

                if line[4]:
                    memory_limit = int(line[4])
                else:
                    memory_limit = -1
                aizu_problems[line[0]] = (line[1], time_limit, memory_limit)
    return aizu_problems


def main():
    parser = argparse.ArgumentParser(
        description='Submit to Aizu Online Judge.')
    parser.add_argument('--submission_dir', action='store', required=True,
                        dest='submission_dir', help='The directory to all submissions.')
    parser.add_argument('--codenet_problem_csv', action='store', required=True,
                        dest='codenet_problem_csv', help='The codenet problem_list.csv file.')
    parser.add_argument('--logging_file', action='store', default='',
                        dest='logging_file', help='The logging file, else it will use stdout.')
    parser.add_argument('--aizu_username', action='store', required=True,
                        dest='aizu_username', help='AIZU username.')
    args = parser.parse_args()

    submission_dir = Path(args.submission_dir).resolve()
    codenet_problem_csv = Path(args.codenet_problem_csv).resolve()

    if args.logging_file:
        logging.basicConfig(filename=args.logging_file, filemode='w', level=logging.DEBUG)
    else:
        logging.basicConfig(stream=sys.stdout, level=logging.DEBUG)

    aizu_problems = read_codenet_problem_csv(codenet_problem_csv)

    password = getpass.getpass(prompt=f'Password for {args.aizu_username}: ')

    global session
    session = requests.Session()
    login(args.aizu_username, password)

    codenet_submission_dir = submission_dir / 'Codenet'
    for problem_dir in tqdm.tqdm(codenet_submission_dir.iterdir(), position=0):
        if problem_dir.name not in aizu_problems:
            continue

        problem_name, time_limit, memory_limit = aizu_problems[problem_dir.name]
        problem_id_successful, problem_id = find_problem_id(problem_name, time_limit, memory_limit)

        for original_file in tqdm.tqdm(itertools.chain(problem_dir.rglob('original.cpp'), problem_dir.rglob('original.c')), position=1, leave=False):
            prediction_dir = original_file.parent
            submit_predictions(prediction_dir, problem_id_successful, problem_id)


if __name__ == "__main__":
    main()