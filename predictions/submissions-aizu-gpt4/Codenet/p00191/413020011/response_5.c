#include <stdio.h>
#include <string.h>
#define REP(i, a, b) for (i = (a); i < (b); ++i)
#define rep(i, n) REP(i, 0, n)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
double a[101][101];
double memo[101][101][101];
double solve(int n, int m, int p, int i) {
  double res;
  if (m == 1)
    return 1;
  if (memo[p][m][i] > 0)
    return memo[p][m][i];
  res = 0;
  REP(i, 0, n) res = MAX(res, solve(n, m - 1, i, p) * a[p][i]);
  return memo[p][m][i] = res;
}
int main(void) {
  int n, m, i, j;
  double res;
  while (scanf("%d%d", &n, &m), n | m) {
    memset(memo, 0, sizeof(memo));
    REP(i, 0, n) REP(j, 0, n) scanf("%lf", &a[i][j]);
    res = 0;
    REP(i, 0, n) REP(j, 0, n) res = MAX(res, solve(n, m, i, j));
    printf("%.2f\n", res);
  }
  return 0;
}