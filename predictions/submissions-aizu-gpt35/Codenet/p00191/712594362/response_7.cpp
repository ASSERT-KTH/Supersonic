#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN = 101;
int n, m;
double dp[MAXN][MAXN];
double t[MAXN][MAXN];
double solve(int times, int prev) {
  if (dp[times][prev] != -1)
    return dp[times][prev];
  if (times == m)
    return dp[times][prev] = 1;
  double tmp = -1;
  for (int i = 0; i < n; i++) {
    if (times == 0) {
      tmp = max(tmp, solve(times + 1, i) * 1);
    } else {
      tmp = max(tmp, solve(times + 1, i) * t[prev][i]);
    }
  }
  return dp[times][prev] = tmp;
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  while (cin >> n >> m) {
    if (!(n | m))
      break;
    fill(&dp[0][0], &dp[MAXN - 1][MAXN - 1] + 1, -1);
    double retd;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> t[i][j];
      }
    }
    retd = solve(0, 0) * 100;
    printf("%.2lf\n", round(retd) / 100);
  }
}