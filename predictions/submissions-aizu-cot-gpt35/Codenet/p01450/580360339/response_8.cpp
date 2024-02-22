#include <iostream>

const int mod = 1000000007;

int N, W;
int w[201];
int dp[2][10001][202];

int main() {
  std::cin >> N >> W;
  for (int i = 0; i < N; i++)
    std::cin >> w[i];

  for (int j = 0; j <= W; j++) {
    for (int k = 0; k <= N; k++) {
      if (j <= W && (k == N || w[k] + j > W))
        dp[N % 2][j][k] = 1;
      else
        dp[N % 2][j][k] = 0;
    }
  }

  for (int i = N - 1; i >= 0; i--) {
    int cur = (i + 1) % 2;
    int nxt = i % 2;
    for (int j = 0; j <= W; j++) {
      for (int k = 0; k <= N; k++) {
        dp[nxt][j][k] = 0;
        if (k == N || w[k] > w[i])
          dp[nxt][j][k] += dp[cur][j][i];
        if (j + w[i] <= W)
          dp[nxt][j][k] += dp[cur][j + w[i]][k];
        dp[nxt][j][k] %= mod;
      }
    }
  }

  std::cout << dp[0][0][N] << std::endl;
  return 0;
}