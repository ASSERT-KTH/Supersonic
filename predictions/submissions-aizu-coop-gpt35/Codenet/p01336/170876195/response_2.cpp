#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define foreach(it, c) for (auto& it : c)
#define CLEAR(arr, val) std::fill(std::begin(arr), std::end(arr), val)

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int n, m;

int dpru(int *c, int *v) {
  int dp[333][333];
  CLEAR(dp, 0);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= m; ++j) {
      dp[i + 1][j] = dp[i][j];
      if (j >= c[i])
        dp[i + 1][j] = max(dp[i + 1][j], dp[i + 1][j - c[i]] + v[i]);
    }
  }
  return dp[n][m];
}

int main() {
  while (cin >> n >> m) {
    int c[333], v[999];
    n = min(n, 333);
    for (int i = 0; i < n; ++i) {
      int t;
      cin >> t;
      c[i] = t;
      for (int j = 0; j < 3; ++j)
        cin >> v[j * n + i];
    }
    int res = 0;
    int max_res = 0;
    for (int i = 0; i < 3; ++i)
      max_res = max(max_res, dpru(c, v + i * n));
    res = max_res;
    cout << res << endl;
  }
}