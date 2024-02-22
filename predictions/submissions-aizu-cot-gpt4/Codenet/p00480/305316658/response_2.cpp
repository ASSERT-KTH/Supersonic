#include <cstdio>
long long dp[110][21];
int a[101];
int main() {
  int N;
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &a[i]);
  }
  dp[1][a[1]] = 1;
  for (int i = 2; i < N; ++i) {
    for (int j = 0; j <= 20; ++j) {
      if (j - a[i] >= 0)
        dp[i][j] += dp[i - 1][j - a[i]];
      if (j + a[i] <= 20)
        dp[i][j] += dp[i - 1][j + a[i]];
    }
  }
  printf("%lld\n", dp[N - 1][a[N]]);
  return 0;
}