#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n;
int t[10002];
int dp[2][5002][2];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d", &t[i]);
  }

  memset(dp, -1, sizeof(dp));
  int cur = 0, pre = 1;
  dp[cur][1][0] = dp[cur][0][1] = 0;

  for (int i = 1; i < n; i++) {
    swap(cur, pre);
    memset(dp[cur], -1, sizeof(dp[cur]));
    for (int j = 0; j <= n / 2; j++) {
      for (int pre_state = 0; pre_state < 2; pre_state++) {
        if (dp[pre][j][pre_state] != -1) {
          int val0 = dp[pre][j][pre_state] + (pre_state == 0 ? 0 : t[i - 1]);
          dp[cur][j + 1][0] = dp[cur][j + 1][0] != -1 ? min(val0, dp[cur][j + 1][0]) : val0;
          int val1 = dp[pre][j][pre_state] + (pre_state == 1 ? 0 : t[i - 1]);
          dp[cur][j][1] = dp[cur][j][1] != -1 ? min(val1, dp[cur][j][1]) : val1;
        }
      }
    }
  }

  int ans = dp[cur][n / 2][0] != -1 ? dp[cur][n / 2][0] : dp[cur][n / 2][1];
  if (dp[cur][n / 2][0] != -1 && dp[cur][n / 2][1] != -1) {
    ans = min(dp[cur][n / 2][0], dp[cur][n / 2][1]);
  }
  printf("%d\n", ans);
}