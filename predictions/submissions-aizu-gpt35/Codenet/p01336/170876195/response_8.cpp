#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 333;
const int MAXM = 10003;
int n, m, c[MAXN], v[3][MAXN], dp[MAXM];
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
      for (int j = 0; j < 3; ++j) cin >> v[j][i];
    }
    for (int i = 0; i < n; ++i)
      for (int j = c[i]; j <= m; ++j) {
        for (int k = 0; k < 3; ++k) {
          if (j >= c[i]) {
            dp[j] = max(dp[j], dp[j - c[i]] + v[k][i]);
          }
        }
      }
    cout << dp[m] << endl;
  }
  return 0;
}