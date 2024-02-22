#include <stdio.h>

#define INF 100000000

int p[101];
int dp[101];

int matrixChainOrder(int pl) {
  int n, i, j, l, k, q;
  n = pl - 1;

  // Initialize dp array
  for (i = 1; i <= n; i++) {
    dp[i] = INF;
  }
  for (i = 0; i <= n; i++) {
    dp[i] = 0;
  }

  for (l = 2; l <= n; l++) {
    for (i = 1; i <= n - l + 1; i++) {
      j = i + l - 1;
      dp[j] = INF;
      for (k = i; k < j; k++) {
        q = dp[i] + dp[k + 1] + p[i - 1] * p[k] * p[j];
        if (dp[j] > q) {
          dp[j] = q;
        }
      }
    }
  }
  return dp[n];
}

int main() {
  int n, i, x, k;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &p[i]);
  }
  scanf("%d", &p[n]);
  
  x = matrixChainOrder(n + 1);
  printf("%d\n", x);
  return 0;
}