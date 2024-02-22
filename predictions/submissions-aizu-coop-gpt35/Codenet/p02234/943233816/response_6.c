#include <stdio.h>
#define INF 100000000

int matrixChainOrder(int pl) {
  int n = pl - 1;
  int m[101]; // 1D array instead of 2D array
  int i, j, l, k, q;

  for (i = 1; i <= n; i++) {
    m[i] = 0;
  }

  for (l = 2; l <= n; l++) {
    for (i = 1; i <= n - l + 1; i++) {
      j = i + l - 1;
      m[j] = INF;
      for (k = i; k < j; k++) {
        q = m[k] + m[k + 1] + p[i - 1] * p[k] * p[j];
        if (m[j] > q)
          m[j] = q;
      }
    }
  }

  return m[n];
}

int main() {
  int n, i, x, k;
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    int dim;
    scanf("%d", &dim);
    if (i < n - 1)
      scanf("%d", &k);
  }

  scanf("%d", &k);
  x = matrixChainOrder(n + 1);
  printf("%d\n", x);
  return 0;
}