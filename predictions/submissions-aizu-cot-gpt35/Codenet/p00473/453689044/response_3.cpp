#include <cstdio>
#include <algorithm>

const int MAX_N = 10002;
const int MAX_DP = 5002;

int t[MAX_N];
int dp[MAX_DP][2];

int solve() {
  dp[0][1] = 0;
  for (int i = 2; i < MAX_N; i++) {
    for (int j = 0; j <= i / 2; j++) {
      dp[j + 1][0] = std::min(dp[j + 1][0], dp[j][0]);
      dp[j][1] = std::min(dp[j][1], dp[j][0] + t[i - 2]);
      dp[j][0] = std::min(dp[j][0], dp[j][1]);
    }
  }
  return dp[MAX_N / 2][0];
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d", &t[i]);
  }
  printf("%d\n", solve());
  return 0;
}