#include <cstdio>
#include <cstring>

int solve(int n) {
  int t[10002];
  int dp[n/2+1][2];
  int tmp[n/2+1][2];

  memset(tmp, -1, sizeof(tmp));
  tmp[1][0] = tmp[0][1] = 0;

  for (int i = 1; i < n; i++) {
    memset(dp, -1, sizeof(dp));

    for (int j = 0; j <= n / 2; j++) {
      for (int pre = 0; pre < 2; pre++) {
        if (tmp[j][pre] == -1)
          continue;

        for (int next = 0; next < 2; next++) {
          if (pre == next) {
            if (next == 0)
              dp[j + 1][next] = dp[j + 1][next] == -1 ? tmp[j][pre] : (tmp[j][pre] < dp[j + 1][next] ? tmp[j][pre] : dp[j + 1][next]);
            else
              dp[j][next] = dp[j][next] == -1 ? tmp[j][pre] : (tmp[j][pre] < dp[j][next] ? tmp[j][pre] : dp[j][next]);
          } else {
            if (next == 0)
              dp[j + 1][next] = dp[j + 1][next] == -1 ? tmp[j][pre] + t[i - 1] : (tmp[j][pre] + t[i - 1] < dp[j + 1][next] ? tmp[j][pre] + t[i - 1] : dp[j + 1][next]);
            else
              dp[j][next] = dp[j][next] == -1 ? tmp[j][pre] + t[i - 1] : (tmp[j][pre] + t[i - 1] < dp[j][next] ? tmp[j][pre] + t[i - 1] : dp[j][next]);
          }
        }
      }
    }

    memcpy(tmp, dp, sizeof(tmp));
  }

  return dp[n / 2][0] < dp[n / 2][1] ? dp[n / 2][0] : dp[n / 2][1];
}

int main() {
  int n;
  scanf("%d", &n);

  int t[n - 1];
  for (int i = 0; i < n - 1; i++) {
    scanf("%d", &t[i]);
  }

  printf("%d\n", solve(n));
}