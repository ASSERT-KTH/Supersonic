#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int n;
int t[10002];
int dp[2][5002];  // Modified array declaration
int minCost(const int &a, const int &b) {
  if (a == -1)
    return b;
  if (b == -1)
    return a;
  return a > b ? b : a;
}
int solve() {
  memset(dp, -1, sizeof(dp));
  dp[1][0] = dp[0][1] = 0;
  int cur = 0;  // Current row index
  for (int i = 1; i < n; i++) {
    memset(dp[cur ^ 1], -1, sizeof(dp[cur ^ 1]));  // Use cur ^ 1 to access the previous row
    for (int j = 0; j <= n / 2; j++) {
      for (int pre = 0; pre < 2; pre++) {
        if (dp[cur][j] == -1)  // Use dp[cur] to access the current row
          continue;
        for (int next = 0; next < 2; next++) {
          if (pre == next) {
            if (next == 0)
              dp[cur ^ 1][j + 1] = minCost(dp[cur ^ 1][j + 1], dp[cur][j]);
            else
              dp[cur][j] = minCost(dp[cur][j], dp[cur][j]);
          } else {
            if (next == 0)
              dp[cur ^ 1][j + 1] =
                  minCost(dp[cur ^ 1][j + 1], dp[cur][j] + t[i - 1]);
            else
              dp[cur][j] = minCost(dp[cur][j], dp[cur][j] + t[i - 1]);
          }
        }
      }
    }
    cur ^= 1;  // Update the current row index
  }
  return minCost(dp[cur][n / 2], dp[cur][n / 2]);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d", &t[i]);
  }
  printf("%d\n", solve());
}