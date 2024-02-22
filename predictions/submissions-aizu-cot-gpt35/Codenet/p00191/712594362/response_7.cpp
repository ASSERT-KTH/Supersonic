#include <cstdio>
#include <iostream>

const int MAX_N = 101;

int n, m;
int t[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

int solve() {
  for (int times = 0; times <= m; times++) {
    for (int prev = 0; prev < n; prev++) {
      if (times == 0) {
        dp[times][prev] = 1;
      } else {
        int tmp = 0;
        for (int i = 0; i < n; i++) {
          tmp = std::max(tmp, dp[times - 1][i] * t[i][prev]);
        }
        dp[times][prev] = tmp;
      }
    }
  }
  return dp[m][0];
}

int main(void) {
  while (std::cin >> n >> m) {
    if (!(n | m))
      break;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        std::cin >> t[i][j];
      }
    }

    int result = solve() * 100;
    std::printf("%.2lf\n", result / 100.0);
  }
}