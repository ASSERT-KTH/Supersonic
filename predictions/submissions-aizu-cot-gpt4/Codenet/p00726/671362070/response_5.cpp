#include <cstdlib>
#include <iostream>
#include <string>

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
char expand(const std::string &str, int s = 0, int e = std::string::npos) {
  for (int i = s; i < s + e && i < str.size(); ++i) {
    if (isdigit(str[i])) {
      int j = 1;
      while (isdigit(str[i + j]))
        j++;
      int num = std::stoi(str.substr(i, j));
      int s_new, e_new;
      if (str[i + j] == '(') {
        int k = cket(str, i + j + 1);
        s_new = i + j + 1;
        e_new = k - (i + j + 1);
        i = k;
      } else {
        s_new = i + j;
        e_new = 1;
        i = i + j;
      }
      for (int l = 0; l < num; ++l) {
        char a = expand(str, s_new, e_new);
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
    std::cout << expand(str) << std::endl;
  }
  return 0;
}