#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAX_N = 5002;
int n;
int t[MAX_N-1];
int dp[MAX_N/2+1][2], tmp[MAX_N/2+1][2];
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
      int tmpj0 = tmp[j][0], tmpj1 = tmp[j][1];
      if (tmpj0 != -1) {
        if (j + 1 <= n/2) {
          dp[j + 1][0] = minCost(dp[j + 1][0], tmpj0);
          dp[j + 1][1] = minCost(dp[j + 1][1], tmpj0 + t[i-1]);
        }
        if (j <= n/2) {
          dp[j][0] = minCost(dp[j][0], tmpj0 + t[i-1]);
          dp[j][1] = minCost(dp[j][1], tmpj0);
        }
      }
      if (tmpj1 != -1) {
        if (j + 1 <= n/2) {
          dp[j + 1][1] = minCost(dp[j + 1][1], tmpj1);
          dp[j + 1][0] = minCost(dp[j + 1][0], tmpj1 + t[i-1]);
        }
        if (j <= n/2) {
          dp[j][1] = minCost(dp[j][1], tmpj1 + t[i-1]);
          dp[j][0] = minCost(dp[j][0], tmpj1);
        }
      }
    }
    memcpy(tmp, dp, sizeof(dp));
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