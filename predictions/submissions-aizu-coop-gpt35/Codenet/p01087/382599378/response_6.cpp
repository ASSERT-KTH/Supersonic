#include <iostream>
#include <numeric>

int solve(const std::string& s, int n, int& y, int x) {
  if (std::isdigit(s[y * n + x])) {
    return s[y++ * n + x] - '0';
  }
  char op = s[y * n + x];
  ++y, ++x;
  int term = 0;
  int result = 0;
  while (y < n && x < n) {
    result += solve(s, n, y, x);
  }
  if (op == '+') {
    return result;
  } else {
    return result + 1;
  }
}

int main(void) {
  int n;
  while (std::cin >> n, n) {
    std::string s;
    for (int i = 0; i < n; ++i) {
      std::string line;
      std::cin >> line;
      s += line;
    }
    int y = 0;
    std::cout << solve(s, n, y, 0) << std::endl;
  }
  return 0;
}