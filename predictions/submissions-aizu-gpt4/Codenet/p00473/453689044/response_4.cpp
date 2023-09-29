#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int t[10002];
int dp[5002][2];
int solve() {
  memset(dp, 0x3f, sizeof(dp));
  dp[1][0] = dp[0][1] = 0;
  for (int i = 1; i < n; i++) {
    for (int j = i / 2; j <= (i + 1) / 2; j++) {
      for (int pre = 0; pre < 2; pre++) {
        int next = i % 2;
        if (pre == next) {
          if (next == 0)
            dp[j + 1][next] = min(dp[j + 1][next], dp[j][pre]);
          else
            dp[j][next] = min(dp[j][next], dp[j][pre]);
        } else {
          if (next == 0)
            dp[j + 1][next] = min(dp[j + 1][next], dp[j][pre] + t[i - 1]);
          else
            dp[j][next] = min(dp[j][next], dp[j][pre] + t[i - 1]);
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