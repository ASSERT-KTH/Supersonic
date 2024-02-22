#include <stdio.h>
#include <string.h>

#define REP(i, a, b) for (i = (a); i < (b); ++i)
#define rep(i, n) REP(i, 0, n)
#define MAX(a, b) ((a) > (b) ? (a) : (b))

double a[101][101];
double memo[101][101][101];

double solve(int n, int m, int p, int q) {
  if (m == 1)
    return 1;
  if (memo[p][m][q] > 0)
    return memo[p][m][q];
  double res = 0;
  for(int i = 0; i < n; i++) 
    res = MAX(res, solve(n, m - 1, q, i) * a[p][i]);
  return memo[p][m][q] = res;
}

int main(void) {
  int n, m;
  double res;
  while (scanf("%d%d", &n, &m) == 2) {
    memset(memo, 0, sizeof(memo));
    rep(i, n) rep(j, n) scanf("%lf", &a[i][j]);
    res = 0;
    rep(i, n) rep(j, n) {
      double temp = solve(n, m, i, j);
      res = MAX(res, temp);
    }
    printf("%.2f\n", res);
  }
  return 0;
}