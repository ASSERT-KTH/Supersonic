#include <algorithm>
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
  while (scanf("%d %d", &n, &m), n | m) {
    fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(double), -1);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        scanf("%lf", &t[i][j]);
      }
    }
    printf("%.2lf\n", solve(0, 0) * 100);
  }
}