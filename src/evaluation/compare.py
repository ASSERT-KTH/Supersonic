import argparse
import json
from pathlib import Path

def main():
    parser = argparse.ArgumentParser(
        description='Compares the prediction file with the ground truth file.')
    parser.add_argument('--prediction_data_file', action='store',
                        dest='prediction_data_file', help='Path to the prediction file.')
    args = parser.parse_args()

    pd_file = Path(args.prediction_data_file).resolve()

    total = 0
    beam_search_correct = 0
    top_pk_sampling_correct = 0

    with pd_file.open() as f:
        for line in f:
            total += 1
            data = json.loads(line)

            ground_truth = data['output']
            for beam_search_prediction in data['beam_search']:
                if ''.join(beam_search_prediction.split()) == ''.join(ground_truth.split()):
                    beam_search_correct += 1
                    break

            for top_pk_sampling_prediction in data['top_pk_sampling']:
                if ''.join(top_pk_sampling_prediction.split()) == ''.join(ground_truth.split()):
                    top_pk_sampling_correct += 1
                    break

    print(f'Beam search correct ratio: {beam_search_correct*100/total} %')
    print(f'Top-k and top-k combined correct ratio: {top_pk_sampling_correct*100/total} %')


if __name__ == "__main__":
    main()
