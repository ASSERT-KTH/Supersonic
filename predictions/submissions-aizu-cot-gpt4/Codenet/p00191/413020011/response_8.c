#include <stdio.h>
#include <string.h>
#include <cmath>
#define REP(i, a, b) for (i = (a); i < (b); ++i)
#define rep(i, n) REP(i, 0, n)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
double a[101][101];
double memo[101][101];
double epsilon = 1e-9;

double solve(int n, int m, int p) {
  double res;
  int i;
  if (m == 1)
    return 1;
  if (!isnan(memo[p][m]))
    return memo[p][m];
  res = 0;
  rep(i, n) res = MAX(res, solve(n, m - 1, i) * a[p][i]);
  return memo[p][m] = res;
}

int main(void) {
  int n, m, i, j;
  double res;
  while (scanf("%d%d", &n, &m), n | m) {
    for(i = 0; i < 101; i++)
      for(j = 0; j < 101; j++)
        memo[i][j] = NAN;
    rep(i, n) rep(j, n) scanf("%lf", &a[i][j]);
    res = 0;
    rep(i, n) rep(j, n) res = MAX(res, solve(n, m, i));
    printf("%.2f\n", res);
  }
  return 0;
}