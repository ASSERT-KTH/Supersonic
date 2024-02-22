#include <cstdio>
#include <cstring>

const int MAXN = 1000000;
int dp[MAXN];
int main() {
  int n;
  while (scanf("%d", &n) && n != 0) {
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i * i <= n; i++) {
      for (int j = i * i; j <= n; j++) {
        dp[j] += dp[j - i * i];
      }
    }
    int result = 0;
    for (int i = 1; i <= 4; i++) {
      result += dp[n - i * i];
    }
    printf("%d\n", result);
  }
}