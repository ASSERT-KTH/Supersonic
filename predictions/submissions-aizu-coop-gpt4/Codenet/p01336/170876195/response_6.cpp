#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int n, m;

int dpru(vi &c, vvi &v) {
  vvi dp(n+1, vi(m+1, 0));
  int res = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= m; ++j) {
      dp[i+1][j] = dp[i][j];
      if (j >= c[i]) {
        for(int k = 0; k < 3; ++k){
          dp[i + 1][j] = max(dp[i + 1][j], dp[i + 1][j - c[i]] + v[k][i]);
          res = max(res, dp[i + 1][j]);
        }
      }
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  while (cin >> n >> m) {
    vi c(n);
    vvi v(3, vi(n));
    for(int i = 0; i < n; ++i) {
      cin >> c[i];
      for(int j = 0; j < 3; ++j) cin >> v[j][i];
    }
    int res = dpru(c, v);
    cout << res << "\n";
  }
  return 0;
}