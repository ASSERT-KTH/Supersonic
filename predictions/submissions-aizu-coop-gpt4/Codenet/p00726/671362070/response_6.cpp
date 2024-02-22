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
    if (isdigit(str[i])) {
      int j = 1;
      while (isdigit(str[i + j]))
        j++;
      int num = std::atoi(str.substr(i, j).c_str());
      int se, ee;
      if (str[i + j] == '(') {
        int k;
        k = cket(str, i + j + 1);
        se = i + j + 1;
        ee = k - (i + j + 1);
        i = k;
      } else {
        se = i + j;
        ee = 1;
        i = i + j;
      }
      char a = '0';
      for (int l = 0; l < num; ++l) {
        a = expand(str, se, ee);
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