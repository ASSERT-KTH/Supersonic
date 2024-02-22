#include <iostream>
#include <vector>
#include <numeric>

int solve(std::vector<std::string>& s, int n, int& y, int x, std::vector<int>& term) {
  if (std::isdigit(s[y][x]))
    return s[y++][x] - '0';
  char op = s[y][x];
  ++y, ++x;
  term.clear();
  while (y < n && x < s[y].size()) {
    term.push_back(solve(s, n, y, x, term));
  }
  switch(op) {
    case '+':
      return std::accumulate(term.begin(), term.end(), 0);
    case '*':
      return std::accumulate(term.begin(), term.end(), 1, std::multiplies<int>());
    default:
      return 0; // Handle invalid operator
  }
}

int main(void) {
  int n;
  while (std::cin >> n, n) {
    std::vector<std::string> s(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> s[i];
    }
    int y = 0;
    std::vector<int> term;
    std::cout << solve(s, n, y, 0, term) << std::endl;
  }
  return 0;
}