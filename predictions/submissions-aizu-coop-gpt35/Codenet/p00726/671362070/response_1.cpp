#include <iostream>
#include <string>

int cket(const std::string& str, int i) {
  int n = 1;
  while (n > 0 && i < str.size()) {
    if (str[i] == '(')
      n++;
    else if (str[i] == ')')
      n--;
    i++;
  }
  return i;
}

char expand(const std::string& str, int start, int end, int& n) {
  for (int i = start; i < end; ++i) {
    if (std::isdigit(str[i])) {
      int j = i + 1;
      while (j < end && std::isdigit(str[j]))
        j++;
      int num = std::stoi(str.substr(i, j - i));
      int s, e;
      if (str[j] == '(') {
        int k = cket(str, j + 1);
        s = j + 1;
        e = k - (j + 1);
        i = k;
      } else {
        s = j;
        e = 1;
        i = j;
      }
      for (int l = 0; l < num; ++l) {
        char a = expand(str, s, s + e, n);
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

int main() {
  while (true) {
    std::string str;
    int n;
    std::cin >> str >> n;
    if (str == "0" && n == 0)
      break;
    std::cout << expand(str, 0, str.size(), n) << std::endl;
  }
  return 0;
}