#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>

int solve(const std::vector<std::string>& s, int n, int& y, int x) {
  if (std::isdigit(s[y][x]))
    return s[y++][x] - '0';
  
  char op = s[y][x];
  ++y, ++x;
  int result = 0;
  
  while (y < n) {
    if (op == '+')
      result += solve(s, n, y, x);
    else
      result *= solve(s, n, y, x);
    
    ++x;
    if (x >= s[y].size())
      break;
  }
  
  return result;
}

int main(void) {
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