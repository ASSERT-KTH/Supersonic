#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
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
  memset(tmp, -1, sizeof(tmp[0][0]) * ((n / 2) + 1) * 2);
  tmp[1][0] = tmp[0][1] = 0;
  for (int i = 1; i < n; i++) {
    memset(dp, -1, sizeof(dp[0][0]) * ((n / 2) + 1) * 2);
    for (int j = 0; j <= n / 2; j++) {
      for (int pre = 0; pre < 2; pre++) {
        if (tmp[j][pre] == -1)
          continue;
        for (int next = 0; next < 2; next++) {
          int cost = minCost(dp[j + (next == 0 ? 1 : 0)][next], tmp[j][pre] + (pre != next ? t[i - 1] : 0));
          dp[j + (next == 0 ? 1 : 0)][next] = cost;
        }
      }
    }
    std::copy(&dp[0][0], &dp[0][0] + (n / 2 + 1) * 2, &tmp[0][0]);
  }
  return minCost(dp[n / 2][0], dp[n / 2][1]);
}
int main() {
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> t[i];
  }
  cout << solve() << '\n';
}