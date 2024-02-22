#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n, W;
  std::cin >> n >> W;

  std::vector<int> weight(n), value(n);
  for (int i = 0; i < n; i++) {
    std::cin >> value[i] >> weight[i];
  }

  std::vector<std::vector<int>> dp(n + 1, std::vector<int>(W + 1, 0));
  for (int i = 0; i < n; i++) {
    for (int w = 0; w <= W; w++) {
      if (w >= weight[i]) {
        dp[i + 1][w] = std::max(dp[i][w - weight[i]] + value[i], dp[i][w]);
      } else {
        dp[i + 1][w] = dp[i][w];
      }
    }
  }

  std::cout << dp[n][W] << std::endl;
  return 0;
}