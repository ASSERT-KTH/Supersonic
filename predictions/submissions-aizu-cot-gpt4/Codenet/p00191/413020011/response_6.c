#include <iostream>
#include <string.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
double a[101][101];
double memo[101][101][101];
double solve(int n, int m, int k, int p) {
  double res;
  int i;
  if (m == 1)
    return 1;
  if (memo[p][m][k] > 0)
    return memo[p][m][k];
  res = 0;
  for(i=0;i<n;i++) res = MAX(res, solve(n, m - 1, p, i) * a[p][i]);
  return memo[p][m][k] = res;
}
int main(void) {
  int n, m, i, j, k;
  double res;
  while (std::cin >> n >> m, n | m) {
    memset(memo, 0, sizeof(memo));
    for(i=0;i<n;i++) for(j=0;j<n;j++) std::cin >> a[i][j];
    res = 0;
    for(i=0;i<n;i++) for(j=0;j<n;j++) res = MAX(res, solve(n, m, i, j));
    std::cout << res << "\n";
  }
  return 0;
}