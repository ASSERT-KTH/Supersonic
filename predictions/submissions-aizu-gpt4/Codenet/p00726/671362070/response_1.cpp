#include <cstdlib>
#include <iostream>
#include <string>

int cket(const std::string &str, int i) {
  int n = 1;
  while (i < str.size()) {
    if (str[i] == '(') n++;
    if (str[i] == ')') n--;
    if (n == 0) break;
    ++i;
  }
  return i;
}

int n;

char expand(const std::string &str, int &i) {
  while (i < str.size()) {
    if (isdigit(str[i])) {
      int j = i;
      while (isdigit(str[j])) ++j;
      int num = std::atoi(str.substr(i, j-i).c_str());
      i = j;
      int s, e;
      if (str[i] == '(') {
        s = i + 1;
        e = cket(str, s);
        i = e;
      } else {
        s = i;
        e = s + 1;
      }
      for (int l = 0; l < num; ++l) {
        int temp = i;
        char a = expand(str, temp);
        if (a != '0') return a;
        i = e;
      }
    } else {
      if (n == 0) {
        return str[i];
      }
      n--;
      ++i;
    }
  }
  return '0';
}

int main(void) {
  while (true) {
    std::string str;
    std::cin >> str >> n;
    if (str == "0" && n == 0) break;
    int i = 0;
    std::cout << expand(str, i) << std::endl;
  }
  return 0;
}