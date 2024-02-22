#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int n;
int t[10002];
vector<vector<int>> dp(5002, vector<int>(2)), tmp(5002, vector<int>(2));

int solve() {
  tmp[1][0] = tmp[0][1] = 0;
  for (int i = 1; i < n; i++) {
    dp.assign(5002, vector<int>(2, -1));
    for (int j = 0; j <= n / 2; j++) {
      if (tmp[j][0] != -1) {
        dp[j + 1][0] = min(dp[j + 1][0], tmp[j][0]);
        dp[j][1] = min(dp[j][1], tmp[j][0]);
      }
      if (tmp[j][1] != -1) {
        dp[j + 1][0] = min(dp[j + 1][0], tmp[j][1] + t[i - 1]);
        dp[j][1] = min(dp[j][1], tmp[j][1] + t[i - 1]);
      }
    }
    tmp = dp;
  }
  return min(dp[n / 2][0], dp[n / 2][1]);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d", &t[i]);
  }
  printf("%d\n", solve());
}