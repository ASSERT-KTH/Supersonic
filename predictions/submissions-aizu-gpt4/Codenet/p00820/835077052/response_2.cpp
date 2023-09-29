#include <cstdio>
#include <cstring>

int dp[1000000][5];

int main() {
  int n;
  while (~scanf("%d", &n)) {
    if (n == 0)
      break;
      
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    
    for (int i = 1; i * i <= n; i++) {
      for (int k = 1; k <= 4; k++) {
        int limit = i * i;
        for (int j = limit; j <= n; j++) {
          dp[j][k] += dp[j - limit][k - 1];
        }
      }
    }
    
    printf("%d\n", dp[n][0] + dp[n][1] + dp[n][2] + dp[n][3]);
  }
  return 0;
}