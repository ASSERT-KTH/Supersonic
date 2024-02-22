#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
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
  if (times == 0) {
    for (int i = 0; i < n; i++) {
      tmp = max(tmp, solve(times + 1, i));
    }
  } else {
    for (int i = 0; i < n; i++) {
      tmp = max(tmp, solve(times + 1, i) * t[prev][i]);
    }
  }
  return dp[times][prev] = tmp;
}
int main(void) {
  while (cin >> n >> m) {
    if (!(n | m))
      break;
    fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(double), -1);
    int ret;
    double retd;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> t[i][j];
      }
    }
    retd = solve(0, 0) * 100;
    printf("%.2lf\n", retd);
  }
}