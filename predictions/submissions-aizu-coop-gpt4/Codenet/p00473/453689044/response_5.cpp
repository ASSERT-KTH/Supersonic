#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int n;
int t[10002];
int dp[2][5002][2];
int solve() {
  fill_n(&dp[0][0][0], 5002*2*2, -1);
  dp[0][1][0] = dp[0][0][1] = 0;
  int curr = 0, prev = 1;
  for (int i = 1; i < n; i++) {
    prev = curr;
    curr = 1 - curr;
    fill_n(&dp[curr][0][0], 5002*2, -1);
    for (int j = 0; j <= n / 2; j++) {
      for (int pre = 0; pre < 2; pre++) {
        if (dp[prev][j][pre] == -1) continue;
        for (int next = 0; next < 2; next++) {
          int add = pre == next ? 0 : t[i - 1];
          dp[curr][j + next][next] = min(dp[curr][j + next][next], dp[prev][j][pre] + add);
        }
      }
    }
  }
  return min(dp[curr][n / 2][0], dp[curr][n / 2][1]);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d", &t[i]);
  }
  printf("%d\n", solve());
}