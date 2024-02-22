#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

const int MAX_N = 101;

int n, m;
double dp[MAX_N][MAX_N];
double t[MAX_N][MAX_N];

double calculate(int n, int m) {
  double dp[MAX_N][MAX_N];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      dp[i][j] = -1;
    }
  }

  for (int times = m; times >= 0; times--) {
    for (int prev = 0; prev < n; prev++) {
      if (times == m) {
        dp[times][prev] = 1;
      } else {
        double tmp = -1;
        for (int i = 0; i < n; i++) {
          if (times == 0) {
            tmp = max(tmp, dp[times + 1][i] * 1);
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
  while (cin >> n >> m) {
    if (!(n | m))
      break;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> t[i][j];
      }
    }
    double result = calculate(n, m) * 100;
    printf("%.2lf\n", round(result) / 100);
  }
}