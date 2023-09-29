#include <cstdlib>
#include <iostream>
#include <string>
int cket(const std::string &str, int i, const int size) {
  int n = 1;
  for (; i < size; ++i) {
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
char expand(const std::string &str, const int size) {
  std::string res;
  for (int i = 0; i < size; ++i) {
    if (isdigit(str[i])) {
      int j = 1;
      while (isdigit(str[i + j]))
        j++;
      int num = std::atoi(str.substr(i, j).c_str());
      int s, e;
      if (str[i + j] == '(') {
        int k;
        k = cket(str, i + j + 1, size);
        s = i + j + 1;
        e = k - (i + j + 1);
        i = k;
      } else {
        s = i + j;
        e = 1;
        i = i + j;
      }
      for (int l = 0; l < num; ++l) {
        char a = expand(str.substr(s, e), e);
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
    std::cout << expand(str, str.size()) << std::endl;
  }
  return 0;
}