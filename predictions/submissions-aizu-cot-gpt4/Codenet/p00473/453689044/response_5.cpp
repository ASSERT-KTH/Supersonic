#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int *t;
int dp[5002][2], tmp[5002][2];
int minCost(const int &a, const int &b) {
  if (a == -1)
    return b;
  if (b == -1)
    return a;
  return a > b ? b : a;
}
int solve() {
  int half = n/2;
  memset(tmp, -1, sizeof(tmp));
  tmp[1][0] = tmp[0][1] = 0;
  for (int i = 1; i < n; i++) {
    for(int j = 0; j <= half; j++){
        dp[j][0] = dp[j][1] = -1;
    }
    for (int j = 0; j <= half; j++) {
      for (int pre = 0; pre < 2; pre++) {
        if (tmp[j][pre] == -1)
          continue;
        for (int next = 0; next < 2; next++) {
          if (pre == next) {
            if (next == 0)
              dp[j + 1][next] = minCost(dp[j + 1][next], tmp[j][pre]);
            else
              dp[j][next] = minCost(dp[j][next], tmp[j][pre]);
          } else {
            if (next == 0)
              dp[j + 1][next] =
                  minCost(dp[j + 1][next], tmp[j][pre] + t[i - 1]);
            else
              dp[j][next] = minCost(dp[j][next], tmp[j][pre] + t[i - 1]);
          }
        }
      }
    }
    swap(dp, tmp);
  }
  return minCost(tmp[half][0], tmp[half][1]);
}
int main() {
  scanf("%d", &n);
  t = new int[n-1];
  for (int i = 0; i < n - 1; i++) {
    scanf("%d", &t[i]);
  }
  printf("%d\n", solve());
  delete[] t;
}