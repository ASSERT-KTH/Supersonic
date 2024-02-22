#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
typedef long long ll;
int n, m;
int dp[333][333];

int dpru(int *c, int *v) {
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; ++i) {
    for (int j = c[i]; j <= m; ++j) {
      dp[i + 1][j] = max(dp[i + 1][j], dp[i + 1][j - c[i]] + v[i]);
    }
  }
  return dp[n][m];
}

int main() {
  while (cin >> n >> m) {
    int c[333], v[3][333];
    rep(i, n) {
      string s;
      int t;
      getline(cin, s);
      getline(cin, s);
      cin >> t;
      c[i] = t;
      rep(j, 3) cin >> v[j][i];
    }
    int res = 0;
    rep(i, 3) res = max(res, dpru(c, v[i]));
    cout << res << endl;
  }
}