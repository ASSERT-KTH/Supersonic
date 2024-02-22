#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

int solve(int n, std::vector<std::pair<int, int>>& book) {
  int sumf = 0, sums = 0;
  for (int i = 0; i < n; ++i)
    sumf += book[i].first, sums += book[i].second;
  if (2 * book[0].first <= sumf)
    return sumf + sums;
  int d = 2 * book[0].first - sumf;
  std::vector<bool> dp(d + 1, false);
  dp[0] = true;
  for (int i = 1; i < n; ++i) {
    for (int j = d - book[i].second; j >= 0; --j) {
      dp[j + book[i].second] = dp[j + book[i].second] || dp[j];
    }
  }
  for (int D = d; D >= 0; --D) {
    if (dp[D]) {
      return sumf + sums + (d - D);
    }
  }
  return sumf + sums;
}

int main() {
  int n;
  while (std::cin >> n && n) {
    std::vector<std::pair<int, int>> book(n);
    for (int i = 0; i < n; ++i)
      std::cin >> book[i].first >> book[i].second;
    std::cout << solve(n, book) << std::endl;
  }
  return 0;
}