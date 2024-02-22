#include <stdio.h>
#include <string.h>

double a[101 * 101];  // Use a 1D array instead of a 2D array

double solve(int n, int m, int p) {
  double memo[101];  // Use a 1D array instead of a 3D array
  double res = 0;
  
  for (int i = 0; i < n; ++i) {
    memo[i] = 1.0;
  }
  
  for (int j = 0; j < m - 1; ++j) {
    for (int i = 0; i < n; ++i) {
      double max_val = 0;
      for (int k = 0; k < n; ++k) {
        max_val = MAX(max_val, memo[k] * a[i * n + k]);
      }
      memo[i] = max_val;
    }
  }
  
  for (int i = 0; i < n; ++i) {
    res = MAX(res, memo[i]);
  }
  
  return res;
}

int main(void) {
  int n, m;
  double res;
  
  while (scanf("%d%d", &n, &m), n | m) {
    memset(a, 0, sizeof(a));
    
    for (int i = 0; i < n * n; ++i) {
      scanf("%lf", &a[i]);
    }
    
    res = solve(n, m, 0);
    
    printf("%.2f\n", res);
  }
  
  return 0;
}