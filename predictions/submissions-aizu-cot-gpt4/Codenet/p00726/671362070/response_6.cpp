#include <iostream>
#include <string>

int cket(std::string &str, int i) {
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

char expand(std::string &str, int s, int e) {
  for (int i = s; i < s + e; ++i) {
    if (isdigit(str[i])) {
      int num = 0;
      while (isdigit(str[i])) {
        num = num * 10 + (str[i] - '0');
        i++;
      }
      int j;
      if (str[i] == '(') {
        j = cket(str, i + 1);
        i = j;
      } else {
        j = 1;
      }
      for (int l = 0; l < num; ++l) {
        char a = expand(str, i - j + 1, j);
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