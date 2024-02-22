#include <stdio.h>
#include <string.h>

#define MAX_N 101

double a[MAX_N][MAX_N];
double memo[MAX_N][MAX_N];
int max_i[MAX_N];

double solve(int n, int m, int p, int max_i_p) {
  if (m == 1)
    return 1;
  if (memo[p][m] > 0)
    return memo[p][m];
  double res = 0;
  for (int i = 0; i < max_i_p; ++i)
    res = fmax(res, solve(n, m - 1, p, i) * a[p][i]);
  return memo[p][m] = res;
}

int main(void) {
  int n, m;
  while (scanf("%d%d", &n, &m), n | m) {
    memset(memo, 0, sizeof(memo));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        scanf("%lf", &a[i][j]);
      }
      max_i[i] = i; // Initialize max_i with the maximum possible value of i
    }
    double res = 0;
    for (int i = 0; i < n; ++i) {
      res = fmax(res, solve(n, m, i, max_i[i]));
      for (int j = 0; j < n; ++j) {
        if (a[i][j] > a[i][max_i[i]]) {
          max_i[i] = j; // Update max_i if a higher probability is found
        }
      }
    }
    printf("%.2f\n", res);
  }
  return 0;
}