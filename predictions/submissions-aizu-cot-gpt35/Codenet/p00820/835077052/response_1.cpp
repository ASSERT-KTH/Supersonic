#include <cstdio>
#include <algorithm>

int dp[1000000][5];

int main() {
  while (true) {
    int n;
    scanf("%d", &n);
    if (n == 0)
      break;

    std::fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(dp[0][0]), 0);
    dp[0][0] = 1;

    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= 4; k++) {
        for (int i = 1; i * i <= j; i++) {
          dp[j][k] += dp[j - i * i][k - 1];
        }
      }
    }

    int result = dp[n][1] + dp[n][2] + dp[n][3] + dp[n][4];
    printf("%d\n", result);
  }

  return 0;
}