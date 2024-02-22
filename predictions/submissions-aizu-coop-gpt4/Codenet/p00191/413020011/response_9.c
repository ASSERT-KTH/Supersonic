#include <stdio.h>
#include <string.h>
#define REP(i, a, b) for (i = (a); i < (b); ++i)
#define rep(i, n) REP(i, 0, n)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
double a[101][101];
double memo[101][101];

int main(void) {
  int n, m, i, j, k;
  double res;
  while (scanf("%d%d", &n, &m), n | m) {
    memset(memo, -1, sizeof(memo));
    rep(i, n) rep(j, n) scanf("%lf", &a[i][j]);

    // Base case: When m = 1, memo[i][1] = 1 for all i
    rep(i, n) memo[i][1] = 1;

    // Iterative dynamic programming
    for (int m = 2; m <= m; m++) {
      rep(i, n) {
        memo[i][m] = 0;
        rep(j, n) {
          memo[i][m] = MAX(memo[i][m], memo[j][m-1] * a[j][i]);
        }
      }
    }

    // Find the maximum result
    res = 0;
    rep(i, n) res = MAX(res, memo[i][m]);
    printf("%.2f\n", res);
  }
  return 0;
}