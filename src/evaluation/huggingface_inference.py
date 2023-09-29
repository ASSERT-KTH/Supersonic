import argparse
from pathlib import Path


def prediction_script(
    model_path: str, tokenizer_path: str, test_data_file: str, prediction_data_file: str,
    is_t5_model: bool = False, max_length: int=512):
    if is_t5_model:
        model_type = 'T5ForConditionalGeneration'
        task_prefix = 'refine: '
    else:
        model_type = 'EncoderDecoderModel'
        task_prefix = ''
    
    return f"""\
import json
import torch
from dataclasses import dataclass
from transformers import AutoTokenizer, EncoderDecoderModel, T5ForConditionalGeneration
from typing import Optional

@dataclass
class GenerateSettings:
    name: str
    num_beams: Optional[int] = 1
    do_sample: Optional[bool] = False
    top_k: Optional[int] = None
    top_p: Optional[float] = None
    temperature: Optional[float] = None
    num_return_sequences: int=10

beam_search = GenerateSettings(
    name='beam_search',
    num_beams=50,
)

top_pk_sampling = GenerateSettings(
    name='top_pk_sampling',
    do_sample=True,
    top_k=50,
    top_p=0.8,
    temperature=0.7,
)

all_generate_settings = [beam_search, top_pk_sampling]

device = "cuda:0" if torch.cuda.is_available() else "cpu"

model = {model_type}.from_pretrained('{model_path}').to(device)
tokenizer = AutoTokenizer.from_pretrained('{tokenizer_path}', use_fast=True)

td_file = open('{test_data_file}')
pd_file = open('{prediction_data_file}', 'w')

for line in td_file:
    data = json.loads(line)
    input_data = data['input']

    inputs = tokenizer(
        '{task_prefix}' + input_data, padding='max_length', truncation=True, max_length={max_length}, return_tensors='pt')
    input_ids = inputs.input_ids.to(device)
    attention_mask = inputs.attention_mask.to(device)
    for generate_setting in all_generate_settings:
        output_ids = model.generate(
            input_ids,
            attention_mask=attention_mask,
            max_length={max_length},
            num_beams=generate_setting.num_beams,
            do_sample=generate_setting.do_sample,
            top_k=generate_setting.top_k,
            top_p=generate_setting.top_p,
            temperature=generate_setting.temperature,
            num_return_sequences=generate_setting.num_return_sequences)
        predicted_texts = tokenizer.batch_decode(output_ids, skip_special_tokens=True, clean_up_tokenization_spaces=False)

        data[generate_setting.name] = []
        for predicted_text in predicted_texts:
            data[generate_setting.name].append(predicted_text)
    
    json.dump(data, pd_file)
    pd_file.write('\\n')

td_file.close()
pd_file.close()

"""

def default_c3se_prediction_script(huggingface_script, gpu_type='A100',
                            number_of_gpus='1', time='48:00:00'):
    log_file_path = Path(huggingface_script).parent / 'prediction_log.txt'
    return f'''\
#!/bin/bash

# Project to run under
#SBATCH -A SNIC2022-5-596 -p alvis
# Name of the job (makes easier to find in the status lists)
#SBATCH -J repair
# Use GPU
#SBATCH --gpus-per-node={gpu_type}:{number_of_gpus}
# the job can use up to x minutes to run
#SBATCH --time={time}

# run the program
python3 {huggingface_script} 2>&1 | tee -a {log_file_path}

'''


def main():
    parser = argparse.ArgumentParser(
        description='Generate predictions from the huggingface models.')
    parser.add_argument('--test_data_file', action="store", required=True,
                        dest='test_data_file', help="The test data jsonl file.")
    parser.add_argument('--sweep_root_path', action="store", required=True,
                        dest='sweep_root_path', help="The dir containing all sweeps.")
    parser.add_argument('--is_t5_model', action="store_true",
                        dest='is_t5_model', help="If the model is a codet5 model.")
    parser.set_defaults(is_t5_model=False)
    args = parser.parse_args()

    sweep_root_path = Path(args.sweep_root_path).resolve()
    test_data_file = Path(args.test_data_file).resolve()

    for sweep_path in sweep_root_path.glob('*_parameter_sweep'):
        model_path = sweep_path / 'model'
        tokenizer_path = sweep_path / 'tokenizer'
        prediction_data_file = sweep_path / (test_data_file.stem + '.predictions.jsonl')
        prediction_job_file = sweep_path / 'prediction_job.sh'

        prediction_code = prediction_script(
            model_path=model_path,
            tokenizer_path=tokenizer_path,
            test_data_file=str(test_data_file),
            prediction_data_file=str(prediction_data_file),
            is_t5_model=args.is_t5_model)
        prediction_code_file = sweep_path / 'huggingface_predict.py'
        with prediction_code_file.open('w') as f:
            f.write(prediction_code)

        prediction_job_script = default_c3se_prediction_script(str(prediction_code_file))
        with prediction_job_file.open('w') as f:
            f.write(prediction_job_script)



if __name__ == "__main__":
    main()