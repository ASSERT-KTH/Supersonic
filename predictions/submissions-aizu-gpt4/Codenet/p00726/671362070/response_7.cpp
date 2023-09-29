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

char expand(const std::string &str, int &i) {
  char res = '0';
  for (; i < str.size(); ++i) {
    if (isdigit(str[i])) {
      int num = 0;
      while (isdigit(str[i]))
        num = num * 10 + (str[i++] - '0');
      int s, e;
      if (str[i] == '(') {
        int k = cket(str, i + 1);
        s = i + 1;
        e = k;
        i = k;
      } else {
        s = i;
        e = i + 1;
      }
      for (int l = 0; l < num; ++l) {
        char a = expand(str, s);
        if (a != '0') {
          res = a;
          break;
        }
      }
    } else {
      if (n == 0) {
        res = str[i];
        break;
      }
      n--;
    }
  }
  return res;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  while (true) {
    std::string str;
    std::cin >> str >> n;
    if (str == "0" && n == 0)
      break;
    int i = 0;
    std::cout << expand(str, i) << '\n';
  }
  return 0;
}