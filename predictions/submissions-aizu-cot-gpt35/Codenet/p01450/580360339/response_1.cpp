#include <iostream>

const int mod = 1000000007;
int N, W;
int w[201];
long long dp[10001][202];

int main() {
  std::cin >> N >> W;
  for (int i = 0; i < N; i++)
    std::cin >> w[i];

  // Initialize dp array
  std::memset(dp, 0, sizeof(dp));

  for (int j = 0; j <= W; j++) {
    for (int k = 0; k < N; k++) {
      if (j <= W && (k == N - 1 || w[k] + j > W))
        dp[j][k] = 1;
      else
        dp[j][k] = 0;
    }
  }

  for (int i = N - 2; i >= 0; i--) {
    int cur = i + 1;
    int nxt = i;
    for (int j = 0; j <= W; j++) {
      for (int k = 0; k < N; k++) {
        dp[j][k] = 0;
        int nmwidx = k;
        if (k == N - 1 || w[k] > w[i])
          nmwidx = i;
        dp[j][k] += dp[j][nmwidx];
        if (j + w[i] <= W)
          dp[j][k] += dp[j + w[i]][k];
        dp[j][k] %= mod;
      }
    }
  }

  std::cout << dp[0][N - 1] << std::endl;
  return 0;
}