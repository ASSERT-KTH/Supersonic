#include <cstdio>
#include <iostream>
using namespace std;

int n;
int t[10002];
int dp[5002][2], tmp[5002][2];

int minCost(const int &a, const int &b) {
  if (a == -1)
    return b;
  else if (b == -1)
    return a;
  else
    return a > b ? b : a;
}

int solve() {
  int half_n = n / 2; // Compute once
  tmp[1][0] = tmp[0][1] = 0;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= half_n; j++) { 
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
        // Merge the copy operation here
        tmp[j][pre] = dp[j][pre];
      }
      // Set unused cells to "-1"
      if (tmp[j][0] == -1) dp[j][0] = -1;
      if (tmp[j][1] == -1) dp[j][1] = -1;
    }
  }
  return minCost(dp[half_n][0], dp[half_n][1]);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d", &t[i]);
  }
  printf("%d\n", solve());
}