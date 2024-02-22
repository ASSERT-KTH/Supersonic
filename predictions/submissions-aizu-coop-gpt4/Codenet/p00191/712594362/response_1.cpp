#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
int n, m;
double dp[101][101];
double t[101][101];

double solve() {
  dp[0][0] = 1;
  for (int times = 1; times <= m; times++) {
    for (int prev = 0; prev < n; prev++) {
      double tmp = -1;
      for (int i = 0; i < n; i++) {
        tmp = max(tmp, dp[times - 1][i] * t[i][prev]);
      }
      dp[times][prev] = tmp;
    }
  }
  return *max_element(dp[m], dp[m] + n);
}

int main(void) {
  while (cin >> n >> m) {
    if (!(n | m))
      break;
    fill((double *)dp, (double *)dp + 101 * 101, -1);
    int ret;
    double retd;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> t[i][j];
      }
    }
    retd = solve() * 100;
    printf("%.2lf\n", round(retd) / 100);
  }
}