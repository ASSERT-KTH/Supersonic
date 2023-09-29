import argparse
import functools
import json
import tqdm
from concurrent.futures import TimeoutError
from pathlib import Path
from pebble import ProcessPool

def read_code(data_dir: Path, problem: str, programming_language: str, submission_id: int):
    source_code_dir = data_dir / problem / programming_language
    source_code_file = list(source_code_dir.glob(f's{submission_id}*'))
    if not source_code_file:
        return ''
    
    source_code_file = source_code_file[0]
    return source_code_file.open().read()


def find_submission_code(contest_dir: Path, codenet_dir: Path):
    data_dir = codenet_dir / 'data'
    for author_json_file in contest_dir.glob('*.json'):
        with author_json_file.open() as f:
            user_submissions = json.load(f)
        for problem in user_submissions:
            for problem_submission in user_submissions[problem]:
                if problem_submission['source_code']:
                    continue
                problem_submission['source_code'] = read_code(
                    data_dir, problem, problem_submission['programming_language'], problem_submission['submission_id'])
        with author_json_file.open('w') as f:
            json.dump(user_submissions, f)
            f.write('\n')


def main():
    parser = argparse.ArgumentParser(
        description='Get source code of submissions.')
    parser.add_argument('-d', '--data_dir', action='store',
                        dest='data_dir', help='Path to the submission data.')
    parser.add_argument('--codenet_dir', action='store',
                        dest='codenet_dir', help='Path to the extracted codenet dir.')
    parser.add_argument('--number_of_processes', type=int, default=4,
                        dest='number_of_processes',
                        help='Number of processes, default to 4.')
    parser.add_argument('--timeout', type=int, default=600,
                        dest='timeout',
                        help='Timeout per process, default to 600s (10m).')
    args = parser.parse_args()

    data_dir = Path(args.data_dir).resolve()
    codenet_dir = Path(args.codenet_dir).resolve()
    contest_dirs = list(data_dir.iterdir())

    pbar = tqdm.tqdm(total=len(contest_dirs), desc='Iterating over all contests.')
    with ProcessPool(max_workers=args.number_of_processes) as pool:
        future = pool.map(functools.partial(find_submission_code, codenet_dir=codenet_dir), contest_dirs, timeout=args.timeout)
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
