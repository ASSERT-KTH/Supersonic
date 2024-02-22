#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int *t;
int dp[2][5002][2];
int solve() {
  int p = 0;
  fill(&dp[0][0][0], &dp[0][0][0] + sizeof(dp[0])/sizeof(int), -1);
  dp[p][1][0] = dp[p][0][1] = 0;
  for (int i = 1; i < n; i++) {
    int np = 1 - p;
    fill(&dp[np][0][0], &dp[np][0][0] + sizeof(dp[0])/sizeof(int), -1);
    for (int j = 0; j <= n / 2; j++) {
      for (int pre = 0; pre < 2; pre++) {
        if (dp[p][j][pre] == -1)
          continue;
        for (int next = 0; next < 2; next++) {
          if (pre == next) {
            if (next == 0)
              dp[np][j + 1][next] = min(dp[np][j + 1][next], dp[p][j][pre]);
            else
              dp[np][j][next] = min(dp[np][j][next], dp[p][j][pre]);
          } else {
            if (next == 0)
              dp[np][j + 1][next] = min(dp[np][j + 1][next], dp[p][j][pre] + t[i - 1]);
            else
              dp[np][j][next] = min(dp[np][j][next], dp[p][j][pre] + t[i - 1]);
          }
        }
      }
    }
    p = np;
  }
  return min(dp[p][n / 2][0], dp[p][n / 2][1]);
}
int main() {
  scanf("%d", &n);
  t = new int[n-1];
  for (int i = 0; i < n - 1; i++) {
    scanf("%d", &t[i]);
  }
  printf("%d\n", solve());
  delete[] t;
}