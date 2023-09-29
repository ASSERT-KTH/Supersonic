#include <cstdio>
#include <cstring>

constexpr int MAX_N = 10002;
constexpr int MAX_N_HALF = 5002;

int n;
int t[MAX_N];
int dp[MAX_N_HALF][2];

int minCost(const int &a, const int &b) {
  if (a == -1)
    return b;
  if (b == -1)
    return a;
  return a > b ? b : a;
}

int solve() {
  memset(dp, -1, sizeof(dp));
  dp[1][0] = dp[0][1] = 0;
  for (int i = 1; i < n; i++) {
    int dp_next[MAX_N_HALF][2];
    memset(dp_next, -1, sizeof(dp_next));
    for (int j = 0; j <= i && j <= n / 2; j++) {
      for (int pre = 0; pre < 2; pre++) {
        if (dp[j][pre] == -1)
          continue;
        for (int next = 0; next < 2; next++) {
          int cost = dp[j][pre] + (pre != next ? t[i - 1] : 0);
          int& dp_target = next ? dp_next[j][next] : dp_next[j + 1][next];
          dp_target = minCost(dp_target, cost);
        }
      }
    }
    memcpy(dp, dp_next, sizeof(dp));
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