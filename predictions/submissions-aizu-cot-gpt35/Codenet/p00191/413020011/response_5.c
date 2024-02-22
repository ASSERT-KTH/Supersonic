#include <stdio.h>
#include <string.h>
#include <math.h>

#define REP(i, a, b) for (i = (a); i < (b); ++i)
#define rep(i, n) REP(i, 0, n)

double memo[101][101];
double solve(int n, int m, int p) {
  double res;
  int i;
  if (m == 1)
    return 1;
  if (memo[p][m] > 0)
    return memo[p][m];
  res = 0;
  rep(i, n) res = fmax(res, solve(n, m - 1, i) * memo[p][i]);
  return memo[p][m] = res;
}

int main(void) {
  int n, m, i, j;
  double res;
  while (scanf("%d%d", &n, &m), n | m) {
    memset(memo, 0, sizeof(memo));
    rep(i, n) rep(j, n) scanf("%lf", &memo[i][j]);
    res = 0;
    rep(i, n) res = fmax(res, solve(n, m, i));
    printf("%.2f\n", res);
  }
  return 0;
}