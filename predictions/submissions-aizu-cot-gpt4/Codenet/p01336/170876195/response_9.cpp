#include <algorithm>
#include <cstdio>
#include <cstring>
using std::max;

#define CLEAR(arr, val) memset(arr, val, sizeof(arr))
typedef long long ll;

const int MAXN = 333;
int n, m;
int c[MAXN], v[3][MAXN];
int dp[2][MAXN];

int dpru(int *c, int *v) {
  CLEAR(dp, 0);
  for (int i = 0; i < n; ++i) {
    memcpy(dp[(i + 1) % 2], dp[i % 2], sizeof(dp[0]));
    for (int j = c[i]; j <= m; ++j) {
      dp[(i + 1) % 2][j] = max(dp[(i + 1) % 2][j], dp[i % 2][j - c[i]] + v[i]);
    }
  }
  return dp[n % 2][m];
}

int main() {
  while (scanf("%d%d", &n, &m) == 2) {
    int res = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%*s %*s %d", &c[i]);
      for (int j = 0; j < 3; ++j) scanf("%d", &v[j][i]);
    }
    for (int i = 0; i < 3; ++i) res = max(res, dpru(c, v[i]));
    printf("%d\n", res);
  }
  return 0;
}