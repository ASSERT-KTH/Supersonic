#include <cstdio>
#include <iostream>
using namespace std;

int n;
int t[10002];
int dp[10002][5002][2];

int minCost(const int &a, const int &b) {
  if (a == -1)
    return b;
  if (b == -1)
    return a;
  return a > b ? b : a;
}

int solve() {
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n / 2; j++) {
      for (int k = 0; k < 2; k++) {
        dp[i][j][k] = -1;
      }
    }
  }

  dp[0][0][0] = dp[0][1][1] = 0;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= n / 2; j++) {
      for (int pre = 0; pre < 2; pre++) {
        if (dp[i-1][j][pre] == -1)
          continue;
        
        // Case for next = 0
        dp[i][j + 1][0] = minCost(dp[i][j + 1][0], dp[i - 1][j][pre] + (pre == 1 ? t[i - 1] : 0));
        
        // Case for next = 1
        dp[i][j][1] = minCost(dp[i][j][1], dp[i - 1][j][pre] + (pre == 0 ? t[i - 1] : 0));
      }
    }
  }
  return minCost(dp[n - 1][n / 2][0], dp[n - 1][n / 2][1]);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d", &t[i]);
  }
  printf("%d\n", solve());
}