#include <iostream>
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
  double next;

  for (int i = 0; i < n; i++) {
    next = solve(times + 1, i);

    if (times == 0) {
      tmp = max(tmp, next * 1);
    } else {
      tmp = max(tmp, next * t[prev][i]);
    }
  }

  return dp[times][prev] = tmp;
}

int main(void) {
  while (cin >> n >> m) {
    if (!(n | m))
      break;

    fill(dp[0], dp[0] + 101 * 101, -1);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> t[i][j];
      }
    }

    double retd = solve(0, 0) * 100;
    printf("%.2lf\n", round(retd) / 100);
  }
}