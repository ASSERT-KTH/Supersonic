#include <stdio.h>
#include <limits.h>
#include <string.h>

#define N 101

int m[N][N], p[N];

int matrixChainOrder(int n) {
  memset(m, 0, sizeof(m));
  for (int l = 2; l < n; l++) {
    for (int i = 1; i < n - l + 1; i++) {
      int j = i + l - 1;
      m[i][j] = INT_MAX;
      for (int k = i; k < j; k++) {
        int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
        if (m[i][j] > q)
          m[i][j] = q;
      }
    }
  }
  return m[1][n - 1];
}

int main() {
  int n, x;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
    if (i < n - 1){
      int k;
      scanf("%d", &k);
    }
  }
  scanf("%d", &p[n]);
  x = matrixChainOrder(n + 1);
  printf("%d\n", x);
  return 0;
}