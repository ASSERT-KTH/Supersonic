#include <iostream>
#include <vector>

int main() {
  int N, W;
  std::cin >> N >> W;

  // Store the values and weights in vectors
  std::vector<int> value(N);
  std::vector<int> weight(N);
  for (int i = 0; i < N; i++)
    std::cin >> value[i] >> weight[i];

  // Initialize the dp array with dimensions (N+1) x (W+1)
  std::vector<std::vector<int>> dp(N + 1, std::vector<int>(W + 1, 0));

  // Iterate through the items and weights
  for (int i = 1; i <= N; i++) {
    for (int w = 1; w <= W; w++) {
      if (w >= weight[i - 1])
        dp[i][w] = std::max(dp[i - 1][w - weight[i - 1]] + value[i - 1], dp[i - 1][w]);
      else
        dp[i][w] = dp[i - 1][w];
    }
  }

  std::cout << dp[N][W] << std::endl;
  return 0;
}