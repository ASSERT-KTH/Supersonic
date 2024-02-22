#include <cstdlib>
#include <iostream>
#include <string>

int n;

char expand(const std::string &str, int s, int e) {
  for (int i = s; i < e; ++i) {
    if (isdigit(str[i])) {
      int num = 0;
      while (isdigit(str[i])) {
        num = num * 10 + (str[i] - '0');
        i++;
      }
      int s_new, e_new;
      if (str[i] == '(') {
        int k = i + 1;
        int count = 1;
        while (count != 0) {
          if (str[k] == '(')
            count++;
          if (str[k] == ')')
            count--;
          k++;
        }
        s_new = i + 1;
        e_new = k - 1;
        i = k - 1;
      } else {
        s_new = i;
        e_new = i + 1;
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
    std::cout << expand(str, 0, str.size()) << std::endl;
  }
  return 0;
}