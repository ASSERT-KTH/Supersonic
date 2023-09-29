#include <stdio.h>
#include <limits.h>
#define MAX_DIM 101

int m[MAX_DIM][MAX_DIM];
int p[MAX_DIM];

int matrixChainOrder(int pl) {
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
        if (q < m[i][j]) {
          m[i][j] = q;
        }
      }
    }
  }
  return m[1][n];
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i <= n; i++) {
    scanf("%d", &p[i]);
  }
  printf("%d\n", matrixChainOrder(n + 1));
  return 0;
}