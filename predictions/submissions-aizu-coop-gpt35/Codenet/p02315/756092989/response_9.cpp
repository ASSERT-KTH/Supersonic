#include <iostream>
#include <vector>

int main() {
  int n, W;
  std::cin >> n >> W;

  std::vector<int> weight;
  std::vector<int> value;
  weight.reserve(n);
  value.reserve(n);

  for (int i = 0; i < n; i++) {
    int v, w;
    std::cin >> v >> w;
    value.push_back(v);
    weight.push_back(w);
  }

  std::vector<std::vector<int>> dp(n + 1, std::vector<int>(W + 1, 0));

  for (int i = 1; i <= n; i++) {
    for (int w = 1; w <= W; w++) {
      int prevWeight = w - weight[i - 1];
      if (prevWeight >= 0) {
        dp[i][w] = std::max(dp[i - 1][w], dp[i - 1][prevWeight] + value[i - 1]);
      } else {
        dp[i][w] = dp[i - 1][w];
      }
    }
  }

  std::cout << dp[n][W] << '\n';

  return 0;
}