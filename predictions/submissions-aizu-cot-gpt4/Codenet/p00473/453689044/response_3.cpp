#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int t[10002];
int dp[2][5002][2];
int solve() {
  int halfN = n / 2;
  dp[0][1][0] = dp[0][0][1] = 0;
  dp[0][0][0] = dp[0][1][1] = -1;
  for (int i = 1; i < n; i++) {
    int cur = i % 2;
    int pre = (i - 1) % 2;
    for (int j = 0; j <= halfN; j++) {
      dp[cur][j][0] = dp[cur][j][1] = -1;
      for (int preStatus = 0; preStatus < 2; preStatus++) {
        if (dp[pre][j][preStatus] == -1)
          continue;
        if (dp[cur][j + 1][0] == -1 || dp[cur][j + 1][0] > dp[pre][j][preStatus])
          dp[cur][j + 1][0] = dp[pre][j][preStatus];
        if (j > 0 && (dp[cur][j][1] == -1 || dp[cur][j][1] > dp[pre][j - 1][0] + t[i - 1]))
          dp[cur][j][1] = dp[pre][j - 1][0] + t[i - 1];
      }
    }
  }
  return min(dp[(n - 1) % 2][halfN][0], dp[(n - 1) % 2][halfN][1]);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d", &t[i]);
  }
  printf("%d\n", solve());
}