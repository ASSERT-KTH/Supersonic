#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
int n;
int t[10002];
int dp[5002][2];
int solve() {
  memset(dp, INF, sizeof(dp));
  dp[0][0] = dp[0][1] = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i / 2; j <= (i + 1) / 2; j++) {
      if (dp[j][0] != INF) {
        dp[j + 1][0] = min(dp[j + 1][0], dp[j][0] + t[i]);
        dp[j][1] = min(dp[j][1], dp[j][0]);
      }
      if (dp[j][1] != INF) {
        dp[j + 1][0] = min(dp[j + 1][0], dp[j][1] + t[i]);
        dp[j][1] = min(dp[j][1], dp[j][1]);
      }
    }
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