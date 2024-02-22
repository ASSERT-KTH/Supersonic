#include <stdio.h>
#include <string.h>
#define REP(i, a, b) for (i = (a); i < (b); ++i)
#define rep(i, n) REP(i, 0, n)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
double a[101][101];
double dp[101][101];

double solve(int n, int m) {
  int i, j, k;
  for(i=0; i<n; i++) dp[i][1] = 1;
  for(i=2; i<=m; i++)
    for(j=0; j<n; j++)
      for(k=0; k<n; k++)
        dp[j][i] = MAX(dp[j][i], dp[k][i-1] * a[k][j]);
  double res = 0;
  for(i=0; i<n; i++) res = MAX(res, dp[i][m]);
  return res;
}

int main(void) {
  int n, m, i, j, k;
  double res;
  while (scanf("%d%d", &n, &m), n | m) {
    memset(dp, 0, sizeof(dp));
    rep(i, n) rep(j, n) scanf("%lf", &a[i][j]);
    res = solve(n, m);
    printf("%.2f\n", res);
  }
  return 0;
}