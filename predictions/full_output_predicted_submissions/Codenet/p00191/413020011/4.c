#include <stdio.h>
#include <string.h>
#define REP(i, a, b) for (i = (a); i < (b); ++i)
#define rep(i, n) REP(i, 0, n)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
double a[101][101];
double memo[101][101][101];
double solve(int n, int m, int k, int p) {
  double res;
  int i, j;
  if (m == 1)
    return 1;
  if (memo[p][m][k] > 0)
    return memo[p][m][k];
  res = 0;
  rep(i, n) res = MAX(res, solve(n, m - 1, p, i) * a[p][i]);
  return memo[p][m][k] = res;
}
int main(void) {
  int n, m, i, j, k;
  double res;
  while (scanf("%d%d", &n, &m), n | m) {
    memset(memo, 0, sizeof(memo));
    rep(i, n) rep(j, n) scanf("%lf", &a[i][j]);
    rep(i, n) rep(j, n) res = MAX(res, solve(n, m, i, j));
    printf("%.2f\n", res);
  }
  return 0;
}
