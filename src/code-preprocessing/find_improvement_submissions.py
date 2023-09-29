import argparse
import functools
import json
import tqdm
from concurrent.futures import TimeoutError
from pathlib import Path
from pebble import ProcessPool


def check_submissions(contest_dir: Path, output_dir: Path):
    output_contest_dir = output_dir / contest_dir.name
    output_contest_dir.mkdir(parents=True, exist_ok=True)
    submission_pairs = []
    submission_pairs_count = 0
    for author_json_file in contest_dir.glob('*.json'):
        with author_json_file.open() as f:
            user_submissions = json.load(f)
        for problem in user_submissions:
            problem_submissions = user_submissions[problem]
            problem_submissions = [submission for submission in problem_submissions if submission['source_code']]
            problem_submissions.sort(key=lambda x: x['creation_time_seconds'])
            for index in range(1, len(problem_submissions)):
                not_cpp = 'C++' not in problem_submissions[index - 1]['programming_language']
                not_c = not problem_submissions[index - 1]['programming_language'].startswith('C') 
                not_gnu_c = not problem_submissions[index - 1]['programming_language'].startswith('GNU C')
                if not_cpp and not_c and not_gnu_c:
                    continue

                if problem_submissions[index - 1]['programming_language'] == problem_submissions[index]['programming_language']:
                    t0_time = problem_submissions[index-1]['time_consumed_millis']
                    t1_time = problem_submissions[index]['time_consumed_millis']
                    t0_memory = problem_submissions[index-1]['memory_consumed_bytes']
                    t1_memory = problem_submissions[index]['memory_consumed_bytes']

                    # Either time is strictly improved and memory is not impacted, or
                    # Either time is not impacted and memory is strictly improved.
                    if ((t1_time < t0_time and t1_memory <= t0_memory) or (t1_time <= t0_time and t1_memory < t0_memory)):
                        submission_pairs.append({
                            'before': problem_submissions[index - 1],
                            'after': problem_submissions[index],
                        })
                        if len(submission_pairs) == 1000:
                            write_submission_pairs(submission_pairs, output_contest_dir, submission_pairs_count)
                            submission_pairs.clear()
                            submission_pairs_count += 1
    if submission_pairs:
        write_submission_pairs(submission_pairs, output_contest_dir, submission_pairs_count)


def write_submission_pairs(submission_pairs: list, output_contest_dir: Path, count: int):
    if submission_pairs:
        output_file = output_contest_dir / (str(count) + '.jsonl')
        with open(output_file, 'w') as f:
            for submission_pair in submission_pairs:
                json.dump(submission_pair, f)
                f.write('\n')


def main():
    parser = argparse.ArgumentParser(
        description='Find submissions with improvement from the same author.')
    parser.add_argument('-d', '--data_dir', action='store',
                        dest='data_dir', help='Path to the submission data.')
    parser.add_argument('-o', '--output_dir', action='store',
                        dest='output_dir', help='Path to store the output.')
    parser.add_argument('--number_of_processes', type=int, default=4,
                        dest='number_of_processes',
                        help='Number of processes, default to 4.')
    parser.add_argument('--timeout', type=int, default=600,
                        dest='timeout',
                        help='Timeout per process, default to 600s (10m).')
    args = parser.parse_args()

    data_dir = Path(args.data_dir).resolve()
    output_dir = Path(args.output_dir).resolve()
    output_dir.mkdir(parents=True, exist_ok=True)
    contest_dirs = list(data_dir.iterdir())

    pbar = tqdm.tqdm(total=len(contest_dirs), desc='Iterating over all contests.')
    with ProcessPool(max_workers=args.number_of_processes) as pool:
        future = pool.map(functools.partial(check_submissions, output_dir=output_dir), contest_dirs, timeout=args.timeout)
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
