#include <algorithm>
#include <cstdio>
#include <cstring>
#define rep(i, n) for (int i = 0; i < n; ++i)

int dp[333][333];
int n, m;

int dpru(int *c, int *v) {
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= m; ++j)
      dp[i][j] = 0;
  
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= m; ++j) {
      dp[i + 1][j] = dp[i][j];
      if (j >= c[i])
        dp[i + 1][j] = max(dp[i + 1][j], dp[i + 1][j - c[i]] + v[i]);
    }
  }
  return dp[n][m];
}

int main() {
  while (scanf("%d%d", &n, &m) == 2) {
    int c[333], v[3][333];
    rep(i, n) {
      int t;
      scanf("%*s"); // read and discard string
      scanf("%d", &t);
      c[i] = t;
      rep(j, 3) scanf("%d", &v[j][i]);
    }
    int res = 0;
    rep(i, 3) res = max(res, dpru(c, v[i]));
    printf("%d\n", res);
  }
}