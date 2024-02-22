#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int n, m;

int dpru(int *c, int *v) {
  int dp[333][333];
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= m; ++j) {
      dp[i + 1][j] = dp[i][j];
      if (j >= c[i]) {
        int temp = dp[i + 1][j - c[i]] + v[i];
        if (temp > dp[i + 1][j]) {
          dp[i + 1][j] = temp;
        }
      }
    }
  }
  return dp[n][m];
}

int main() {
  while (cin >> n >> m) {
    int c[333], v[999];
    memset(c, 0, sizeof(c));
    memset(v, 0, sizeof(v));
    rep(i, n) {
      string s;
      int t;
      getline(cin, s);
      getline(cin, s);
      cin >> t;
      c[i] = t;
      rep(j, 3) cin >> v[i + j * n];
    }
    int res = 0;
    rep(i, 3) {
      int temp = dpru(c, v + i * n);
      if (temp > res) {
        res = temp;
      }
    }
    cout << res << endl;
  }
}