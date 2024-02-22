#include <stdio.h>
#include <string.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
double a[101][101];
double memo[101][101][101] = {0};

void calculate(int n, int m) {
  int i, j, k, p;
  for (p = 0; p < n; ++p)
    for (k = 1; k < m; ++k)
      for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
          memo[p][k][j] = MAX(memo[p][k][j], memo[i][k - 1][p] * a[p][i]);
}

int main(void) {
  int n, m, i, j;
  double res;
  while (scanf("%d%d", &n, &m), n | m) {
    for (i = 0; i < n; ++i) for (j = 0; j < n; ++j) scanf("%lf", &a[i][j]);
    calculate(n, m);
    res = 0;
    for (i = 0; i < n; ++i) for (j = 0; j < n; ++j) res = MAX(res, memo[i][m - 1][j]);
    printf("%.2f\n", res);
  }
  return 0;
}