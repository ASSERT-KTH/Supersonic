#include <cstdlib>
#include <iostream>
#include <string>

int cket(const std::string &str, int i) {
  int n = 1;
  for (; i < str.length(); ++i) {
    if (str.at(i) == '(')
      ++n;
    if (str.at(i) == ')')
      --n;
    if (n == 0)
      break;
  }
  return i;
}

int n;
char expand(const std::string &str, int s, int e) {
  for (int i = s; i < s + e; ++i) {
    if (isdigit(str.at(i))) {
      int j = 1;
      while (isdigit(str.at(i + j)))
        ++j;
      int num = std::stoi(str.substr(i, j));
      int k;
      if (str.at(i + j) == '(') {
        k = cket(str, i + j + 1);
        i = k;
      } else {
        j = 1;
        i += j;
      }
      for (int l = 0; l < num; ++l) {
        char a = expand(str, i + j, k - (i + j + 1));
        if (a != '0')
          return a;
      }
    } else {
      if (n == 0) {
        return str.at(i);
      }
      --n;
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
    std::cout << expand(str, 0, str.length()) << std::endl;
  }
  return 0;
}