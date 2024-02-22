#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int matrixChainOrder(int* p, int pl) {
  int n = pl - 1;

  // Dynamically allocate m array based on the actual size of matrices
  int** m = (int**)malloc(sizeof(int*) * n);
  for (int i = 0; i < n; i++) {
    m[i] = (int*)malloc(sizeof(int) * n);
  }

  // Initialize m array with 0s
  for (int i = 1; i < n; i++) {
    m[i][i] = 0;
  }

  for (int l = 2; l < n; l++) {
    for (int i = 1; i < n - l + 1; i++) {
      int j = i + l - 1;
      m[i][j] = INT_MAX;
      for (int k = i; k < j; k++) {
        int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
        if (m[i][j] > q) {
          m[i][j] = q;
        }
      }
    }
  }

  int minMultiplications = m[1][n - 1];

  // Free dynamically allocated memory
  for (int i = 0; i < n; i++) {
    free(m[i]);
  }
  free(m);

  return minMultiplications;
}

int main() {
  int n;
  scanf("%d", &n);

  int* p = (int*)malloc(sizeof(int) * (n + 1));

  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
    if (i < n - 1) {
      int k;
      scanf("%d", &k);
    }
  }
  scanf("%d", &p[n]);

  int minMultiplications = matrixChainOrder(p, n + 1);
  printf("%d\n", minMultiplications);

  free(p);

  return 0;
}