#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int n;
int t[10002];
int dp[5002][2];

int solve() {
  memset(dp, -1, sizeof(dp));
  dp[1][0] = dp[0][1] = 0;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= n / 2; j++) {
      for (int pre = 0; pre < 2; pre++) {
        if (dp[j][pre] != -1) {
          for (int next = 0; next < 2; next++) {
            int cost = dp[j][pre] + (pre != next ? t[i - 1] : 0);
            if (pre == next) {
              if (next == 0)
                dp[j + 1][next] = (dp[j + 1][next] == -1) ? cost : min(dp[j + 1][next], cost);
              else
                dp[j][next] = (dp[j][next] == -1) ? cost : min(dp[j][next], cost);
            } else {
              if (next == 0)
                dp[j + 1][next] = (dp[j + 1][next] == -1) ? cost : min(dp[j + 1][next], cost);
              else
                dp[j][next] = (dp[j][next] == -1) ? cost : min(dp[j][next], cost);
            }
          }
        }
      }
    }
  }
  return min(dp[n / 2][0], dp[n / 2][1]);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d", &t[i]);
  }
  printf("%d\n", solve());
}