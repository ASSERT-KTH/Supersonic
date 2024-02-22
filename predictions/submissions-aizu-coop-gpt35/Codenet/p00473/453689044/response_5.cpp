#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n;
int t[10002];
int dp[5002], tmp[5002];

int minCost(const int &a, const int &b) {
  if (a == -1)
    return b;
  if (b == -1)
    return a;
  return a > b ? b : a;
}

int solve() {
  memset(tmp, -1, sizeof(tmp));
  tmp[1] = tmp[0] = 0;

  for (int i = 1; i < n; i++) {
    memset(dp, -1, sizeof(dp));
    for (int j = 0; j <= n / 2; j++) {
      if (tmp[j] == -1)
        continue;

      int val1 = tmp[j];
      int val2 = tmp[j] + t[i - 1];

      if (j + 1 <= n / 2) {
        dp[j + 1] = minCost(dp[j + 1], val1);
      }

      dp[j] = minCost(dp[j], val2);
    }

    for (int j = 0; j <= n / 2; j++) {
      tmp[j] = dp[j];
    }
  }

  return minCost(dp[n / 2], dp[n / 2]);
}

int main() {
  scanf("%d", &n);

  for (int i = 0; i < n - 1; i++) {
    scanf("%d", &t[i]);
  }

  printf("%d\n", solve());
}