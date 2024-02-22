#include <iostream>

typedef long long ll;
const int mod = 1000000007;
int N, W;
int w[201];
ll dp[2][10001];

int main() {
  std::cin >> N >> W;
  for (int i = 0; i < N; i++)
    std::cin >> w[i];

  for (int j = 0; j <= W; j++) {
    for (int k = 0; k < N; k++) {
      if (j <= W && (k == N - 1 || w[k] + j > W))
        dp[N % 2][j] = 1;
      else
        dp[N % 2][j] = 0;
    }
  }

  for (int i = N - 1; i >= 0; i--) {
    for (int j = 0; j <= W; j++) {
      for (int k = 0; k < N; k++) {
        dp[i % 2][j] = 0;
        int nmwidx = k;
        if (k == N - 1 || w[k] > w[i])
          nmwidx = i;
        dp[i % 2][j] += dp[(i + 1) % 2][nmwidx];
        if (j + w[i] <= W)
          dp[i % 2][j] += dp[(i + 1) % 2][k];
        dp[i % 2][j] %= mod;
      }
    }
  }

  std::cout << dp[0][0] << std::endl;
  return 0;
}