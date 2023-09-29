import argparse
import json
import subprocess
import tempfile
import tqdm
from concurrent.futures import TimeoutError
from pathlib import Path
from pebble import ProcessPool


def format_code(source_code: str, extension: str):
    with tempfile.TemporaryDirectory() as tmp_dir:
        tmp_file = Path(tmp_dir) / ('test' + extension)
        with tmp_file.open('w') as f:
            f.write(source_code)
        try:
            remove_comment_process = subprocess.Popen(
                ['gcc', '-fpreprocessed', '-dD', '-E', '-P', str(tmp_file)],
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE
            )
            formatter_process = subprocess.Popen(
                ['clang-format', '--style=llvm'],
                stdin=remove_comment_process.stdout,
                stdout=subprocess.PIPE
            )
            out, _ = formatter_process.communicate(timeout=15)
            return out.decode('utf-8')
        except Exception as e:
            return ''


def process_contest_dir(contest_dir: Path):
    for jsonl_file in contest_dir.glob('*.jsonl'):
        submission_pairs = []
        with jsonl_file.open() as f:
            for line in f:
                submission_pair = json.loads(line)
                before_source_code = submission_pair['before']['source_code']
                after_source_code = submission_pair['after']['source_code']
                programming_language = submission_pair['before']['programming_language']
                if before_source_code and after_source_code and programming_language:
                    before_formatted_source_code = None
                    after_formatted_source_code = None

                    if 'C++' in programming_language or programming_language == 'cpp':
                        before_formatted_source_code = format_code(before_source_code, '.cpp')
                        after_formatted_source_code = format_code(after_source_code, '.cpp')
                    elif programming_language == 'C' or programming_language.startswith('GNU C'):
                        before_formatted_source_code = format_code(before_source_code, '.c')
                        after_formatted_source_code = format_code(after_source_code, '.c')
                    if before_formatted_source_code and after_formatted_source_code:
                        submission_pair['before']['formatted_source_code'] = before_formatted_source_code
                        submission_pair['after']['formatted_source_code'] = after_formatted_source_code
                        submission_pairs.append(submission_pair)

        with jsonl_file.open('w') as f:
            for submission_pair in submission_pairs:
                json.dump(submission_pair, f)
                f.write('\n')
        submission_pairs.clear()


def main():
    parser = argparse.ArgumentParser(
        description='Format code and remove code comments.')
    parser.add_argument('-d', '--data_dir', action='store',
                        dest='data_dir', help='Path to the data.')
    parser.add_argument('--number_of_processes', type=int, default=4,
                        dest='number_of_processes',
                        help='Number of processes, default to 4.')
    parser.add_argument('--timeout', type=int, default=21600,
                        dest='timeout',
                        help='Timeout per process, default to 21600s (6h).')
    args = parser.parse_args()

    data_dir = Path(args.data_dir).resolve()
    contest_dirs = list(data_dir.iterdir())

    pbar = tqdm.tqdm(total=len(contest_dirs), desc='Iterating over all contests.')
    with ProcessPool(max_workers=args.number_of_processes) as pool:
        future = pool.map(process_contest_dir, contest_dirs, timeout=args.timeout)
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


if __name__ == '__main__':
    main()
