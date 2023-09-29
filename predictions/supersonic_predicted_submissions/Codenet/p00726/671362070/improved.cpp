#include <cstdlib>
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
char expand(std::string str) {
  for (int i = 0; i < str.size(); ++i) {
    if (isdigit(str[i])) {
      int j = 1;
      while (isdigit(str[i + j]))
        j++;
      int num = std::atoi(str.substr(i, j).c_str());
      int s, e;
      if (str[i + j] == '(') {
        int k;
        k = cket(str, i + j + 1);
        s = i + j + 1;
        e = k - (i + j + 1);
        i = k;
      } else {
        s = i + j;
        e = 1;
        i = i + j;
      }
      for (int l = 0; l < num; ++l) {
        char a = expand(str.substr(s, e));
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
