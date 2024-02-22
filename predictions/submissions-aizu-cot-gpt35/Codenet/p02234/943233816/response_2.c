#include <stdio.h>

int p[101];
int m[101];

int matrixChainOrder(int pl) {
  int n = pl - 1;
  int i, j, k, q;

  for (i = 2; i <= n; i++) {
    m[i] = 0;
  }

  for (int l = 2; l <= n; l++) {
    for (i = 1; i <= n - l + 1; i++) {
      j = i + l - 1;
      m[i] = INT_MAX;
      for (k = i; k < j; k++) {
        q = m[k] + m[k + 1] + p[i - 1] * p[k] * p[j];
        if (m[i] > q)
          m[i] = q;
      }
    }
  }

  return m[1];
}

int main() {
  int n, i;

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &p[i]);
  }
  scanf("%d", &p[n]);

  int result = matrixChainOrder(n + 1);
  printf("%d\n", result);

  return 0;
}