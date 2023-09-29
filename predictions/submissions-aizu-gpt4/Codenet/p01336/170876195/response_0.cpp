#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define max_swap(a, b) a = max(a, b)

const int MAX_N = 333;
int n, m;
int c[MAX_N], v[3][MAX_N], dp[MAX_N][MAX_N];

int dpru(int *c, int *v) {
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= m; ++j) {
      dp[i + 1][j] = dp[i][j];
      if (j >= c[i])
        max_swap(dp[i + 1][j], dp[i + 1][j - c[i]] + v[i]);
    }
  }
  return dp[n][m];
}

int main() {
  while (cin >> n >> m) {
    rep(i, n) {
      cin.ignore();
      cin >> c[i];
      rep(j, 3) cin >> v[j][i];
    }
    int res = 0;
    rep(i, 3) max_swap(res, dpru(c, v[i]));
    cout << res << endl;
  }
  return 0;
}