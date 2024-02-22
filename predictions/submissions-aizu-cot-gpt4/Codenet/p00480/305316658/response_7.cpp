#include <cstdio>
long long dp[21];
int main() {
  int N;
  scanf("%d", &N);
  int *a = new int[N+1];
  for (int i = 1; i <= N; i++) {
    scanf("%d", &a[i]);
  }
  dp[a[1]] = 1;
  for (int i = 2; i < N; i++) {
    long long next[21] = {0};
    for (int j = 0; j <= 20; j++) {
      if (j - a[i] >= 0)
        next[j] += dp[j - a[i]];
      if (j + a[i] <= 20)
        next[j] += dp[j + a[i]];
    }
    for (int j = 0; j <= 20; j++) {
        dp[j] = next[j];
    }
  }
  printf("%lld\n", dp[a[N]]);
  delete[] a;
  return 0;
}