#include <iostream>
#include <vector>

int main() {
  int n, m;
  while (std::cin >> n >> m) {
    if (n == 0 && m == 0)
      break;

    std::vector<std::vector<double>> t(n, std::vector<double>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        std::cin >> t[i][j];
      }
    }

    std::vector<std::vector<double>> dp(m + 1, std::vector<double>(n, -1.0));
    dp[m][0] = 1.0;

    for (int times = m - 1; times >= 0; times--) {
      for (int prev = 0; prev < n; prev++) {
        for (int i = 0; i < n; i++) {
          if (times == 0) {
            dp[times][prev] = std::max(dp[times][prev], dp[times + 1][i]);
          } else {
            dp[times][prev] = std::max(dp[times][prev], dp[times + 1][i] * t[prev][i]);
          }
        }
      }
    }

    int result = static_cast<int>(dp[0][0] * 100);
    std::cout << result / 100 << "." << result % 100 << std::endl;
  }

  return 0;
}