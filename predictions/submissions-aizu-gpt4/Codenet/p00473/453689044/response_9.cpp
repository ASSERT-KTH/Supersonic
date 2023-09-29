#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int t[10002];
int dp[5002][2];
int solve() {
  memset(dp, -1, sizeof(dp));
  dp[0][0] = dp[0][1] = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j >= 0; j--) {
      for (int pre = 0; pre < 2; pre++) {
        if (dp[j][pre] != -1) {
          dp[j + 1][0] = min(dp[j + 1][0] == -1 ? t[i] : dp[j + 1][0], dp[j][pre] + t[i]);
          dp[j][1] = min(dp[j][1] == -1 ? 0 : dp[j][1], dp[j][pre]);
        }
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