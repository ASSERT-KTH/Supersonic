#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)

template <class T> void max_swap(T &a, const T &b) { a = max(a, b); }

int dpru(const vector<int>& c, const vector<vector<int>>& v, int m) {
  vector<vector<int>> dp(c.size() + 1, vector<int>(m + 1, 0));
  int res = 0;
  for (int i = 0; i < c.size(); ++i) {
    for (int j = 0; j <= m; ++j) {
      dp[i + 1][j] = dp[i][j];
      if (j >= c[i])
        max_swap(dp[i + 1][j], dp[i + 1][j - c[i]] + v[i]);
      max_swap(res, dp[i + 1][j]);
    }
  }
  return res;
}

int main() {
  int n, m;
  while (cin >> n >> m) {
    vector<int> c(n);
    vector<vector<int>> v(3, vector<int>(n));
    rep(i, n) {
      string s;
      cin >> s >> c[i] >> v[0][i] >> v[1][i] >> v[2][i];
    }
    cout << dpru(c, v, m) << endl;
  }
}