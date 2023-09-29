#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int MAX_N = 333;
const int MAX_M = 10001;
int n, m;
int c[MAX_N], v[3][MAX_N];
int dp[MAX_M];
int dpru(int *c, int *v) {
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; ++i) {
    for (int j = m; j >= c[i]; --j) {
      dp[j] = max(dp[j], dp[j - c[i]] + v[i]);
    }
  }
  return dp[m];
}
int main() {
  while (cin >> n >> m) {
    for (int i = 0; i < n; ++i) {
      string s;
      int t;
      getline(cin, s);
      getline(cin, s);
      cin >> t;
      c[i] = t;
      for (int j = 0; j < 3; ++j) {
        cin >> v[j][i];
      }
    }
    int res = 0;
    for (int i = 0; i < 3; ++i) {
      res = max(res, dpru(c, v[i]));
    }
    cout << res << endl;
  }
}