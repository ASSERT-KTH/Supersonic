#include <cstdio>
#include <cstring>
using namespace std;
int n;
int t[10002];
int dp[2][5002][2];

int solve() {
  memset(dp, -1, sizeof(dp));
  dp[0][1][0] = dp[0][0][1] = 0;
  for (int i = 1; i < n; i++) {
    int cur = i & 1;
    int pre = 1 - cur;
    memset(dp[cur], -1, sizeof(dp[cur]));
    for (int j = 0; j <= n / 2; j++) {
      for (int p = 0; p < 2; p++) {
        if (dp[pre][j][p] == -1)
          continue;
        for (int next = 0; next < 2; next++) {
          if (p == next) {
            if (next == 0 && (dp[cur][j + 1][next] == -1 || dp[cur][j + 1][next] > dp[pre][j][p]))
              dp[cur][j + 1][next] = dp[pre][j][p];
            else if (dp[cur][j][next] == -1 || dp[cur][j][next] > dp[pre][j][p])
              dp[cur][j][next] = dp[pre][j][p];
          } else {
            if (next == 0 && (dp[cur][j + 1][next] == -1 || dp[cur][j + 1][next] > dp[pre][j][p] + t[i - 1]))
              dp[cur][j + 1][next] = dp[pre][j][p] + t[i - 1];
            else if (dp[cur][j][next] == -1 || dp[cur][j][next] > dp[pre][j][p] + t[i - 1])
              dp[cur][j][next] = dp[pre][j][p] + t[i - 1];
          }
        }
      }
    }
  }
  int final = n & 1;
  if (dp[final][n / 2][0] == -1) return dp[final][n / 2][1];
  if (dp[final][n / 2][1] == -1) return dp[final][n / 2][0];
  return dp[final][n / 2][0] > dp[final][n / 2][1] ? dp[final][n / 2][1] : dp[final][n / 2][0];
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d", &t[i]);
  }
  printf("%d\n", solve());
}