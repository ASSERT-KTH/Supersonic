#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
template <class T> void max_swap(T &a, const T &b) { a = max(a, b); }
typedef long long ll;
typedef pair<int, int> pint;
static int dp[333][333];
int n, m;
int dpru(int *c, int *v) {
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; ++i) {
    if (c[i] > m) continue;
    for (int j = 0; j <= m; ++j) {
      dp[i + 1][j] = dp[i][j];
      if (j >= c[i])
        max_swap(dp[i + 1][j], dp[i + 1][j - c[i]] + v[i]);
    }
  }
  return dp[n][m];
}
int main() {
  while (scanf("%d %d", &n, &m) == 2) {
    int c[333], v[3][333];
    rep(i, n) {
      int t;
      scanf("%*s %*s %d", &t);
      c[i] = t;
      rep(j, 3) scanf("%d", &v[j][i]);
    }
    int res = 0;
    rep(i, 3) max_swap(res, dpru(c, v[i]));
    printf("%d\n", res);
  }
}