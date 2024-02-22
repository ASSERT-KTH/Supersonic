#include <iostream>
#include <vector>
#include <numeric>

int solve(const std::vector<std::string>& s, int n, int& y, int x) {
  if (std::isdigit(s[y][x]))
    return s[y++][x] - '0';
  char op = s[y][x];
  ++y, ++x;
  std::vector<int> term;
  term.reserve(n);
  while (y < n && (int)s[y].size() > x) {
    term.push_back(solve(s, n, y, x));
  }
  int result = 0;
  if (op == '+') {
    for (int i : term) {
      result += i;
    }
  } else {
    result = 1;
    for (int i : term) {
      result *= i;
    }
  }
  return result;
}

int main(void) {
  int n;
  while (std::cin >> n, n) {
    std::vector<std::string> s(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> s[i];
    }
    int y = 0;
    std::cout << solve(s, n, y, 0) << std::endl;
  }
  return 0;
}