#include <stdio.h>
#include <limits.h>
#define MAX_SIZE 101

int m[MAX_SIZE][MAX_SIZE];
int p[MAX_SIZE];
int computed[MAX_SIZE][MAX_SIZE];

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
        if (computed[i][k] == 0) {
          computed[i][k] = matrixChainOrder(k + 1);
        }
        if (computed[k + 1][j] == 0) {
          computed[k + 1][j] = matrixChainOrder(j + 1);
        }
        
        int q = computed[i][k] + computed[k + 1][j] + p[i - 1] * p[k] * p[j];
        if (m[i][j] > q) {
          m[i][j] = q;
        }
      }
    }
  }
  
  return m[1][n];
}

int main() {
  int n, i, x, k;
  scanf("%d", &n);
  
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