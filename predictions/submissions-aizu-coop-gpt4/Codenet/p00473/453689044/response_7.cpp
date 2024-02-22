#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int t[10002];
int dp[2][5002][2];
int solve() {
  for (int i = 1; i < n; i++) {
    int cur = i & 1;  // current iteration
    int pre = 1 - cur;  // previous iteration
    for (int j = 0; j <= n / 2; j++) {
      // loop unrolling
      int next = 0;
      if (j + 1 <= n / 2)
        dp[cur][j + 1][next] = (dp[pre][j][next] == -1) ? -1 :
                                min(dp[cur][j + 1][next], dp[pre][j][next]);
      if (j + 1 <= n / 2)
        dp[cur][j + 1][next] = (dp[pre][j][1 - next] == -1) ? -1 :
                                min(dp[cur][j + 1][next], dp[pre][j][1 - next] + t[i - 1]);

      next = 1;
      dp[cur][j][next] = (dp[pre][j][next] == -1) ? -1 :
                          min(dp[cur][j][next], dp[pre][j][next]);
      dp[cur][j][next] = (dp[pre][j][1 - next] == -1) ? -1 :
                          min(dp[cur][j][next], dp[pre][j][1 - next] + t[i - 1]);
    }
  }
  return min(dp[n & 1][n / 2][0], dp[n & 1][n / 2][1]);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d", &t[i]);
  }
  printf("%d\n", solve());
}