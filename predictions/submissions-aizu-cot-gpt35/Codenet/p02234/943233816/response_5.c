#include <iostream>
#include <limits.h>
#define MAX_SIZE 101

int m[MAX_SIZE][MAX_SIZE];
int p[MAX_SIZE];

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
        if (m[i][j] > q)
          m[i][j] = q;
      }
    }
  }
  
  return m[1][n];
}

int main() {
  int n, k;
  std::cin >> n;
  
  for (int i = 0; i < n; i++) {
    std::cin >> p[i];
    if (i < n - 1)
      std::cin >> k;
  }
  
  std::cin >> p[n];
  
  int result = matrixChainOrder(n + 1);
  std::cout << result << std::endl;
  
  return 0;
}