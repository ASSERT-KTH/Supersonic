#include <iostream>
#include <vector>
#include <numeric>
#include <functional>

int solve(std::vector<std::string> &s, int n, int &y, int x) {
  if (isdigit(s[y][x]))
    return s[y++][x] - '0';
  char op = s[y][x];
  ++y;
  ++x;
  std::vector<int> term;
  term.reserve(n); // reserve memory for n elements
  while (y < n && (int)s[y].size() > x) {
    term.push_back(solve(s, n, y, x));
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
    for(int i = 0; i < n; i++) std::cin >> s[i];
    int y = 0;
    std::cout << solve(s, n, y, 0) << std::endl;
  }
  return 0;
}