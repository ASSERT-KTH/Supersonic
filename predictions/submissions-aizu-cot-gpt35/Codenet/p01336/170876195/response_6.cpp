#include <cstdio>
#include <cstring>
using namespace std;

#define CLEAR(arr, val) memset(arr, val, sizeof(arr))
#define rep(i, n) for (int i = 0; i < n; ++i)

int n, m;

int dpru(int *c, int *v) {
  int dp[333];
  CLEAR(dp, 0);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= m; ++j) {
      dp[j] = max(dp[j], (j >= c[i] ? dp[j - c[i]] + v[i] : 0));
    }
  }
  return dp[m];
}

int main() {
  while (scanf("%d %d", &n, &m) == 2) {
    int c[333], v[3][333];
    rep(i, n) {
      scanf("%d", &c[i]);
      rep(j, 3) scanf("%d", &v[j][i]);
    }
    int res = 0;
    rep(i, 3) res = max(res, dpru(c, v[i]));
    printf("%d\n", res);
  }
}