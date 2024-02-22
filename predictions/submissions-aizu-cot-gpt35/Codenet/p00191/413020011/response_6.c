#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

double** a;
bool*** memo;
double* maxWeight;

double solve(int n, int m, int p) {
  double res;
  int i;
  if (m == 1)
    return 1;
  if (memo[p][m][n])
    return memo[p][m][n];
  res = 0;
  for (i = 0; i < n; ++i)
    res = fmax(res, solve(n, m - 1, i) * a[p][i]);
  return memo[p][m][n] = res;
}

int main(void) {
  int n, m, i, j;
  double res;
  while (scanf("%d%d", &n, &m), n | m) {
    a = (double**)malloc(n * sizeof(double*));
    for (i = 0; i < n; ++i)
      a[i] = (double*)malloc(n * sizeof(double));
    memo = (bool***)malloc(n * sizeof(bool**));
    for (i = 0; i < n; ++i) {
      memo[i] = (bool**)malloc((m + 1) * sizeof(bool*));
      for (j = 0; j <= m; ++j)
        memo[i][j] = (bool*)calloc(n + 1, sizeof(bool));
    }
    maxWeight = (double*)malloc(n * sizeof(double));
    for (i = 0; i < n; ++i) {
      maxWeight[i] = 0;
      for (j = 0; j < n; ++j)
        maxWeight[i] = fmax(maxWeight[i], a[i][j]);
    }
    for (i = 0; i < n; ++i)
      for (j = 0; j < n; ++j)
        scanf("%lf", &a[i][j]);
    res = 0;
    for (i = 0; i < n; ++i)
      for (j = 0; j < n; ++j)
        res = fmax(res, solve(n, m, i) * a[j][i]);
    printf("%.2f\n", res);
    for (i = 0; i < n; ++i) {
      free(a[i]);
      for (j = 0; j <= m; ++j)
        free(memo[i][j]);
      free(memo[i]);
    }
    free(a);
    for (i = 0; i < n; ++i)
      free(memo[i]);
    free(memo);
    free(maxWeight);
  }
  return 0;
}