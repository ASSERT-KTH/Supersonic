#include <stdio.h>
#include <cstring>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

double a[101][101];
double memo[101][101][101];

double solve(int n, int m, int p) {
  if (m == 1)
    return 1;
  if (memo[p][m][0] > 0)
    return memo[p][m][0];

  double res = 0;
  for (int i = 0; i < n; ++i) {
    res = MAX(res, solve(n, m - 1, i) * a[p][i]);
  }
  
  return memo[p][m][0] = res;
}

int main(void) {
  int n, m;
  double res;

  while (scanf("%d%d", &n, &m), n | m) {
    memset(memo, 0, sizeof(memo));
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        scanf("%lf", &a[i][j]);
      }
    }

    res = 0;
    for(int i = 0; i < n; ++i) {
      res = MAX(res, solve(n, m, i));
    }
    printf("%.2f\n", res);
  }

  return 0;
}