#include <cstdio>
#include <algorithm>

int n;
int t[10002];
int dp[5002][2], tmp[5002][2];

int solve() {
  for (int j = 0; j <= n / 2; j++) {
      tmp[j][0] = tmp[j][1] = -1;
  }
  tmp[1][0] = tmp[0][1] = 0;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= n / 2; j++) {
      dp[j][0] = dp[j][1] = -1;
      for (int pre = 0; pre < 2; pre++) {
        if (tmp[j][pre] == -1)
          continue;
        for (int next = 0; next < 2; next++) {
          if (pre == next) {
            if (next == 0 && (dp[j + 1][next] == -1 || dp[j + 1][next] > tmp[j][pre]))
              dp[j + 1][next] = tmp[j][pre];
            else if (next == 1 && (dp[j][next] == -1 || dp[j][next] > tmp[j][pre]))
              dp[j][next] = tmp[j][pre];
          } else {
            if (next == 0 && (dp[j + 1][next] == -1 || dp[j + 1][next] > tmp[j][pre] + t[i - 1]))
              dp[j + 1][next] = tmp[j][pre] + t[i - 1];
            else if (next == 1 && (dp[j][next] == -1 || dp[j][next] > tmp[j][pre] + t[i - 1]))
              dp[j][next] = tmp[j][pre] + t[i - 1];
          }
        }
      }
    }
    std::swap(dp, tmp);
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