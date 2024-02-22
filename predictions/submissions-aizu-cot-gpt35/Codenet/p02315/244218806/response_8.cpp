#include <iostream>

int main() {
  int N, W;
  std::cin >> N >> W;
  int v[N], w[N];
  for (int i = 0; i < N; i++)
    std::cin >> v[i] >> w[i];
  int dp[N + 1][W + 1] = {};
  for (int i = N - 1; i >= 0; i--) {
    for (int j = 0; j <= W; j++) {
      if (j - w[i] < 0) {
        dp[i][j] = dp[i + 1][j];
      } else {
        dp[i][j] = std::max(dp[i + 1][j], dp[i + 1][j - w[i]] + v[i]);
      }
    }
  }
  std::cout << dp[0][W] << std::endl;
}