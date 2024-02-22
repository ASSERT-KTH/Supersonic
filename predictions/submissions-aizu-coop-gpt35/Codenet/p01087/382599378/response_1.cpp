#include <iostream>
#include <vector>
#include <stack>
#include <numeric>

int solve(const std::vector<std::string>& s, int n, int& y, int x) {
  if (isdigit(s[y][x]))
    return s[y++][x] - '0';
  char op = s[y][x];
  ++y, ++x;
  std::stack<int> term;
  while (y < n && static_cast<int>(s[y].size()) > x) {
    term.push(solve(s, n, y, x));
  }
  int initial_value = (op == '+') ? 0 : 1;
  int result = initial_value;
  while (!term.empty()) {
    result = (op == '+') ? result + term.top() : result * term.top();
    term.pop();
  }
  return result;
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