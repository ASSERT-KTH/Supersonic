#include <stdio.h>
#include <string.h>
#define REP(i, a, b) for (i = (a); i < (b); ++i)
#define rep(i, n) REP(i, 0, n)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
double a[101][101];
double dp[101][101][101];

double solve(int n, int m) {
  int i, j, k, p;
  rep(i, n) dp[i][1][i] = 1;
  REP(k, 2, m+1) {
    rep(i, n) {
      rep(j, n) {
        rep(p, n) dp[i][k][j] = MAX(dp[i][k][j], dp[p][k-1][i] * a[j][p]);
      }
    }
  }
}

int main(void) {
  int n, m, i, j, k;
  double res;
  while (scanf("%d%d", &n, &m), n | m) {
    memset(dp, 0, sizeof(dp));
    rep(i, n) rep(j, n) scanf("%lf", &a[i][j]);
    solve(n, m);
    res = 0;
    rep(i, n) rep(j, n) res = MAX(res, dp[i][m][j]);
    printf("%.2f\n", res);
  }
  return 0;
}