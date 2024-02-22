#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

double solve(int times, int prev, int n, int m, double dp[][101], double t[][101]) {
  if (dp[times][prev] != -1)
    return dp[times][prev];
  if (times == m)
    return dp[times][prev] = 1;
  double tmp = -1;
  for (int i = 0; i < n; i++) {
    if (times == 0) {
      tmp = max(tmp, solve(times + 1, i, n, m, dp, t));
    } else {
      tmp = max(tmp, solve(times + 1, i, n, m, dp, t) * t[prev][i]);
    }
  }
  return dp[times][prev] = tmp;
}

int main(void) {
  int n, m;
  while (scanf("%d %d", &n, &m) != EOF) {
    if (!(n | m)) break;
    double dp[101][101];
    double t[101][101];
    fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(double), -1);
    double retd;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        scanf("%lf", &t[i][j]);
      }
    }
    retd = solve(0, 0, n, m, dp, t) * 100;
    printf("%.2lf\n", round(retd) / 100);
  }
  return 0;
}