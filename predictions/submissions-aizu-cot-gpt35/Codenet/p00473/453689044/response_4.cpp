#include <cstdio>
#include <algorithm>

int n;
int t[10002];
int dp[5002][2];

int solve() {
  dp[1][0] = dp[0][1] = 0;
  for (int i = 1; i < n; i++) {
    std::swap(dp[0][0], dp[1][0]);
    std::swap(dp[0][1], dp[1][1]);

    dp[1][0] = dp[0][0];
    dp[1][1] = dp[0][1];

    for (int j = 0; j <= n / 2; j++) {
      for (int pre = 0; pre < 2; pre++) {
        int next = 1 - pre;

        if (dp[j][pre] == -1)
          continue;

        if (pre == next) {
          if (next == 0)
            dp[j + 1][next] = std::min(dp[j + 1][next], dp[j][pre]);
          else
            dp[j][next] = std::min(dp[j][next], dp[j][pre]);
        } else {
          if (next == 0)
            dp[j + 1][next] = std::min(dp[j + 1][next], dp[j][pre] + t[i - 1]);
          else
            dp[j][next] = std::min(dp[j][next], dp[j][pre] + t[i - 1]);
        }
      }
    }
  }
  return std::min(dp[n / 2][0], dp[n / 2][1]);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d", &t[i]);
  }
  printf("%d\n", solve());
}