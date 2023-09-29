#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int n;
int t[10002];
int dp[5002][2], tmp[5002][2];
int minCost(const int &a, const int &b) {
  if (a == -1)
    return b;
  if (b == -1)
    return a;
  return a > b ? b : a;
}
int solve() {
  memset(dp, -1, sizeof(dp));
  tmp[1][0] = tmp[0][1] = 0;
  for (int i = 1; i < n; i++) {
    memset(dp, -1, sizeof(dp));
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
      