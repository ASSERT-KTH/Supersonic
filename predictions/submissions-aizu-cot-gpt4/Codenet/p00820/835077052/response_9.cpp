#include <cstdio>
#include <cstring>
#include <vector>

int main() {
  int n;
  while (~scanf("%d", &n)) {
    if (n == 0)
      break;
    std::vector<std::vector<int>> dp(n+1, std::vector<int>(5, 0));
    dp[0][0] = 1;
    for (int i = 1; i * i <= n; i++) {
      for (int k = 1; k <= 4; k++) {
        for (int j = i * i; j <= n; j++) {
          dp[j][k] += dp[j - i * i][k - 1];
        }
      }
    }
    int sum = dp[n][4] + dp[n][3] + dp[n][2] + dp[n][1];
    printf("%d\n", sum);
  }
}