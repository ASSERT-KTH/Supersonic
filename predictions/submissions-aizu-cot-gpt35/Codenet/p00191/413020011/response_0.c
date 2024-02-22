#include <stdio.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

double a[101][101];
double memo[101][101];

double solve(int n, int m, int k) {
  double res = 0;
  
  if (m == 1)
    return 1;
  
  if (memo[m][k] > 0)
    return memo[m][k];
  
  for (int i = 0; i < n; ++i) {
    res = MAX(res, solve(n, m - 1, i) * a[k][i]);
  }
  
  return memo[m][k] = res;
}

int main(void) {
  int n, m;
  
  while (scanf("%d%d", &n, &m), n | m) {
    memset(memo, 0, sizeof(memo));
    
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        scanf("%lf", &a[i][j]);
      }
    }
    
    double res = 0;
    
    for (int i = 0; i < n; ++i) {
      res = MAX(res, solve(n, m, i));
    }
    
    printf("%.2f\n", res);
  }
  
  return 0;
}