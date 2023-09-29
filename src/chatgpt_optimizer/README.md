This folder contains the source code of using ChatGPT to generate optimized code for orginal c or cpp code in test dataset.

- 🌱 The current code can only sample once for each prompt, so we plan to support multiple sampling.
- 🌱 In our prompt, although we write a natural language limitation to let ChatGPT only generate optimized code, it also may generate extra natural language text. So we plan to write a python script to automatically extract code from ChatGPT's answer.
- 🌱 We design different prompts but we can't easily compare them by mini-batch samples. So we plan to add this function.


`Note`: Currently you can only run this code when finishing the evaluation of our approach because it exists some dependency. <br />
`Note`: To use ChatGPT API, you need to have an OpenAI account and generate an API key, then set it to the environment variable with name ``OPENAI_API_KEY``.


### Requirement

- openai
- tiktoken



### How To Use

#### Step 1
Use the following command to generate prompt.txt for each original c or cpp code in test dataset. We design three different level prompt for each code, i.e., easy, specific, and advanced, and you can choose it by ``--prompt_level``. You can also generaet prompt for you own dataset by giving ``--test_data_dir`` the path of your dataset.

```bash
python3 build_chatgpt_submissions.py --test_data_dir ../../submissions --prompt_level easy
```

#### Step 2
Use the following command to request ChatGPT to optimized code with different level prompt.

```bash
python run_chatgpt_optimizeer.py --prompt_level easy
```
