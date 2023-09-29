#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N, W;
  std::cin >> N >> W;
  std::vector<int> value(N), weight(N);
  for (int i = 0; i < N; i++)
    std::cin >> value[i] >> weight[i];
  
  std::vector<std::vector<int>> dp(N+1, std::vector<int>(W+1, 0));

  for (int i = 0; i < N; i++) {
    for (int w = 0; w <= W; w++) {
      if (w >= weight[i])
        dp[i + 1][w] = std::max(dp[i][w - weight[i]] + value[i], dp[i][w]);
      else
        dp[i + 1][w] = dp[i][w];
    }
  }
  std::cout << dp[N][W] << "\n";
  return 0;
}