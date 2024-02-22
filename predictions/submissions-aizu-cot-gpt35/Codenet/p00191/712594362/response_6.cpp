#include <iostream>
#include <iomanip>
#include <cstring>

const int MAX_N = 101;

int n, m;
double dp[MAX_N][MAX_N];
double t[MAX_N][MAX_N];

double solve() {
  memset(dp, 0, sizeof(dp));

  for (int times = m; times >= 0; times--) {
    for (int prev = 0; prev < n; prev++) {
      if (times == m) {
        dp[times][prev] = 1;
      } else {
        double tmp = 0;
        for (int i = 0; i < n; i++) {
          tmp = std::max(tmp, dp[times + 1][i] * t[prev][i]);
        }
        dp[times][prev] = tmp;
      }
    }
  }

  return dp[0][0];
}

int main() {
  while (std::cin >> n >> m && (n || m)) {
    memset(t, 0, sizeof(t));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        std::cin >> t[i][j];
      }
    }

    double result = solve() * 100;
    std::cout << std::fixed << std::setprecision(2) << round(result) / 100 << std::endl;
  }

  return 0;
}