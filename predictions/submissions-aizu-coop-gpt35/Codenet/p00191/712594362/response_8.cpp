#include <cstdio>
#include <iostream>

int n, m;
double dp[2][101];
double t[101][101];

int main(void) {
  while (std::cin >> n >> m) {
    if (!(n | m))
      break;

    // Optimization step 3: Optimize memory usage
    std::fill(dp[0], dp[0] + 101, -1);
    std::fill(dp[1], dp[1] + 101, -1);

    double retd;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        std::cin >> t[i][j];
      }
    }

    // Optimization step 5: Use a bottom-up approach
    for (int i = 0; i < n; i++) {
      dp[0][i] = 1.0;
    }

    for (int times = 1; times <= m; times++) {
      for (int prev = 0; prev < n; prev++) {
        double tmp = -1;
        for (int i = 0; i < n; i++) {
          if (times == 1) {
            tmp = std::max(tmp, dp[0][i] * t[prev][i]);
          } else {
            tmp = std::max(tmp, dp[1][i] * t[prev][i]);
          }
        }
        dp[times % 2][prev] = tmp;
      }
    }

    retd = dp[m % 2][0] * 100;
    std::printf("%.2lf\n", std::round(retd) / 100);
  }
}