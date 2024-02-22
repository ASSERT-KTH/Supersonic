#include <iostream>
#include <vector>
#include <numeric>

int solve(const std::vector<std::string>& s, int n, int& y, int x) {
  if (isdigit(s[y][x]))
    return s[y++][x] - '0';
  char op = s[y][x];
  ++y, ++x;
  const int size = static_cast<int>(s.size());
  std::vector<int> term;
  while (y < size) {
    term.push_back(solve(s, n, y, x));
  }
  switch (op) {
    case '+':
      return std::accumulate(term.begin(), term.end(), 0);
    case '*':
      return std::accumulate(term.begin(), term.end(), 1, std::multiplies<int>());
  }
  return 0;
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