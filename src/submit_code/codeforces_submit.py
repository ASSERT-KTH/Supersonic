"""
Configure cf tool to have one template for each extension first:

lang_to_extension = {
    'GNU C++17': '.gnucpp17',               # GNU G++17 7.3.0: cf id = 54
    'GNU C++14': '.gnucpp14',               # GNU G++14 6.4.0: cf id = 50
    'GNU C++11': '.gnucpp14',               # GNU G++14 6.4.0: cf id = 50
    'GNU C++': '.gnucpp17',                 # GNU G++17 7.3.0: cf id = 54
    'GNU C++17 (64)': '.gnucpp17',          # GNU G++17 7.3.0: cf id = 54
    'MS C++': '.mscpp2017',                 # Microsoft Visual C++ 2017: cf id = 59
    'GNU C++0x': '.gnucpp17',               # GNU G++17 7.3.0: cf id = 54
    'GNU C11': '.gnuc11',                   # GNU GCC C11 5.1.0: cf id = 43
    'MS C++ 2017': '.mscpp2017',            # Microsoft Visual C++ 2017: cf id = 59
    'GNU C': '.gnuc11',                     # GNU GCC C11 5.1.0: cf id = 43
    'GNU C++17 Diagnostics': '.gnucpp17',   # GNU G++17 7.3.0: cf id = 54
    'MS C++ 2010': '.mscpp2010',            # Microsoft Visual C++ 2010: cf id = 2
}
"""


import argparse
import json
import logging
import itertools
import random
import re
import subprocess
import string
import sys
import time
import tempfile
import tqdm
from pathlib import Path
from typing import Optional, Tuple


LONG_SLEEP_TIME = 300
SLEEP_TIME = 30
RANDOM_DELAY_MAX = 10
STATUS_RE = 'status: (.*)'
TIME_RE = 'time: (.*)'
MEMORY_RE = 'memory: (.*)'


def list_contest(contest_id: int) -> Tuple[bool, str]:
    command = ['cf', 'list', str(contest_id)]
    logging.info(f'Running command: {command}')
    response = subprocess.run(
        command,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE)
    if response.returncode == 0:
        response_str = response.stdout.decode()
        logging.info(f'Got response: {response_str}')
        return True, response_str
    
    logging.warning(f'Command failed: {command}')
    return False, ''

    
def find_problem_sub_id(contest_list: str, problem: str) -> str:
    logging.info(f'Finding sub problem id for: {problem}')
    for line in contest_list.splitlines():
        if problem in line:
            problem_id_column = line.split(problem)[0]
            sub_problem_id = problem_id_column.split('|')[1].lower().strip()
            logging.info(f'Sub problem id is: {sub_problem_id} ')
            return sub_problem_id
    logging.warning(f'Sub problem id for {problem} not found')
    return ''


def parse_submit_output(submit_output: str) -> Tuple[Optional[str], Optional[str], Optional[str]]:
    status = None
    cpu_time = None
    memory = None

    for line in submit_output.splitlines()[::-1]:
        line_strip = line.strip()
        
        status_search = re.search(STATUS_RE, line_strip)
        time_search = re.search(TIME_RE, line_strip)
        memory_search = re.search(MEMORY_RE, line_strip)

        if status_search and status is None:
            status = status_search.groups()[0]
        if time_search and cpu_time is None:
            cpu_time = time_search.groups()[0]
        if memory_search and memory is None:
            memory = memory_search.groups()[0]

    return status, cpu_time, memory


def submit(file_path: Path, contest_id: int, problem_sub_id: str) -> Tuple[bool, Optional[str]]:
    command = ['cf', 'submit', '-f', str(file_path), str(contest_id), problem_sub_id]
    logging.info(f'Running command: {command}')
    response = subprocess.run(
        ['cf', 'submit', '-f', str(file_path), str(contest_id), problem_sub_id],
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE)
    if response.returncode == 0:
        response_str = response.stdout.decode()
        logging.info(f'Got response: {response_str}')
        return True, response_str
    
    logging.warning(f'Command failed: {command}')
    return False, None


