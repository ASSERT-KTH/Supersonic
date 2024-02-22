#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int n;
int t[10002];
int dp[5002], tmp[5002];

int solve() {
  memset(tmp, -1, sizeof(tmp));
  tmp[1] = tmp[0] = 0;

  for (int i = 1; i < n; i++) {
    memset(dp, -1, sizeof(dp));

    for (int j = 0; j <= n / 2; j++) {
      if (tmp[j] != -1) {
        dp[j + 1] = (tmp[j] != -1) ? min(dp[j + 1], tmp[j]) : dp[j + 1];
        dp[j] = (tmp[j] != -1) ? min(dp[j], tmp[j] + t[i - 1]) : dp[j];
      }
    }

    for (int j = 0; j <= n / 2; j++) {
      tmp[j] = dp[j];
    }
  }

  return min(dp[n / 2], dp[n / 2 + 1]);
}

int main() {
  scanf("%d", &n);

  for (int i = 0; i < n - 1; i++) {
    scanf("%d", &t[i]);
  }

  printf("%d\n", solve());
}