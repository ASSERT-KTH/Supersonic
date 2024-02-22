#include <stdio.h>
#define INF 100000000

int matrixChainOrder(int pl) {
  int n, i, j, l, k, q;
  n = pl - 1;

  // Allocate a one-dimensional array for m
  int m[101] = {0};

  for (l = 2; l <= n; l++) {
    for (i = 1; i <= n - l + 1; i++) {
      j = i + l - 1;
      m[i] = INF;

      // Unroll the innermost loop to perform two iterations at a time
      for (k = i; k < j; k += 2) {
        q = m[i] + m[k + 1] + p[i - 1] * p[k] * p[j];
        if (m[i] > q) {
          m[i] = q;
        }
        q = m[i + 1] + m[k + 2] + p[i] * p[k + 1] * p[j];
        if (m[i + 1] > q) {
          m[i + 1] = q;
        }
      }
    }
  }
  return m[1];
}

int main() {
  int n, i, x, k;
  scanf("%d", &n);

  // Allocate a one-dimensional array for p
  int p[102] = {0};

  for (i = 0; i < n; i++) {
    scanf("%d", &p[i]);
    if (i < n - 1) {
      scanf("%d", &k);
    }
  }
  scanf("%d", &p[n]);
  x = matrixChainOrder(n + 1);
  printf("%d\n", x);
  return 0;
}