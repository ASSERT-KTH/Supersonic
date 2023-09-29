#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAX_N = 5001;
const int INF = 1e9;
int n;
int t[MAX_N - 1];
int dp[MAX_N][2];
int minCost(const int &a, const int &b) {
  return a < b ? a : b;
}
int solve() {
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i < n; i++) {
    for (int j = n / 2; j >= 0; j--) {
      if (j == 0) {
        dp[j][1] = INF;
        dp[j][0] = dp[j][0] + t[i - 1];
      } else {
        dp[j][1] = minCost(dp[j - 1][0], dp[j - 1][1]);
        dp[j][0] = minCost(dp[j][0] + t[i - 1], dp[j][1] + t[i - 1]);
      }
    }
  }
  return dp[n / 2][0];
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d", &t[i]);
  }
  printf("%d\n", solve());
}