#include <stdio.h>
#include <string.h>
#define REP(i, a, b) for (int i = (a); i < (b); ++i)
#define MAX(a, b) ((a) > (b) ? (a) : (b))

double a[101][101];
double memo[101][101][101];

double solve(int n, int m, int p) {
  if (m == 1)
    return 1;
  if (memo[p][m][0] > 0)
    return memo[p][m][0];
    
  double res = 0;
  REP(i, 0, n) res = MAX(res, solve(n, m - 1, i) * a[p][i]);
  return memo[p][m][0] = res;
}

int main(void) {
  int n, m;
  double res;
  while (scanf("%d%d", &n, &m), n | m) {
    memset(memo, 0, sizeof(memo));
    REP(i, 0, n) REP(j, 0, n) scanf("%lf", &a[i][j]);
      
    res = 0;
    REP(i, 0, n) REP(j, 0, n) res = MAX(res, solve(n, m, i));
    printf("%.2f\n", res);
  }
  return 0;
}