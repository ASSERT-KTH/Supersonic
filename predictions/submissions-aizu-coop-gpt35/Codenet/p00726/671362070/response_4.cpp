#include <iostream>
#include <string>

int findClosingParenthesis(const std::string& str, int startIndex) {
  int count = 1;
  for (int i = startIndex + 1; i < str.size(); ++i) {
    if (str[i] == '(') {
      count++;
    } else if (str[i] == ')') {
      count--;
      if (count == 0) {
        return i;
      }
    }
  }
  return -1; // Invalid input, closing parenthesis not found
}

char expand(const std::string& str, int& index) {
  std::string result;
  while (index < str.size()) {
    if (str[index] >= '0' && str[index] <= '9') {
      int num = str[index] - '0';
      int j = index + 1;
      while (j < str.size() && str[j] >= '0' && str[j] <= '9') {
        num = num * 10 + (str[j] - '0');
        j++;
      }
      index = j;
      
      if (str[j] == '(') {
        int closingIndex = findClosingParenthesis(str, j);
        if (closingIndex != -1) {
          std::string subStr = str.substr(j + 1, closingIndex - j - 1);
          for (int l = 0; l < num; ++l) {
            char a = expand(subStr, index);
            if (a != '0') {
              return a;
            }
          }
          continue;
        }
      }
      
      for (int l = 0; l < num; ++l) {
        if (index < str.size()) {
          char a = str[index];
          index++;
          if (a != '0') {
            return a;
          }
        }
      }
    } else {
      if (index < str.size()) {
        char a = str[index];
        index++;
        if (a != '0') {
          return a;
        }
      }
    }
  }
  return '0';
}

int main() {
  while (true) {
    std::string str;
    std::cin >> str;
    if (str == "0") {
      break;
    }
    int n;
    std::cin >> n;
    std::cout << expand(str, n) << std::endl;
  }
  return 0;
}