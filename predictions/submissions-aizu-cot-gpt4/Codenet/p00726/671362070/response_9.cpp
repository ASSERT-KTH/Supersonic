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
  for (int i = s; i < e; ++i) {
    if (isdigit(str[i])) {
      int num = str[i] - '0';
      int j = i + 1;
      if (str[j] == '(') {
        int k = cket(str, j + 1);
        i = k;
        for (int l = 0; l < num; ++l) {
          char a = expand(str, j + 1, k);
          if (a != '0')
            return a;
        }
      } else {
        for (int l = 0; l < num; ++l) {
          char a = expand(str, j, j + 1);
          if (a != '0')
            return a;
        }
        i = j;
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