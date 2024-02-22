#include <cstdlib>
#include <iostream>
#include <string>

int cket(const std::string &str, int i) {
  int n = 1;
  for (; i < str.size(); ++i) {
    if (str[i] == '(')
      n++;
    if (str[i] == ')')
      n--;
    if (n == 0)
      break;
  }
  return i;
}

int n;

char expand(const std::string &str, int s, int e) {
  std::string res;
  for (int i = s; i < s + e; ++i) {
    bool isDigit = isdigit(str[i]);
    if (isDigit) {
      int num = 0;
      while (isDigit) {
        num = num * 10 + (str[i] - '0');
        i++;
        isDigit = isdigit(str[i]);
      }
      int start, end;
      if (str[i] == '(') {
        int k = cket(str, i + 1);
        start = i + 1;
        end = k - start;
        i = k;
      } else {
        start = i;
        end = 1;
      }
      for (int l = 0; l < num; ++l) {
        char a = expand(str, start, end);
        if (a != '0')
          return a;
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
    std::cin >> str >> n;
    if (str == "0" && n == 0)
      break;
    std::cout << expand(str, 0, str.size()) << std::endl;
  }
  return 0;
}