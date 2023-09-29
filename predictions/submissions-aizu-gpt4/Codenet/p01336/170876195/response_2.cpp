#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::max;
using std::string;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define CLEAR(arr, val) memset(arr, val, sizeof(arr))

int n, m;
int dpru(int *c, int *v) {
  int dp[333];
  CLEAR(dp, 0);
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