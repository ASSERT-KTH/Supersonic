#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
int n, m;
double dp[101][101];
double t[101][101];

double solve(int times, int prev) {
  if (dp[times][prev] != -1)
    return dp[times][prev];
  if (times == m)
    return dp[times][prev] = 1;
  double tmp = -1;
  for (int i = 0; i < n; i++) {
    tmp = max(tmp, solve(times + 1, i) * (times == 0 ? 1 : t[prev][i]));
  }
  return dp[times][prev] = tmp;
}

int main(void) {
  fill((double *)dp, (double *)dp + 101 * 101, -1);
  while (scanf("%d %d", &n, &m), n | m) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        scanf("%lf", &t[i][j]);
      }
    }
    double retd = solve(0, 0) * 100;
    printf("%.2lf\n", round(retd) / 100);
  }
}