#include <iostream>
#include <vector>
#include <numeric>
#include <functional>

#define rep(i, n) for (int i = 0; i < n; ++i)

inline int solve(std::vector<std::string> &s, int &y, int x) {
  if (isdigit(s[y][x]))
    return s[y++][x] - '0';
  char op = s[y][x];
  ++y, ++x;
  std::vector<int> term;
  while (y < s.size() && s[y].size() > x) {
    term.push_back(solve(s, y, x));
  }
  if (op == '+')
    return std::accumulate(term.begin(), term.end(), 0);
  else
    return std::accumulate(term.begin(), term.end(), 1, std::multiplies<int>());
}

int main(void) {
  int n;
  while (std::cin >> n, n) {
    std::vector<std::string> s(n);
    rep(i, n) std::cin >> s[i];
    int y = 0;
    std::cout << solve(s, y, 0) << '\n';
  }
  return 0;
}