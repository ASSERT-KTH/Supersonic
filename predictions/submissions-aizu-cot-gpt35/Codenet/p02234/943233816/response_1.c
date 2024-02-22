#include <stdio.h>

int matrixChainOrder(int p[], int n) {
  int m[n+1][n+1];
  int i, j, l, k, q;

  for (i = 1; i <= n; i++) {
    m[i][i] = 0;
  }

  for (l = 2; l <= n; l++) {
    for (i = 1; i <= n - l + 1; i++) {
      j = i + l - 1;
      m[i][j] = INT_MAX;
      for (k = i + 1; k <= j; k++) {
        q = m[i][k-1] + m[k][j] + p[i-1] * p[k] * p[j];
        if (m[i][j] > q) {
          m[i][j] = q;
        }
      }
    }
  }

  return m[1][n];
}

int main() {
  int n, i, x;
  scanf("%d", &n);
  int p[n+1];
  for (i = 0; i <= n; i++) {
    scanf("%d", &p[i]);
  }
  x = matrixChainOrder(p, n);
  printf("%d\n", x);
  return 0;
}