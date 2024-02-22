#include <iostream>

int solve() {
  const int MAX_N = 5002;
  const int MAX_T = 10001;

  int n;
  std::cin >> n;

  int t[MAX_T];
  for (int i = 0; i < n - 1; i++) {
    std::cin >> t[i];
  }

  int dp[MAX_N][2] = {0};
  int tmp[MAX_N][2] = {0};

  tmp[1][0] = tmp[0][1] = 0;
  for (int i = 1; i < n; i++) {
    std::swap(dp, tmp);
    for (int j = 0; j <= n / 2; j++) {
      for (int pre = 0; pre < 2; pre++) {
        for (int next = 0; next < 2; next++) {
          if (pre == next) {
            if (next == 0)
              dp[j + 1][next] = std::min(dp[j + 1][next], tmp[j][pre]);
            else
              dp[j][next] = std::min(dp[j][next], tmp[j][pre]);
          } else {
            if (next == 0)
              dp[j + 1][next] = std::min(dp[j + 1][next], tmp[j][pre] + t[i - 1]);
            else
              dp[j][next] = std::min(dp[j][next], tmp[j][pre] + t[i - 1]);
          }
        }
      }
    }
  }
  return std::min(dp[n / 2][0], dp[n / 2][1]);
}

int main() {
  std::cout << solve() << std::endl;
  return 0;
}