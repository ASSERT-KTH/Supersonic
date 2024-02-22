#include <stdio.h>
#define INF 100000000

int m[101][101];
int p[101];

int matrixChainOrder(int pl) {
  int n, i, j, l, k, q;
  n = pl - 1;

  // Initialize matrix m
  for (i = 2; i <= n; i++) {
    m[i][i] = 0;
  }

  for (l = 2; l <= n; l++) {
    for (i = 1; i <= n - l + 1; i++) {
      j = i + l - 1;
      m[i][j] = INF;

      // Calculate q once and store it in a temporary variable
      int sum = p[i - 1] * p[j];
      for (k = i; k < j; k++) {
        q = m[i][k] + m[k + 1][j] + sum * p[k];

        // Update m[i][j] if q is smaller
        if (m[i][j] > q)
          m[i][j] = q;
      }
    }
  }

  return m[1][n];
}

int main() {
  int n, i, x, k;
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%d", &p[i]);
    if (i < n - 1)
      scanf("%d", &k);
  }

  scanf("%d", &p[n]);

  x = matrixChainOrder(n + 1);
  printf("%d\n", x);

  return 0;
}