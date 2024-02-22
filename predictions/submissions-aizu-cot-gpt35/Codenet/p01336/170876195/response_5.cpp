#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int dpru(const vector<int>& c, const vector<vector<int>>& v) {
  int n = c.size();
  int m = v[0].size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= m; ++j) {
      dp[i + 1][j] = dp[i][j];
      if (j >= c[i]) {
        dp[i + 1][j] = max(dp[i + 1][j], dp[i + 1][j - c[i]] + v[i][j]);
      }
    }
  }
  return dp[n][m];
}

int main() {
  int n, m;
  while (cin >> n >> m) {
    cin.ignore();
    vector<int> c(n);
    vector<vector<int>> v(3, vector<int>(n));

    for (int i = 0; i < n; ++i) {
      string s;
      getline(cin, s);
      istringstream iss(s);
      int t;
      iss >> t;
      c[i] = t;
      for (int j = 0; j < 3; ++j) {
        iss >> v[j][i];
      }
    }

    int res = 0;
    for (int i = 0; i < 3; ++i) {
      res = max(res, dpru(c, v));
    }
    cout << res << endl;
  }
}