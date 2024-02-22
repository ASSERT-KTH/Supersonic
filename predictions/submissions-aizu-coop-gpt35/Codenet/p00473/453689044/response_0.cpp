#include <cstdio>
#include <algorithm>

const int MAX_N = 10002;

int n;
int t[MAX_N];
int dp[MAX_N][2];

int solve() {
  dp[1][0] = dp[0][1] = 0;

  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= n / 2; j++) {
      dp[j + 1][0] = std::min(dp[j + 1][0], dp[j][0]);
      dp[j][1] = std::min(dp[j][1], dp[j][0]);
      
      dp[j + 1][1] = std::min(dp[j + 1][1], dp[j][1] + t[i - 1]);
      dp[j][0] = std::min(dp[j][0], dp[j][1] + t[i - 1]);
    }
  }

  return std::min(dp[n / 2][0], dp[n / 2][1]);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d", &t[i]);
  }

  printf("%d\n", solve());
  return 0;
}