#include <stdio.h>
#define REP(i, a, b) for (i = (a); i < (b); ++i)
#define rep(i, n) REP(i, 0, n)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
double a[101][101];
double memo[101][101];

double solve(int n, int m, int p) {
  double res;
  int i;
  if (m == 1)
    return 1;
  if (memo[m][p] > 0)
    return memo[m][p];
  res = 0;
  rep(i, n) res = MAX(res, solve(n, m - 1, i) * a[p][i]);
  return memo[m][p] = res;
}

int main(void) {
  int n, m, i, j;
  double res;
  while (scanf("%d%d", &n, &m), n | m) {
    rep(i, n) rep(j, n) scanf("%lf", &a[i][j]);
    res = 0;
    rep(i, n) res = MAX(res, solve(n, m, i));
    printf("%.2f\n", res);
  }
  return 0;
}