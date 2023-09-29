#include <iostream>
#include <vector>
#include <numeric>
#define rep(i, n) for (int i = 0; i < int(n); ++i)

int solve(std::vector<std::string> &s, int n, int &y, int x) {
  if (std::isdigit(s[y][x]))
    return s[y++][x] - '0';
  char op = s[y][x];
  ++y, ++x;
  std::vector<int> term;
  term.reserve(n);
  while (y < n && s[y].size() > x) {
    term.push_back(solve(s, n, y, x));
  }
  return op == '+' ? std::accumulate(term.begin(), term.end(), 0) : std::accumulate(term.begin(), term.end(), 1, std::multiplies<int>());
}

int main(void) {
  int n;
  while (std::cin >> n, n) {
    std::vector<std::string> s(n);
    rep(i, n) std::cin >> s[i];
    int y = 0;
    std::cout << solve(s, n, y, 0) << '\n';
  }
  return 0;
}