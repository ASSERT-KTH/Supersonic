#include <cstdio>
#include <cstring>
#include <cmath>

const int MAX_N = 1000000;
const int MAX_K = 5;

int dp[MAX_N][MAX_K];

int main() {
  int n;
  while (~scanf("%d", &n)) {
    if (n == 0)
      break;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= sqrt(n); i++) {
      for (int k = 1; k <= 4; k++) {
        for (int j = i * i; j <= n; j++) {
          dp[j][k] += dp[j - i * i][k - 1];
        }
      }
    }
    printf("%d\n", dp[n][4] + dp[n][3] + dp[n][2] + dp[n][1]);
  }
}