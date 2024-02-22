#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

#define CLEAR(arr, val) memset(arr, val, sizeof(arr))
#define rep(i, n) for (int i = 0; i < n; ++i)
template <class T> void max_swap(T &a, const T &b) { a = max(a, b); }

int dpru(int *c, int *v, int n, int m) {
  int dp[333][333];
  CLEAR(dp, 0);
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
  int n, m;
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
    rep(i, 3) max_swap(res, dpru(c, v[i], n, m));
    cout << res << '\n';
  }
}