#include <stdio.h>
#include <string.h>
#define REP(i, a, b) for (i = (a); i < (b); ++i)
#define rep(i, n) REP(i, 0, n)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
double a[101][101];
double memo[101][101][101];

void solve(int n, int m) {
  int p, i, j;
  rep(i, n) rep(j, m+1) rep(p, n) memo[i][j][p] = -1;
  rep(i, n) memo[i][1][0] = 1;
  REP(j, 2, m+1) rep(i, n) rep(p, n) if (memo[i][j-1][p] != -1) memo[i][j][p] = MAX(memo[i][j][p], memo[i][j-1][p] * a[p][i]);
}

int main(void) {
  int n, m, i, j;
  double res;
  while (scanf("%d%d", &n, &m), n | m) {
    rep(i, n) rep(j, n) scanf("%lf", &a[i][j]);
    solve(n, m);
    res = 0;
    rep(i, n) rep(j, n) res = MAX(res, memo[i][m][j]);
    printf("%.2f\n", res);
  }
  return 0;
}