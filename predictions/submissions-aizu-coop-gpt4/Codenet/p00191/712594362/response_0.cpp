#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<double>> dp;
vector<vector<double>> t;

double solve(int n, int m) {
  for (int times = m; times >= 0; times--) {
    for (int prev = 0; prev < n; prev++) {
      if (times == m)
        dp[times][prev] = 1;
      else {
        double tmp = -1;
        for (int i = 0; i < n; i++) {
          if (times == 0) {
            tmp = max(tmp, dp[times + 1][i]);
          } else {
            tmp = max(tmp, dp[times + 1][i] * t[prev][i]);
          }
        }
        dp[times][prev] = tmp;
      }
    }
  }
  return dp[0][0];
}

int main(void) {
  int n, m;
  while (cin >> n >> m) {
    if (!(n | m))
      break;
    dp = vector<vector<double>>(m + 1, vector<double>(n, -1));
    t = vector<vector<double>>(n, vector<double>(n));
    double retd;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> t[i][j];
      }
    }
    retd = solve(n, m) * 100;
    printf("%.2lf\n", round(retd) / 100);
  }
}