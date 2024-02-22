#include <stdio.h>
#include <stdlib.h>
#define INF 100000000

int matrixChainOrder(int pl, int *p) {
  int n = pl - 1;
  int m[n+1][n+1];

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

int main(int argc, char *argv[]) {
  int n = argc - 1;
  int *p = malloc(n * sizeof(int));
  
  for (int i = 0; i < n; i++) {
    p[i] = atoi(argv[i + 1]);
  }
  
  int result = matrixChainOrder(n + 1, p);
  printf("%d\n", result);
  
  free(p);
  
  return 0;
}