def add_random_comment(file_path: Path) -> Path:
    suffix = file_path.suffix
    tmp = tempfile.NamedTemporaryFile(mode='w', delete=False, suffix=suffix)
    original_file_content = file_path.open().read()
    random_string = ''.join(random.choices(string.ascii_letters, k=128))

    logging.info(f'Adding {random_string} as random comment to {str(file_path)}, stored in {tmp.name}')

    file_content_with_random_comment = original_file_content + '\n' + '// ' + random_string
    tmp.write(file_content_with_random_comment)
    tmp.close()
    return Path(tmp.name)


def is_valid_verdict(verdict):
    if not verdict['list_contest_success']:
        return False
    
    if 'Cannot find csrf' in verdict['contest_list']:
        return False
    
    if 'Cannot find csrf' in verdict['submit_output']:
        return False
    
    if 'Unexpected error' in verdict['submit_output']:
        return False
    
    if 'Submit failed' in verdict['submit_output']:
        return False
    
    return True


def submit_predictions(prediction_dir, contest_id):
    code_files = itertools.chain(prediction_dir.glob('*.gnu*'), prediction_dir.glob('*.ms*'))

    context_file = prediction_dir / 'context.json'
    with context_file.open() as f:
        context_data = json.load(f)
    problem = context_data['problem']
    contest_id = context_data['contest_id']

    problem_sub_id = None
    list_contest_success = False
    contest_list = ''

    for code_file in code_files:
        # time.sleep(SLEEP_TIME) 
        verdict_file = code_file.parent / (code_file.stem + '_verdict.json')

        if verdict_file.exists():
            verdict = json.load(verdict_file.open())
            if is_valid_verdict(verdict):
                continue

        if problem_sub_id is None:
            list_contest_success, contest_list = list_contest(contest_id)
            problem_sub_id = find_problem_sub_id(contest_list, problem)
            # Sleep after cf tool command
            time.sleep(SLEEP_TIME)
            time.sleep(random.randint(1, RANDOM_DELAY_MAX))

        verdict_json = {
            'list_contest_success': list_contest_success,
            'contest_list': contest_list,
            'problem_sub_id': problem_sub_id,
            'submit_success': False,
            'submit_output': '',
            'status': '',
            'cpu_time': '',
            'memory': '',
        }

        if not list_contest_success or not problem_sub_id:
            with verdict_file.open('w') as f:
                json.dump(verdict_json, f)
                f.write('\n')
            time.sleep(LONG_SLEEP_TIME)
            continue

        tmp_file = add_random_comment(code_file)

        time.sleep(SLEEP_TIME)
        time.sleep(random.randint(1, RANDOM_DELAY_MAX))

        submit_success, submit_output = submit(tmp_file, contest_id, problem_sub_id)
        verdict_json['submit_success'] = submit_success
        verdict_json['submit_output'] = submit_output
        tmp_file.unlink()

        if not submit_success:
            with verdict_file.open('w') as f:
                json.dump(verdict_json, f)
                f.write('\n')
            time.sleep(LONG_SLEEP_TIME)
            continue

        status, cpu_time, memory = parse_submit_output(submit_output)
        verdict_json['status'] = status
        verdict_json['cpu_time'] = cpu_time
        verdict_json['memory'] = memory

        with verdict_file.open('w') as f:
            json.dump(verdict_json, f)
            f.write('\n')

def main():
    parser = argparse.ArgumentParser(
        description='Submit to Codeforces.')
    parser.add_argument('--submission_dir', action='store', required=True,
                        dest='submission_dir', help='The directory to all submissions.')
    parser.add_argument('--logging_file', action='store', default='',
                        dest='logging_file', help='The logging file, else it will use stdout.')
    args = parser.parse_args()

    submission_dir = Path(args.submission_dir).resolve()

    if args.logging_file:
        logging.basicConfig(filename=args.logging_file, filemode='w', level=logging.DEBUG)
    else:
        logging.basicConfig(stream=sys.stdout, level=logging.DEBUG)

    run_cf_config = input('Have you run cf config? (Y/n)')
    if run_cf_config != 'Y':
        print('Please run cf config to 1) login 2) create template for c++ 3) create template for c')
        sys.exit(0)

    codeforces_dir = submission_dir / 'Codeforces'
    for context_json_file in tqdm.tqdm(codeforces_dir.rglob('context.json')):
        prediction_dir = context_json_file.parent
        contest_id = int(prediction_dir.parent.name)
        submit_predictions(prediction_dir, contest_id)


if __name__ == "__main__":
    main()