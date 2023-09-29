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

char expand(const std::string &str, int &n, int i = 0) {
  std::string res;
  for (; i < str.size(); ++i) {
    if (isdigit(str[i])) {
      int j = 1;
      while (isdigit(str[i + j])) ++j;
      int num = std::stoi(str.substr(i, j));
      i += j;
      if (str[i] == '(') {
        int k = cket(str, i + 1);
        int s = i + 1;
        int e = k - (i + 1);
        i = k;
        for (int l = 0; l < num; ++l) {
          char a = expand(str, n, s);
          if (a != '0')
            return a;
        }
      } else {
        for (int l = 0; l < num && n > 0; ++l, --n) {
          if (i >= str.size()) return '0';
          if (isdigit(str[i])) {
            i--;
            break;
          }
          if (n == 1) return str[i];
        }
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
    std::cout << expand(str, n) << std::endl;
  }
  return 0;
}