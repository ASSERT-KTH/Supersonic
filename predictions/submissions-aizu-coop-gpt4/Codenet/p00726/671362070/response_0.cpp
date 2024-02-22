#include <iostream>
#include <string>
#include <cstdlib>

int cket(const std::string &str, int i) {
  int n = 1;
  for (; i < str.size(); ++i) {
    if (str[i] == '(')
      n++;
    else if (str[i] == ')')
      n--;
    if (n == 0)
      break;
  }
  return i;
}

int n;
char expand(const std::string &str, int s, int e) {
  for (int i = s; i < s+e; ++i) {
    if (isdigit(str[i])) {
      int num = str[i] - '0';
      int j = i + 1;
      while (isdigit(str[j])) {
        num = num * 10 + (str[j] - '0');
        ++j;
      }
      i = j - 1;
      if (str[i + 1] == '(') {
        int k = cket(str, i + 2);
        for (int l = 0; l < num; ++l) {
          char a = expand(str, i + 2, k - (i + 2));
          if (a != '0')
            return a;
        }
        i = k;
      } else {
        for (int l = 0; l < num; ++l) {
          if (n == 0) {
            return str[i + 1];
          }
          n--;
        }
        i++;
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

int main() {
  while (true) {
    std::string str;
    std::cin >> str >> n;
    if (str == "0" && n == 0)
      break;
    std::cout << expand(str, 0, str.size()) << std::endl;
  }
  return 0;
}