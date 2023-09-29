#include <iostream>
#include <string>

inline int cket(const std::string &str, int i) {
  for (int n = 1; i < str.size(); ++i) {
    n += str[i] == '(' ? 1 : (str[i] == ')' ? -1 : 0);
    if (n == 0) return i;
  }
  return i;
}

int n;

inline char expand(const std::string &str, int &i) {
  for (; i < str.size(); ++i) {
    if (isdigit(str[i])) {
      int j = i;
      while (isdigit(str[j])) ++j;
      int num = std::atoi(str.substr(i, j - i).c_str());
      i = j;
      int s = i, e;
      if (str[i] == '(') {
        int k = cket(str, i + 1);
        s = i + 1;
        e = k - s;
        i = k;
      } else {
        e = 1;
      }
      while (num--) {
        int p = s;  
        char a = expand(str, p);
        if (a != '0') return a;
      }
    } else {
      if (n == 0) return str[i];
      --n;
    }
  }
  return '0';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::string str;
  while (std::cin >> str >> n, str != "0" || n != 0) {
    int i = 0;
    std::cout << expand(str, i) << '\n';
  }
  return 0;
}