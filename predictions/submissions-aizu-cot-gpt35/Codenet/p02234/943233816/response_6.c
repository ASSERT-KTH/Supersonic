#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int matrixChainOrder(int pl, int* p) {
  int n = pl - 1;
  int** m = (int**)malloc(sizeof(int*) * n);
  for (int i = 0; i < n; i++) {
    m[i] = (int*)malloc(sizeof(int) * n);
  }

  for (int l = 2; l <= n; l++) {
    for (int i = 1; i <= n - l + 1; i++) {
      int j = i + l - 1;
      m[i][j] = INT_MAX;
      int pk = p[i - 1] * p[j];
      for (int k = i; k < j; k++) {
        int q = m[i][k] + m[k + 1][j] + pk * p[k];
        if (m[i][j] > q) {
          m[i][j] = q;
        }
      }
    }
  }

  int result = m[1][n];

  for (int i = 0; i < n; i++) {
    free(m[i]);
  }
  free(m);

  return result;
}

int main() {
  int n, k;
  scanf("%d", &n);
  int* p = (int*)malloc(sizeof(int) * (n + 1));
  for (int i = 0; i <= n; i++) {
    scanf("%d", &p[i]);
    if (i < n) {
      scanf("%d", &k);
    }
  }
  int result = matrixChainOrder(n + 1, p);
  printf("%d\n", result);
  free(p);
  return 0;
}