#include <iostream>
#include <string>
#include <sstream>

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
char expand(const std::string &str, int start, int len) {
  for (int i = start; i < start + len; ++i) {
    if (isdigit(str[i])) {
      int j = 1;
      while (isdigit(str[i + j]))
        j++;
      std::stringstream ss(str.substr(i, j));
      int num;
      ss >> num;
      int s, e, idx = i + j;
      if (str[idx] == '(') {
        int k;
        k = cket(str, idx + 1);
        s = idx + 1;
        e = k - s;
        i = k;
      } else {
        s = idx;
        e = 1;
        i = idx;
      }
      for (int l = 0; l < num; ++l) {
        char a = expand(str, s, e);
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