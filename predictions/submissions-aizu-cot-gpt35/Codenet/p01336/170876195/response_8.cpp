#include <iostream>
#include <cstring>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)

int n, m;

int dpru(int *c, int *v) {
  int dp[333];
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; ++i) {
    for (int j = m; j >= c[i]; --j) {
      dp[j] = max(dp[j], dp[j - c[i]] + v[i]);
    }
  }
  return dp[m];
}

int main() {
  while (cin >> n >> m) {
    int c[333], v[3][333];
    rep(i, n) {
      int t;
      cin >> c[i];
      rep(j, 3) cin >> v[j][i];
    }
    int res = 0;
    rep(i, 3) res = max(res, dpru(c, v[i]));
    cout << res << endl;
  }
}