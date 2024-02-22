#include <iostream>
#include <vector>

int main() {
  int N, W;
  std::cin >> N >> W;

  std::vector<int> v, w;
  v.reserve(N);
  w.reserve(N);

  for (int i = 0; i < N; i++) {
    int vi, wi;
    std::cin >> vi >> wi;
    v.push_back(vi);
    w.push_back(wi);
  }

  std::vector<std::vector<int>> dp(N + 1, std::vector<int>(W + 1, 0));

  for (int i = 0; i < N; i++) {
    for (int j = W; j >= 0; j--) {
      if (j - w[i] < 0) {
        dp[i + 1][j] = dp[i][j];
      } else {
        dp[i + 1][j] = std::max(dp[i][j], dp[i][j - w[i]] + v[i]);
      }
    }
  }

  std::cout << dp[N][W] << "\n";

  return 0;
}