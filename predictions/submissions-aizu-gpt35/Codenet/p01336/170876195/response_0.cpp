#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int MAX_N = 330;

int n, m;
int c[MAX_N], v[MAX_N][3];
int dp[MAX_N][MAX_N];

int dpru(int *c, int *v) {
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      dp[i][j] = dp[i - 1][j];
      if (j >= c[i - 1])
        dp[i][j] = max(dp[i][j], dp[i][j - c[i - 1]] + v[i - 1][0] + v[i - 1][v[i - 1][j - c[i - 1]]] + v[i - 1][v[i - 1][j - c[i - 1]]]);
    }
  }
  return dp[n][m];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  while (cin >> n >> m) {
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i) {
      string s;
      int t;
      getline(cin, s);
      getline(cin, s);
      cin >> t;
      c[i] = t;
      for (int j = 0; j < 3; ++j)
        cin >> v[i][j];
    }
    int res = 0;
    for (int i = 0; i < 3; ++i)
      res = max(res, dpru(c, v[i]));
    cout << res << '\n';
  }
  return 0;
}