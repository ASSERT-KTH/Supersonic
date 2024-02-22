#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int main(void) {
  int n, m;
  while (cin >> n >> m) {
    if (!(n | m)) break;
    double dp[101][101] = {0};
    double t[101][101];
    int ret;
    double retd;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> t[i][j];
      }
    }
    // Initialize dp array
    for (int i = 0; i < n; i++) {
      dp[m][i] = 1;
    }
    // Bottom-up DP
    for (int times = m - 1; times >= 0; times--) {
      for (int prev = 0; prev < n; prev++) {
        double tmp = -1;
        for (int i = 0; i < n; i++) {
          tmp = max(tmp, dp[times + 1][i] * t[prev][i]);
        }
        dp[times][prev] = tmp;
      }
    }
    retd = dp[0][0] * 100;
    printf("%.2lf\n", round(retd) / 100);
  }
}