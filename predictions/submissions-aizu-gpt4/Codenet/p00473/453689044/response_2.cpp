#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 10005;

int n;
int t[MAXN];
int dp[MAXN][2];

int solve() {
  fill_n(&dp[0][0], MAXN*2, -1);
  dp[1][0] = dp[0][1] = 0;

  for (int i = 1; i < n; i++) {
    int dpnext[MAXN][2];
    fill_n(&dpnext[0][0], MAXN*2, -1);
    for (int j = 0; j <= n / 2; j++) {
      for (int pre = 0; pre < 2; pre++) {
        if (dp[j][pre] != -1) {
          for (int next = 0; next < 2; next++) {
            if (pre == next) {
              if (next == 0 && dpnext[j + 1][next] == -1)
                dpnext[j + 1][next] = dp[j][pre];
              else if (dpnext[j][next] == -1)
                dpnext[j][next] = dp[j][pre];
            } else {
              if (next == 0 && dpnext[j + 1][next] == -1)
                dpnext[j + 1][next] = dp[j][pre] + t[i - 1];
              else if (dpnext[j][next] == -1)
                dpnext[j][next] = dp[j][pre] + t[i - 1];
            }
          }
        }
      }
    }
    copy(&dpnext[0][0], &dpnext[0][0]+MAXN*2, &dp[0][0]);
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