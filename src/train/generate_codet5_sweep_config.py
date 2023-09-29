import argparse
from pathlib import Path


def hugging_face_script(train_data_file: str, valid_data_file: str, model_dir: str, log_dir: str,
                        learning_rate: float, tokenizer_dir: str, batch_size: int=4,
                        max_length: int=512, eval_steps: int=2000, max_steps: int=200000, gradient_accumulation_steps: int=4):
    return f"""\
import datasets
import evaluate
import logging
import functools
import sys
import transformers
from transformers import AutoTokenizer, EarlyStoppingCallback, Seq2SeqTrainer, Seq2SeqTrainingArguments, T5ForConditionalGeneration


datasets.logging.set_verbosity_info()
transformers.logging.set_verbosity_info()
datasets.disable_progress_bar()
transformers.utils.logging.disable_progress_bar()


def process_data_to_model_inputs(batch, tokenizer, encoder_max_length, decoder_max_length):
  # Tokenize the input and target data
  task_prefix = 'refine: '
  inputs = tokenizer(
    [task_prefix + i for i in batch['input']],
    padding='max_length', truncation=True, max_length=encoder_max_length)
  outputs = tokenizer(batch['output'], padding='max_length', truncation=True, max_length=decoder_max_length)

  batch['input_ids'] = inputs.input_ids
  batch['attention_mask'] = inputs.attention_mask
  batch['decoder_attention_mask'] = outputs.attention_mask
  batch['labels'] = outputs.input_ids.copy()

  batch['labels'] = [[-100 if token == tokenizer.pad_token_id else token for token in labels] for labels in batch['labels']]

  return batch


def compute_metrics(eval_preds, tokenizer):
    metric = evaluate.load('exact_match')
    preds, labels = eval_preds
    # In case the model returns more than the prediction logits
    if isinstance(preds, tuple):
        preds = preds[0]

    decoded_preds = tokenizer.batch_decode(preds, skip_special_tokens=True, clean_up_tokenization_spaces=False)

    # Replace -100s in the labels as we can't decode them
    labels[labels == -100] = tokenizer.pad_token_id
    decoded_labels = tokenizer.batch_decode(labels, skip_special_tokens=True, clean_up_tokenization_spaces=False)

    # Some simple post-processing
    decoded_preds = [pred.strip() for pred in decoded_preds]
    decoded_labels = [label.strip() for label in decoded_labels]

    result = metric.compute(predictions=decoded_preds, references=decoded_labels)
    return {{'exact_match': result['exact_match']}}


def main():
    logging.basicConfig(
        format="%(asctime)s - %(levelname)s - %(name)s - %(message)s",
        datefmt="%m/%d/%Y %H:%M:%S",
        handlers=[logging.StreamHandler(sys.stdout)],
    )

    model = T5ForConditionalGeneration.from_pretrained('Salesforce/codet5-large')
    tokenizer = AutoTokenizer.from_pretrained('Salesforce/codet5-large', use_fast=True)
    
    model.config.early_stopping = True
    model.config.num_beams = 10

    process_data_to_model_inputs_fn = functools.partial(
        process_data_to_model_inputs, tokenizer=tokenizer,
        encoder_max_length={max_length}, decoder_max_length={max_length})

    train_dataset = datasets.load_dataset('json', data_files='{train_data_file}', split='train')
    valid_dataset = datasets.load_dataset('json', data_files='{valid_data_file}', split='train')

    train_dataset = train_dataset.map(
        process_data_to_model_inputs_fn,
        batched=True,
        batch_size={batch_size},
        remove_columns=['input', 'output']
    )
    train_dataset.set_format(
        type='torch', columns=['input_ids', 'attention_mask', 'decoder_attention_mask', 'labels'])

    valid_dataset = valid_dataset.map(
        process_data_to_model_inputs_fn,
        batched=True,
        batch_size={batch_size},
        remove_columns=['input', 'output']
    )
    valid_dataset.set_format(
        type='torch', columns=['input_ids', 'attention_mask', 'decoder_attention_mask', 'labels'])

    training_args = Seq2SeqTrainingArguments(
        output_dir='{model_dir}',
        logging_dir='{log_dir}',
        per_device_train_batch_size={batch_size},
        per_device_eval_batch_size={batch_size},
        predict_with_generate=True,
        evaluation_strategy='steps',
        do_train=True,
        do_eval=True,
        learning_rate={learning_rate},
        logging_steps={eval_steps},  
        eval_steps={eval_steps},
        save_steps={eval_steps}, 
        warmup_steps=2048,  
        max_steps={max_steps},
        overwrite_output_dir=True,
        label_smoothing_factor=0,
        save_total_limit=5,
        fp16=True, 
        gradient_accumulation_steps={gradient_accumulation_steps},
        load_best_model_at_end=True,
    )

    compute_metrics_fn = functools.partial(compute_metrics, tokenizer=tokenizer)
    # instantiate trainer
    trainer = Seq2SeqTrainer(
        model=model,
        args=training_args,
        compute_metrics=compute_metrics_fn,
        train_dataset=train_dataset,
        eval_dataset=valid_dataset,
        callbacks=[EarlyStoppingCallback(early_stopping_patience=3)],
    )

    # Fine-tune the model, training and evaluating on the train dataset
    trainer.train()
    # Save the encoder-decoder model just trained
    trainer.save_model('{model_dir}')
    tokenizer.save_pretrained('{tokenizer_dir}')


if __name__ == "__main__":
    main()
"""

def default_c3se_job_script(huggingface_script, gpu_type='A100',
                            number_of_gpus='2', time='144:00:00'):
    log_file_path = Path(huggingface_script).parent / 'log.txt'
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
        description='Automatic creating the Huggingface sweep.')
    parser.add_argument('--train_data_file', action="store", required=True,
                        dest='train_data_file', help="The training data jsonl file")
    parser.add_argument('--valid_data_file', action="store", required=True,
                        dest='valid_data_file', help="The validation data jsonl file")
    parser.add_argument('--sweep_root_path', action="store", required=True,
                        dest='sweep_root_path',
                        help="Path to the root directory of all configs sweeps")
    args = parser.parse_args()

    sweep_root_path = Path(args.sweep_root_path).resolve()

    learning_rate_sweep = [2e-4, 1e-4, 5e-5]
    for index, learning_rate in enumerate(learning_rate_sweep):

        sweep_path = sweep_root_path / (str(index) + '_parameter_sweep')
        sweep_path.mkdir(parents=True, exist_ok=True)
        model_dir = sweep_path / 'model'
        log_dir = sweep_path / 'log'
        tokenizer_dir = sweep_path / 'tokenizer'

        training_script = hugging_face_script(
            args.train_data_file, args.valid_data_file, str(model_dir),
            str(log_dir), learning_rate, str(tokenizer_dir))
        training_script_path = sweep_path / 'huggingface_train.py'
        with training_script_path.open('w') as f:
            f.write(training_script)

        job_script = default_c3se_job_script(str(training_script_path))
        job_script_path = sweep_path / 'job.sh'
        with job_script_path.open('w') as f:
            f.write(job_script)


if __name__ == "__main__":
    main()
