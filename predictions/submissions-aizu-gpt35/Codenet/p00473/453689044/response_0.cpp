#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 10002;
const int MAXM = 5002;
int n;
int t[MAXN];
int dp[MAXM][2], tmp[MAXM][2];
int minCost(const int &a, const int &b) {
  if (a == -1)
    return b;
  if (b == -1)
    return a;
  return a > b ? b : a;
}
int solve() {
  memset(tmp, -1, sizeof(tmp));
  tmp[1][0] = tmp[0][1] = 0;
  for (int i = 1; i < n; i++) {
    memset(dp, -1, sizeof(dp));
    for (int j = 0; j <= n / 2; j++) {
      if (tmp[j][0] != -1) {
        if (j + 1 <= n / 2) {
          dp[j + 1][0] = minCost(dp[j + 1][0], tmp[j][0]);
        }
        dp[j][1] = minCost(dp[j][1], tmp[j][0] + t[i - 1]);
      }
      if (tmp[j][1] != -1) {
        if (j + 1 <= n / 2) {
          dp[j + 1][0] = minCost(dp[j + 1][0], tmp[j][1] + t[i - 1]);
        }
        dp[j][1] = minCost(dp[j][1], tmp[j][1]);
      }
    }
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