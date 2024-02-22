#include <stdio.h>
#include <limits.h>

int matrixChainOrder(int p[], int pl) {
  int n = pl - 1;
  int m[(n + 1) * (n + 1)];

  for (int i = 1; i <= n; i++) {
    m[i * (n + 1) + i] = 0;
  }

  for (int l = 2; l <= n; l++) {
    for (int j = l; j <= n; j++) {
      int i = j - l + 1;
      m[i * (n + 1) + j] = INT_MAX;

      for (int k = i; k < j; k++) {
        int q = m[i * (n + 1) + k] + m[(k + 1) * (n + 1) + j] + p[i - 1] * p[k] * p[j];
        if (m[i * (n + 1) + j] > q) {
          m[i * (n + 1) + j] = q;
        }
      }
    }
  }

  return m[n + 1];
}

int main() {
  int n;
  scanf("%d", &n);
  int p[n + 1];

  for (int i = 0; i <= n; i++) {
    scanf("%d", &p[i]);
  }

  int x = matrixChainOrder(p, n + 1);
  printf("%d\n", x);

  return 0;
}