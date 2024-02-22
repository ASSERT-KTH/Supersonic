#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int n, m;
double dp[101];
double t[101][101];

double solve(int times, int prev) {
  if (dp[times] != -1)
    return dp[times];

  if (times == m)
    return dp[times] = 1;

  double tmp = -1;

  for (int i = 0; i < n; i++) {
    double val = (times == 0) ? 1 : t[prev][i];
    tmp = max(tmp, solve(times + 1, i) * val);
  }

  return dp[times] = tmp;
}

int main(void) {
  while (cin >> n >> m) {
    if (!(n | m))
      break;

    fill(dp, dp + 101, -1);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> t[i][j];
      }
    }

    double retd = solve(0, 0) * 100;
    printf("%.2lf\n", round(retd) / 100);
  }
}