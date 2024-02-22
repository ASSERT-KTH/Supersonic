#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

const int MAX_N = 333;
const int MAX_M = 333;

int dp[MAX_M];
int n, m;

int dpru(int *c, int *v) {
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= m; ++j) {
      dp[j] = max(dp[j], (j >= c[i] ? dp[j - c[i]] + v[i] : 0));
    }
  }
  return dp[m];
}

int main() {
  while (cin >> n >> m) {
    int c[MAX_N], v[3][MAX_N];
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