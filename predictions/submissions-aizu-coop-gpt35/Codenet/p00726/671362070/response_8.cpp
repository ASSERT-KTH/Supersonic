#include <cstdlib>
#include <iostream>
#include <string>
#include <stack>
#include <cctype>

int findClosingParenthesis(const std::string& str, int i) {
  std::stack<int> openingParentheses;
  openingParentheses.push(i);

  for (i++; i < str.size(); ++i) {
    if (str[i] == '(') {
      openingParentheses.push(i);
    }
    else if (str[i] == ')') {
      openingParentheses.pop();
      if (openingParentheses.empty()) {
        break;
      }
    }
  }

  return i;
}

char expand(const std::string& str) {
  if (str.empty()) {
    return '0';
  }

  int i = 0;
  while (std::isdigit(str[i])) {
    i++;
  }

  int num = std::stoi(str.substr(0, i));
  int s, e;

  if (str[i] == '(') {
    int k = findClosingParenthesis(str, i + 1);
    s = i + 1;
    e = k - (i + 1);
    i = k;
  }
  else {
    s = i;
    e = 1;
  }

  for (int l = 0; l < num; ++l) {
    char a = expand(str.substr(s, e));
    if (a != '0') {
      return a;
    }
  }

  return '0';
}

int main(void) {
  while (true) {
    std::string str;
    int n;
    std::cin >> str >> n;

    if (str == "0" && n == 0) {
      break;
    }

    std::cout << expand(str) << std::endl;
  }

  return 0;
}