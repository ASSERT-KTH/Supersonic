import argparse
import json
import tqdm
from pathlib import Path
from typing import Sequence


def line_equal(src_line: str, tgt_line: str):
    return ''.join(src_line.split()) == ''.join(tgt_line.split())


def is_valid_hunk(hunk_lines: Sequence[str]):
    # Find the hunk starting and ending lines
    hunk_start = -1
    hunk_end = -1
    for index, line in enumerate(hunk_lines):
        if line.startswith(('-', '+')):
            hunk_start = index
            break

    for index, line in enumerate(hunk_lines[::-1]):
        if line.startswith(('-', '+')):
            hunk_end = len(hunk_lines) - index
            break

    # If we did not even find the start and end line, it is not valid
    if hunk_start == -1 or hunk_end == -1:
        return False
    
    # If all lines does not start with '-' or '+' in the hunk, it is not valid
    for line in hunk_lines[hunk_start: hunk_end]:
        if not line.startswith(('-', '+')):
            return False

    signs = [
        line[0]
        for line in hunk_lines[hunk_start: hunk_end]
    ]
    # If we only have a single sign, it is a pure-addition or deletion
    # patch, ie. valid.
    if len(set(signs)) == 1:
        return True
    
    # It can only be a replacement patch, therefore the last index of '-'
    # must be less than the first index of '+'
    if len(signs) - signs[::-1].index('-') - 1 > signs.index('+'):
        return False
    
    return True


def get_patch_hunks(predicted_patch: str, context_lines: int=1):
    predicted_patch_lines = predicted_patch.splitlines(True)
    hunks = []
    current_hunk = []
    is_new_hunk = False
    for index, line in enumerate(predicted_patch_lines):
        if line.startswith(('-', '+')):
            if not is_new_hunk:
                is_new_hunk = True

                for context_line in predicted_patch_lines[max(0, index-context_lines): index]:
                    current_hunk.append(context_line)
            current_hunk.append(line)
        else:
            if is_new_hunk:
                is_new_hunk = False
                for context_line in predicted_patch_lines[index: min(index+context_lines, len(predicted_patch_lines))]:
                    current_hunk.append(context_line)
                if is_valid_hunk(current_hunk):
                    hunks.append(''.join(current_hunk))
                    current_hunk = []
                else:
                    return []
                current_hunk.clear()
    
    if current_hunk:
        if is_valid_hunk(current_hunk):
            hunks.append(''.join(current_hunk))
            current_hunk = []
        else:
            return []
        
    return hunks


def apply_predicted_hunk(original_code: str, predicted_hunk: str):
    code_lines = original_code.splitlines(True)
    predicted_hunk_lines = predicted_hunk.splitlines(True)

    before_context = predicted_hunk_lines[0]

    insert_index = 0

    # Pure addtion patch at the start of file
    if before_context.startswith('+'):
        for predicted_line in predicted_hunk_lines:
            if predicted_line[0] == '+':
                code_lines.insert(insert_index, predicted_line[1:])
                insert_index += 1
        return ''.join(code_lines)
    # Pure deletion or replacement patch at the start of file
    elif before_context.startswith('-'):
        for predicted_line in predicted_hunk_lines:
            if predicted_line[0] == '-':
                if line_equal(predicted_line[1:], code_lines[0]):
                    del code_lines[0]
                else:
                    return ''
            elif predicted_line[0] == '+':
                code_lines.insert(insert_index, predicted_line[1:])
                insert_index += 1
        return ''.join(code_lines)
    # We have to find where before_context is
    else:
        for index, original_code_line in enumerate(code_lines):
            if line_equal(before_context[1:], original_code_line):
                insert_index = index+1
                break
        
        for predicted_line in predicted_hunk_lines[1:]:
            if predicted_line[0] == '-':
                if insert_index >= len(code_lines):
                    return ''

                if line_equal(predicted_line[1:], code_lines[insert_index]):
                    del code_lines[insert_index]
                else:
                    return ''
            elif predicted_line[0] == '+':
                code_lines.insert(insert_index, predicted_line[1:])
                insert_index += 1
        return ''.join(code_lines)



def apply_patch(original_code: str, predicted_patch: str):
    predicted_hunks = get_patch_hunks(predicted_patch)
    if not predicted_hunks:
        return ''
    
    patched_code = original_code
    
    for predicted_hunk in predicted_hunks:
        patched_code = apply_predicted_hunk(patched_code, predicted_hunk)
        if not patched_code:
            return ''
    return patched_code

 

def main():
    parser = argparse.ArgumentParser(
        description='Format the prediction.')
    parser.add_argument('--prediction_data_file', action="store", required=True,
                        dest='prediction_data_file', help="The prediction data jsonl file")
    parser.add_argument('--prediction_submission_file', action="store", required=True,
                        dest='prediction_submission_file', help="The prediction submission jsonl file")
    parser.add_argument('--full_output', default=False, action=argparse.BooleanOptionalAction)
    args = parser.parse_args()

    prediction_data_file = Path(args.prediction_data_file).resolve()
    prediction_submission_file = Path(args.prediction_submission_file).resolve()


    pd_file = prediction_data_file.open()
    ps_file = prediction_submission_file.open('w')

    beam_search_total = 0
    beam_search_malformed = 0
    top_pk_sampling_total = 0
    top_pk_sampling_malformed = 0
    for line in tqdm.tqdm(pd_file):
        data = json.loads(line)

        data['beam_search_submissions'] = []
        for beam_search_prediction in data['beam_search']:
            if args.full_output:
                patched_code = beam_search_prediction
            else:
                patched_code = apply_patch(data['input'], beam_search_prediction)

            beam_search_total += 1
            if not patched_code:
                beam_search_malformed += 1
            data['beam_search_submissions'].append(patched_code)

        data['top_pk_sampling_submissions'] = []
        for top_pk_sampling_prediction in data['top_pk_sampling']:
            if args.full_output:
                patched_code = beam_search_prediction
            else:
                patched_code = apply_patch(data['input'], top_pk_sampling_prediction)

            top_pk_sampling_total += 1
            if not patched_code:
                top_pk_sampling_malformed += 1
            data['top_pk_sampling_submissions'].append(patched_code)


        json.dump(data, ps_file)
        ps_file.write('\n')

    pd_file.close()
    ps_file.close()

    print(f'{beam_search_malformed*100/beam_search_total}% of beam search predictions are malformed.')
    print(f'{top_pk_sampling_malformed*100/top_pk_sampling_total}% of top k and k predictions are malformed.')


if __name__ == "__main__":
    main()