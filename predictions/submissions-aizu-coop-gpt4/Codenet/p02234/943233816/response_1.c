#include <stdio.h>
#include <stdlib.h>

#define INF 100000000

int matrixChainOrder(int* p, int** m, int n) {
  int i, l, j, k, q;
  for (i = 1; i <= n; i++) {
    m[i][i] = 0;
  }
  for (l = 2; l <= n; l++) {
    for (i = 1; i <= n - l + 1; i++) {
      j = i + l - 1;
      m[i][j] = INF;
      for (k = i; k < j; k++) {
        q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
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
  int *p = malloc((n + 1) * sizeof(int));
  int **m = malloc((n + 1) * sizeof(int *));
  for (i = 0; i <= n; i++) {
    m[i] = malloc((n + 1) * sizeof(int));
  }
  for (i = 0; i < n; i++) {
    scanf("%d", &p[i]);
    if (i < n - 1)
      scanf("%d", &k);
  }
  scanf("%d", &p[n]);
  x = matrixChainOrder(p, m, n + 1);
  printf("%d\n", x);
  free(p);
  for (i = 0; i <= n; i++) {
    free(m[i]);
  }
  free(m);
  return 0;
}