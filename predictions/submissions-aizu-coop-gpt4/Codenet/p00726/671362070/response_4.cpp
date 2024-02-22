#include <cstdlib>
#include <iostream>
#include <string>

int n;

char expand(const std::string &str, int s = 0, int e = -1) {
  if(e == -1) e = str.size();
  for (int i = s; i < e; ++i) {
    if (isdigit(str[i])) {
      int j = 1;
      while (isdigit(str[i + j]))
        j++;
      int num = std::stoi(str.substr(i, j));
      int s1, e1;
      if (str[i + j] == '(') {
        int n = 1;
        int k = i + j + 1;
        while(n != 0) {
          if(str[k] == '(') n++;
          if(str[k] == ')') n--;
          k++;
        }
        s1 = i + j + 1;
        e1 = k - 1;
        i = k - 1;
      } else {
        s1 = i + j;
        e1 = s1 + 1;
        i = i + j;
      }
      for (int l = 0; l < num; ++l) {
        char a = expand(str, s1, e1);
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