#include <iostream>
#include <string>

int cket(const std::string &str, int i) {
  int n = 1;
  while (i < str.size()) {
    if (str[i] == '(')
      ++n;
    if (str[i] == ')')
      --n;
    if (n == 0)
      break;
    ++i;
  }
  return i;
}

int n;

char expand(const std::string &str, int &i) {
  while (i < str.size()) {
    if (isdigit(str[i])) {
      int num = 0;
      while (isdigit(str[i]))
        num = num * 10 + str[i++] - '0';
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
        if (n == 0) {
          return str[s];
        }
        --n;
        char a = expand(str, s);
        if (a != '0')
          return a;
      }
    } else {
      if (n == 0) {
        return str[i];
      }
      --n;
      ++i;
    }
  }
  return '0';
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
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