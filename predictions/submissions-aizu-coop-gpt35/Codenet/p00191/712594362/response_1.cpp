#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int n, m;
double** dp;
double** t;

double solve(int times, int prev) {
  if (dp[times][prev] != -1)
    return dp[times][prev];

  if (times == m)
    return dp[times][prev] = 1;

  double tmp = -1;

  if (times == 0) {
    for (int i = 0; i < n; i++) {
      tmp = max(tmp, solve(times + 1, i) * 1);
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

    // Allocate memory for dp and t arrays
    dp = new double*[m + 1];
    t = new double*[n];
    for (int i = 0; i <= m; i++) {
      dp[i] = new double[n];
      fill(dp[i], dp[i] + n, -1);
    }
    for (int i = 0; i < n; i++) {
      t[i] = new double[n];
    }

    int ret;
    double retd;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> t[i][j];
      }
    }

    retd = solve(0, 0) * 100;
    printf("%.2lf\n", round(retd) / 100);

    // Free memory for dp and t arrays
    for (int i = 0; i <= m; i++) {
      delete[] dp[i];
    }
    delete[] dp;
    for (int i = 0; i < n; i++) {
      delete[] t[i];
    }
    delete[] t;
  }
}