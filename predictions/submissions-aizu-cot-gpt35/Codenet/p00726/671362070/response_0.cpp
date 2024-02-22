#include <iostream>
#include <string>
#include <cctype>

int cket(const std::string& str, int i) {
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

char expand(const std::string& str) {
  int n = 1;
  int size = str.size();
  for (int i = 0; i < size; ++i) {
    if (std::isdigit(str[i])) {
      int j = 1;
      while (std::isdigit(str[i + j]))
        j++;
      int num = std::stoi(str.substr(i, j));
      int s, e;
      if (str[i + j] == '(') {
        int k = cket(str, i + j + 1);
        s = i + j + 1;
        e = k - (i + j + 1);
        i = k;
      } else {
        s = i + j;
        e = 1;
        i = i + j;
      }
      std::string sub = str.substr(s, e);
      for (int l = 0; l < num; ++l) {
        char a = expand(sub);
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
    int n;
    std::cin >> str >> n;
    if (str == "0" && n == 0)
      break;
    std::cout << expand(str) << std::endl;
  }
  return 0;
}