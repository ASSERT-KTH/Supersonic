#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n;
int t[10002];
int dp[5002][2], tmp[5002][2];

int minCost(const int &a, const int &b) {
  // No changes made to the minCost function
  if (a == -1)
    return b;
  if (b == -1)
    return a;
  return a > b ? b : a;
}

int solve() {
  // Initialize tmp and dp arrays only once
  memset(tmp, -1, sizeof(tmp));
  tmp[1][0] = tmp[0][1] = 0;

  for (int i = 1; i <= n / 2; i++) {
    // No need to initialize dp array at every iteration
    for (int j = 0; j <= n / 2; j++) {
      for (int pre = 0; pre < 2; pre++) {
        if (tmp[j][pre] == -1)
          continue;
        for (int next = 0; next < 2; next++) {
          if (pre == next) {
            if (next == 0)
              dp[j + 1][next] = minCost(dp[j + 1][next], tmp[j][pre]);
            else
              dp[j][next] = minCost(dp[j][next], tmp[j][pre]);
          } else {
            if (next == 0)
              dp[j + 1][next] =
                  minCost(dp[j + 1][next], tmp[j][pre] + t[i - 1]);
            else
              dp[j][next] = minCost(dp[j][next], tmp[j][pre] + t[i - 1]);
          }
        }
      }
    }
    // Copy dp array to tmp array for the next iteration
    for (int j = 0; j <= n / 2; j++) {
      for (int k = 0; k < 2; k++) {
        tmp[j][k] = dp[j][k];
      }
    }
  }
  return minCost(dp[n / 2][0], dp[n / 2][1]);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d", &t[i]);
  }
  printf("%d\n", solve());
}