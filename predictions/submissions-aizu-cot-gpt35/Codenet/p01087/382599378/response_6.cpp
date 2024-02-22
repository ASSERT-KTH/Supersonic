#include <iostream>
#include <vector>
#include <numeric>

int solve(std::vector<std::string>& s, int n, int& y, int x) {
  if (isdigit(s[y][x]))
    return s[y++][x] - '0';
  char op = s[y][x];
  ++y, ++x;
  int term = 0;
  while (y < n && (int)s[y].size() > x) {
    term += solve(s, n, y, x);
  }
  if (op == '+')
    return term;
  else
    return term;
}

int main() {
  int n;
  while (std::cin >> n, n) {
    std::vector<std::string> s(n);
    for (int i = 0; i < n; ++i)
      std::cin >> s[i];
    int y = 0;
    std::cout << solve(s, n, y, 0) << std::endl;
  }
  return 0;
}