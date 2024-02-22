#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  int n, m;
  while (cin >> n >> m) {
    if (!(n | m))
      break;
    vector<vector<double>> dp(m+1, vector<double>(n, -1));
    vector<vector<double>> t(n, vector<double>(n));
    double retd;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> t[i][j];
      }
    }
    for (int i = 0; i < n; i++)
      dp[m][i] = 1;
    for (int times = m - 1; times >= 0; times--) {
      for (int prev = 0; prev < n; prev++) {
        for (int i = 0; i < n; i++) {
          if (times == 0) {
            dp[times][prev] = max(dp[times][prev], dp[times + 1][i]);
          } else {
            dp[times][prev] = max(dp[times][prev], dp[times + 1][i] * t[prev][i]);
          }
        }
      }
    }
    retd = dp[0][0] * 100;
    printf("%.2lf\n", round(retd) / 100);
  }
}