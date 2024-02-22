#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int n;
int t[10002];
int dp[2][5002][2];
int minCost(const int &a, const int &b) {
  if (a == -1)
    return b;
  if (b == -1)
    return a;
  return a > b ? b : a;
}
int solve() {
  int cur = 0, pre = 1;
  memset(dp[cur], -1, sizeof(dp[cur]));
  dp[cur][1][0] = dp[cur][0][1] = 0;
  for (int i = 1; i < n; i++) {
    swap(cur, pre);
    memset(dp[cur], -1, sizeof(dp[cur]));
    for (int j = 0; j <= n / 2; j++) {
      for (int preState = 0; preState < 2; preState++) {
        if (dp[pre][j][preState] == -1)
          continue;
        for (int nextState = 0; nextState < 2; nextState++) {
          int cost = dp[pre][j][preState];
          if (preState != nextState)
            cost += t[i - 1];
          if (nextState == 0)
            dp[cur][j + 1][nextState] = minCost(dp[cur][j + 1][nextState], cost);
          else
            dp[cur][j][nextState] = minCost(dp[cur][j][nextState], cost);
        }
      }
    }
  }
  return minCost(dp[cur][n / 2][0], dp[cur][n / 2][1]);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d", &t[i]);
  }
  printf("%d\n", solve());
}