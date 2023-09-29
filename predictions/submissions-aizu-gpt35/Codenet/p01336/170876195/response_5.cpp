#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 333;
int n, m;
int c[MAXN], v[3][MAXN], dp[MAXN];
int main() {
  while (cin >> n >> m) {
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i) {
      string s;
      int t;
      getline(cin, s);
      getline(cin, s);
      cin >> t;
      c[i] = t;
      for (int j = 0; j < 3; ++j) cin >> v[j][i];
    }
    for (int i = 0; i < n; ++i) {
      for (int j = m; j >= c[i]; --j) {
        for (int k = 0; k < 3; ++k) {
          dp[j] = max(dp[j], dp[j - c[i]] + v[k][i]);
        }
      }
    }
    int res = 0;
    for (int i = 1; i <= m; ++i) res = max(res, dp[i]);
    cout << res << endl;
  }
}