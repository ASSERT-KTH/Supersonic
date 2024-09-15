# Supersonic: Learning to Generate Source Code Optimisations in C/C++

This is the GitHub repository for [***Supersonic: Learning to Generate Source Code Optimisations in C/C++***](https://arxiv.org/abs/2309.14846) (IEEE TSE, 2024).

```bibtex
@article{supersonic,
 title = {Supersonic: Learning to Generate Source Code Optimizations in C/C++},
 journal = {IEEE Transactions on Software Engineering},
 year = {2024},
 doi = {10.1109/TSE.2024.3423769},
 author = {Zimin Chen and Sen Fang and Martin Monperrus},
 url = {http://arxiv.org/pdf/2309.14846},
}
```

The model is uploaded to [Zenodo](https://zenodo.org/records/10889066), and the filtered dataset used to train Supersonic is upladed to [Zenodo](https://zenodo.org/record/8386875). The unfiltered dataset is also uploaded to [Zenodo](https://zenodo.org/record/8388731). 

## Predictions

All Supersonic, GPT-3.5-Turbo and GPT-4 predictions are located in `predictions/`.

## Files

All executable file uses `argparse`, meaning that you can run `python foo.py -h` to see all command line arguments

### src/codeforces-crawler

* `src/codeforces-crawler/crawler.py`: Uses Codeforces API to crawl submission information.
* `src/codeforces-crawler/find_submission_code.py`: Uses dataset from this [blog](https://codeforces.com/blog/entry/94755), and finds the actual code for each Codeforces submission.

### src/codenet-crawler

* `src/codenet-crawler/parse_subnet_csv.py`: First download the Codenet dataset from their [GitHub page](https://github.com/IBM/Project_CodeNet#download-the-dataset). Then run this file to find all submission information.
* `src/codenet-crawler/find_submission_code.py`: Finds the actual code for each Codenet submission.

### src/code-preprocessing

* `src/code-preprocessing/find_improvement_submissions.py`: Using the Codeforces and Codenet submissions, we find submission where either the time or memory improved.
* `src/code-preprocessing/format_code.py`: Uses `gcc` to remove source code comment and `clang-format` to format all submissions.

### src/train

* `src/train/generate_huggingface_dataset.py`: Generates dataset to be used for huggingface models. There are several filters defined in this file.
* `src/train/generate_bert2bert_sweep_config.py`: Generates bert2bert training files.
* `src/train/generate_codet5_sweep_config.py`: Generates codet5 training files.

### src/evaluation

* `src/evaluation/huggingface_inference.py`: Generate predictions on the test dataset.
* `src/evaluation/compare.py`: Compute the test accuracy.
* `src/evaluation/generate_predicted_submissions.py`: Parse the model output and generate the acutual predicted program. We need this step since the model predicts a diff.
* `src/evaluation/output_submission_dir.py`: Generate a directory containing all predicted submissions.

### src/submit_code

* `src/submit_code/aizu_submit.py`: Upload generated solutions to AIZU.
* `src/submit_code/atcoder_submit.py`:  Upload generated solutions to AtCoder.
* `src/submit_code/codeforces_submit.py`: Upload generated solutions to Codeforces.

### src/notebooks

* `src/notebooks/Statistics.ipynb`: The statistics notebook.
* `src/notebooks/figures.ipynb`: Notebook to generate figures used in the paper.
