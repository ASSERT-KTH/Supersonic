#include <stdio.h>
#include <limits.h>

int matrixChainOrder(int* p, int n) {
  int m[n][n];

  // Initialize the diagonal elements to 0
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

  return m[1][n - 1];
}

int main() {
  int n;
  printf("Enter the number of matrices: ");
  scanf("%d", &n);

  int p[n];
  printf("Enter the dimensions of matrices: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
  }

  int minCost = matrixChainOrder(p, n);

  printf("Minimum cost of matrix multiplication: %d\n", minCost);

  return 0;
}