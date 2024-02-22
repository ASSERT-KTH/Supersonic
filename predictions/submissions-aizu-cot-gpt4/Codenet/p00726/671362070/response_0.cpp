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
      size_t idx;
      int num = std::stoi(str.substr(i), &idx);
      if (str[i + idx] == '(') {
        int k = cket(str, i + idx + 1);
        i = expand(str, i + idx + 1, k);
      } else {
        i += idx;
      }
      for (int l = 0; l < num; ++l) {
        char a = expand(str, i, i + 1);
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