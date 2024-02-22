#include <stdio.h>
#include <string.h>

#define REP(i, a, b) for (i = (a); i < (b); ++i)
#define rep(i, n) REP(i, 0, n)
#define MAX(a, b) ((a) > (b) ? (a) : (b))

double a[101][101];

double solve(int n, int m) {
  double dp[101][101];
  memset(dp, 0, sizeof(dp));
  
  int i, j, k;
  REP(i, 1, n + 1) dp[i][1] = 1;
  
  REP(j, 2, m + 1) {
    REP(i, 1, n + 1) {
      REP(k, 1, i) {
        dp[i][j] = MAX(dp[i][j], dp[k][j - 1] * a[k][i]);
      }
    }
  }
  
  double res = 0;
  REP(i, 1, n + 1) {
    res = MAX(res, dp[i][m]);
  }
  
  return res;
}

int main(void) {
  int n, m, i, j;
  while (scanf("%d%d", &n, &m), n | m) {
    memset(a, 0, sizeof(a));
    rep(i, n) rep(j, n) scanf("%lf", &a[i][j]);
    printf("%.2f\n", solve(n, m));
  }
  return 0;
}