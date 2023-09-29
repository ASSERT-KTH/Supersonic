import argparse
import functools
import json
import tqdm
from concurrent.futures import TimeoutError
from pathlib import Path
from helper import init_process
from pebble import ProcessPool


def read_code(id: int, code_dir: Path):
    block_len = 2**10 - 2
    block_bytes = block_len * 4 + 8
    fileId = (id - 1) // 10**6 + 1
    id = (id - 1) % 10**6
    blockId = id // block_len
    blockPos = id % block_len
    bin_file = code_dir / (str(fileId) + '.bin')
    if not bin_file.exists():
        return ''
    with open(bin_file, 'rb') as f:
        f.seek(blockId * block_bytes)
        buf = f.read(block_bytes)
        offset = int.from_bytes(buf[:8], 'little')
        for i in range(blockPos):
            offset += int.from_bytes(buf[i * 4 + 8:i * 4 + 12], 'little')
        length = int.from_bytes(buf[blockPos * 4 + 8:blockPos * 4 + 12], 'little')
        f.seek(offset)
        return f.read(length).decode('utf-8')


def find_submission_code(contest_dir: Path, code_dir: Path):
    for author_json_file in contest_dir.glob('*.json'):
        with author_json_file.open() as f:
            user_submissions = json.load(f)
        for problem in user_submissions:
            for problem_submission in user_submissions[problem]:
                if problem_submission['source_code']:
                    continue
                problem_submission['source_code'] = read_code(
                    problem_submission['submission_id'], code_dir)
        with author_json_file.open('w') as f:
            json.dump(user_submissions, f)
            f.write('\n')


def main():
    parser = argparse.ArgumentParser(
        description='Get source code of submissions.')
    parser.add_argument('-d', '--data_dir', action='store',
                        dest='data_dir', help='Path to the submission data.')
    parser.add_argument('--code_dir', action='store',
                        dest='code_dir', help='Path to the submission code data.')
    parser.add_argument('--number_of_processes', type=int, default=4,
                        dest='number_of_processes',
                        help='Number of processes, default to 4.')
    parser.add_argument('--timeout', type=int, default=21600,
                        dest='timeout',
                        help='Timeout per process, default to 21600s (6h)')
    args = parser.parse_args()

    data_dir = Path(args.data_dir).resolve()
    code_dir = Path(args.code_dir).resolve()
    contest_dirs = list(data_dir.iterdir())

    pbar = tqdm.tqdm(total=len(contest_dirs), desc='Iterating over all contests.')
    with ProcessPool(max_workers=args.number_of_processes) as pool:
        future = pool.map(functools.partial(find_submission_code, code_dir=code_dir), contest_dirs, timeout=args.timeout)
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
