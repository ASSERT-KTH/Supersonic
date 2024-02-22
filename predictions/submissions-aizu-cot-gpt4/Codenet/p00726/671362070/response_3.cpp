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
  for (int i = s; i < s + e; ++i) {
    if (isdigit(str[i])) {
      int num = 0;
      while (isdigit(str[i])) {
        num = num * 10 + str[i] - '0';
        ++i;
      }
      if (str[i] == '(') {
        int k = cket(str, i + 1);
        i = expand(str, i + 1, k - i - 1);
        if (i != '0') return i;
      } else {
        for (int l = 0; l < num; ++l) {
          char a = expand(str, i, 1);
          if (a != '0') return a;
        }
        ++i;
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
    if (str == "0" && n == 0) break;
    std::cout << expand(str, 0, str.size()) << std::endl;
  }
  return 0;
}