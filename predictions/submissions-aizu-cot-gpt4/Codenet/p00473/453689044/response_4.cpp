#include <cstdio>
#include <cstring>
#include <iostream>

int n;
int t[10002];
int dp[5002][2], tmp[5002][2];

int minCost(int a, int b) {
  if (a == -1)
    return b;
  if (b == -1)
    return a;
  return a > b ? b : a;
}

int solve() {
  memset(tmp, -1, sizeof(tmp));
  tmp[1][0] = tmp[0][1] = 0;
  int half_n = n / 2;
  
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= half_n; j++) {
      for (int pre = 0; pre < 2; pre++) {
        if (tmp[j][pre] == -1)
          continue;
        for (int next = 0; next < 2; next++) {
          int &current = next == 0 ? dp[j + 1][next] : dp[j][next];
          int cost = pre == next ? tmp[j][pre] : tmp[j][pre] + t[i - 1];
          current = minCost(current, cost);
        }
      }
    }
    memcpy(tmp, dp, sizeof(dp));
    memset(dp, -1, sizeof(dp));
  }
  return minCost(tmp[half_n][0], tmp[half_n][1]);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d", &t[i]);
  }
  printf("%d\n", solve());
}