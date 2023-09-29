#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 5002;
const int maxm = 2;
int n;
int t[maxn];
int dp[maxm][maxn], tmp[maxm][maxn];
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
      for (int pre = 0; pre < 2; pre++) {
        if (tmp[j][pre] == -1)
          continue;
        for (int next = 0; next < 2; next++) {
          if (pre == next) {
            dp[j + (next == 0)][next] =
              minCost(dp[j + (next == 0)][next], tmp[j][pre]);
          } else {
            dp[j][next] =
              minCost(dp[j][next], tmp[j][pre] + t[i - 1] * (next == 1));
          }
        }
      }
    }
    for (int j = 0; j <= n / 2; j++) {
      for (int k = 0; k < 2; k++) {
        tmp[k][j] = dp[k][j];
      }
    }
  }
  return minCost(dp[0][n / 2], dp[1][n / 2]);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d", &t[i]);
  }
  printf("%d\n", solve());
}