#include <cstdio>
#include <cstring>

int main() {
  int n;
  while (~scanf("%d", &n)) {
    if (n == 0)
      break;
      
    int** dp = new int*[n+1];
    for (int i = 0; i <= n; i++) {
      dp[i] = new int[5];
      memset(dp[i], 0, sizeof(int) * 5);
    }
    
    dp[0][0] = 1;
    for (int i = 1; i * i <= n; i++) {
      for (int k = 1; k <= 4; k++) {
        for (int j = i * i; j <= n; j++) {
          dp[j][k] += dp[j - i * i][k - 1];
        }
      }
    }
    
    int result = dp[n][4] + dp[n][3] + dp[n][2] + dp[n][1];
    
    for (int i = 0; i <= n; i++) {
      delete[] dp[i];
    }
    delete[] dp;
    
    printf("%d\n", result);
  }
}