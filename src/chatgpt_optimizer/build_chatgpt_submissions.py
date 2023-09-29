#!/usr/bin/env python
# -*- encoding: utf-8 -*-


'''
@Author  :   Sen Fang
@Email   :   senf@kth.se
@Ide     :   vscode & conda
@File    :   build_chatgpt_submissions.py
@Time    :   2023/03/24 19:59:08
'''

"""In this file, we build the prompt file for each original c or cpp file in test data."""

import os
import argparse
import json
import csv
from tqdm import tqdm


def load_paths(dir_path: str=""):
    """Load paths of all original c or cpp file from test data. For each problem, there may exist 
    multiple original c or cpp files becasue different authors may use different methods to solve the problem."""
    paths = []
    for root, dirs, files in tqdm(os.walk(dir_path)):
        for file in (files):
            if file.startswith("original") or file.startswith("improved") or file.endswith(".json"):
                path = os.path.join(root, file)
                if "Codenet" in path:
                    paths.append(path)
    return paths


def load_aizu_problem_id(dir_path: str=""):
    """Load paths of all original c or cpp file from test data. For each problem, there may exist 
    multiple original c or cpp files becasue different authors may use different methods to solve the problem."""
    ids = []
    with open(dir_path, "r") as f:
        reader = csv.reader(f)
        for idx, row in enumerate(reader):
            if idx == 0:
                continue
            if row[2] == "AIZU":
                ids.append(row[0])
    return ids


def build_prompt(paths: list, problem_ids: list, prompt: str="", prompt_level: str=""):
    """Create prompts for original c or cpp files and save them into a submission directory in the current directory."""

    submissions_dir = os.path.join(os.getcwd(), "submissions"+"-"+prompt_level)
    if not os.path.exists(submissions_dir):
        os.mkdir(submissions_dir)

    for idx, path in tqdm(enumerate(paths)):

        # breakpoint()
        problem_id = path.split("/")[-3]
        if problem_id not in problem_ids:
            continue
        temp_path = "/".join(path.split("/")[-4:-1])
        new_path = os.path.join(submissions_dir, temp_path)
        if not os.path.exists(new_path):
            os.makedirs(new_path)

        with open(path, "r") as f:
            content = f.read()

        if path.startswith("original"):
            
            # Copy c or cpp file to new path
            with open(new_path+"/"+path.split("/")[-1], "w") as f:
                f.write(content)

            # Save prompt_dict to new path
            prompt_dict = {"prompt": prompt, "content": content}
            with open(new_path+"/prompt.json", "w") as f:
                json.dump(prompt_dict, f, indent=4)
        elif path.startswith("improved"):
            # Copy c or cpp file to new path
            with open(new_path+"/"+path.split("/")[-1], "w") as f:
                f.write(content)
        else:
            # rewrite json file to target path
            with open(new_path+"/"+path.split("/")[-1], "w") as f:
                f.write(content)


def main():

    parser = argparse.ArgumentParser(
        description='Build prompt file for each original c or cpp file in test data.')
    parser.add_argument('--test_data_dir', '-t', action='store',
                        dest='test_data_dir', help='Path to the submissions directory in the project direcotry.')
    parser.add_argument('--codenet_problem_csv', '-c', action='store', required=True,
                        dest='codenet_problem_csv', help='The codenet problem_list.csv file.')
    parser.add_argument('--prompt_level', '-pl', action='store', default='easy', choices=["easy", "specific", "advanced"],
                        dest='prompt_level', help='There are different levels of prompts.')
    args = parser.parse_args()

    prompt_dict = {"easy": "Please optimize the following code and return the markdown format optimized code.\n",
                   "advanced": "I want you to act as an experienced C and C++ developer and your task is to optimize my written C or C++ programs. I want you to optimize my program from the running time and memory usage. I will type my C or C++ program and you will optimize the program and return the optimized program. I want you to only reply with the fixed program inside one unique code block, and nothing else. Do not write explanations unless I instruct you to do so.\n"}

    test_data_dir = args.test_data_dir
    prompt_level = args.prompt_level
    prompt = prompt_dict[prompt_level]

    paths = load_paths(test_data_dir)
    aizu_problem_ids = load_aizu_problem_id(args.codenet_problem_csv)
    build_prompt(paths, aizu_problem_ids, prompt, prompt_level)


if __name__ == "__main__":
    main()
