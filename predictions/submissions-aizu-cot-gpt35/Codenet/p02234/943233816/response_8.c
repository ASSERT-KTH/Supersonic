#include <stdio.h>

const int INF = 100000000;

int matrixChainOrder(int numMatrices) {
  int n = numMatrices - 1;
  int m[n+1];
  int p[n+1];
  
  for (int i = 0; i <= n; i++) {
    m[i] = 0;
  }
  
  for (int l = 2; l <= n; l++) {
    for (int i = 0; i <= n - l; i++) {
      int j = i + l;
      m[i][j] = INF;
      for (int k = i; k < j; k++) {
        int q = m[i][k] + m[k + 1][j] + p[i] * p[k] * p[j];
        if (m[i][j] > q)
          m[i][j] = q;
      }
    }
  }
  
  return m[0][n];
}

int main() {
  int n;
  scanf("%d", &n);
  
  int p[n+1];
  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
    if (i < n - 1)
      scanf("%d", &p[i+1]);
  }
  
  printf("%d\n", matrixChainOrder(n + 1));
  return 0;
}