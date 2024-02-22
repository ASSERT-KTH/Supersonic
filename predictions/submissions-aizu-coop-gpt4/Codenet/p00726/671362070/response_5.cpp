#include <cstdlib>
#include <iostream>
#include <string>
#include <stack>

int str_to_int(const std::string &str, int start, int length) {
  int result = 0;
  for (int i = start; i < start + length; ++i) {
    result = result * 10 + (str[i] - '0');
  }
  return result;
}

char expand(const std::string &str, int &n, std::stack<int> &brackets) {
  for (int i = 0; i < str.size(); ++i) {
    if (isdigit(str[i])) {
      int j = 1;
      while (isdigit(str[i + j]))
        j++;
      int num = str_to_int(str, i, j);

      if (str[i + j] == '(') {
        brackets.push(i + j);
        i += j;
      } else {
        for (int l = 0; l < num; ++l) {
          if (n == 0) {
            return str[i + j];
          }
          n--;
        }
        i += j;
      }
    } else if (str[i] == ')') {
      if (!brackets.empty()) {
        int start = brackets.top();
        brackets.pop();
        i = start;
      }
    } else {
      if (n == 0) {
        return str[i];
      }
      n--;
    }
  }
  return '0';
}

int main(void) {
  while (true) {
    std::string str;
    int n;
    std::cin >> str >> n;
    if (str == "0" && n == 0)
      break;
    std::stack<int> brackets;
    std::cout << expand(str, n, brackets) << std::endl;
  }
  return 0;
}