#include <stdio.h>
#include <string.h>

#define MAX_SIZE 101

double a[MAX_SIZE][MAX_SIZE];
double memo[MAX_SIZE][MAX_SIZE];

double solve(int n, int m, int p) {
  if (m == 1)
    return 1;
  if (memo[p][m] > -1)
    return memo[p][m];
  double res = 0;
  for (int i = 0; i < n; ++i)
    res = fmax(res, solve(n, m - 1, i) * a[p][i]);
  return memo[p][m] = res;
}

int main(void) {
  int n, m;
  while (scanf("%d%d", &n, &m), n | m) {
    memset(memo, -1, sizeof(memo));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        scanf("%lf", &a[i][j]);
    double res = 0;
    for (int i = 0; i < n; ++i)
      res = fmax(res, solve(n, m, i));
    printf("%.2f\n", res);
  }
  return 0;
}