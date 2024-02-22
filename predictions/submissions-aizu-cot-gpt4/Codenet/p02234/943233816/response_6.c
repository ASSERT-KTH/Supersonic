#include <stdio.h>
#include <stdlib.h>
#define INF 100000000

int matrixChainOrder(int* p, int** m, int pl) {
  int n = pl - 1;
  for (int i = 1; i <= n; i++) {
    m[i][i] = 0;
  }
  for (int l = 2; l <= n; l++) {
    for (int i = 1; i <= n - l + 1; i++) {
      int j = i + l - 1;
      m[i][j] = INF;
      for (int k = i; k < j; k++) {
        int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
        if (m[i][j] > q)
          m[i][j] = q;
      }
    }
  }
  return m[1][n];
}

int main() {
  int n;
  scanf("%d", &n);
  int* p = (int*)malloc((n+1)*sizeof(int));
  int** m = (int**)malloc((n+1)*sizeof(int*));
  for(int i=0; i<=n; i++){
    m[i] = (int*)malloc((n+1)*sizeof(int));
  }
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &p[i], &p[i+1]);
  }
  int x = matrixChainOrder(p, m, n + 1);
  printf("%d\n", x);
  
  free(p);
  for(int i=0; i<=n; i++){
    free(m[i]);
  }
  free(m);

  return 0;
}