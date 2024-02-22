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
  char res = '0';
  for (int i = s; i < s + e && i < str.size(); ++i) {
    if (isdigit(str[i])) {
      int j = 1;
      while (isdigit(str[i + j]))
        j++;
      int num = std::atoi(str.substr(i, j).c_str());
      i = i + j;
      if (str[i] == '(') {
        int k = cket(str, i + 1);
        res = expand(str, i + 1, k - i - 1);
        i = k;
      } else {
        res = expand(str, i, 1);
      }
      for (int l = 1; l < num && res == '0'; ++l)
        res = expand(str, s, e);
    } else {
      if (n == 0) {
        return str[i];
      }
      n--;
    }
  }
  return res;
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