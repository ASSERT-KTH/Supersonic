#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 333;
const int MAXM = 10003;

int n, m, res;
int c[MAXN], v[3][MAXN];
int dp[MAXM];

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
      rep(j, 3) cin >> v[j][i];
    }
    for (int i = 0; i < n; ++i) {
      for (int j = m; j >= c[i]; --j) {
        max_swap(dp[j], dp[j-c[i]] + v[0][i]);
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = m; j >= c[i]; --j) {
        max_swap(dp[j], dp[j-c[i]] + v[1][i]);
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = m; j >= c[i]; --j) {
        max_swap(dp[j], dp[j-c[i]] + v[2][i]);
      }
    }
    for (int i = 1; i <= m; ++i) {
      max_swap(res, dp[i]);
    }
    cout << res << endl;
  }
  return 0;
}