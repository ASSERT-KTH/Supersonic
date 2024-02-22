#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int matrixChainOrder(int p[], int m[][101], int pl) {
  int n = pl - 1;
  for (int i = 1; i <= n; i++) {
    m[i][i] = 0;
  }
  for (int l = 2; l <= n; l++) {
    for (int i = 1; i <= n - l + 1; i++) {
      int j = i + l - 1;
      m[i][j] = INT_MAX;
      for (int k = i; k < j; k++) {
        int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
        if (q < m[i][j])
          m[i][j] = q;
      }
    }
  }
  return m[1][n];
}

int main() {
  int n;
  scanf("%d", &n);
  int p[n+1];
  int m[n+1][101];
  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
    if (i < n - 1) {
      int k;  /* Unused variable, can be ignored */
      scanf("%d", &k);
    }
  }
  scanf("%d", &p[n]);
  int x = matrixChainOrder(p, m, n + 1);
  printf("%d\n", x);
  return 0;
}