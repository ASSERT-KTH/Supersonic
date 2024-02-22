#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n, m;
  while (cin >> n >> m, n) {
    vector<int> b(m);
    vector<int> a(n + 1);
    for (int i = 0; i < m; i++) {
      cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(256, INT_MAX));
    dp[0][128] = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 256; j++) {
        if (dp[i][j] != INT_MAX) {
          for (int k = 0; k < m; k++) {
            int p = max(0, min(255, j + b[k]));
            dp[i + 1][p] = min(dp[i + 1][p], dp[i][j] + (a[i + 1] - p) * (a[i + 1] - p));
          }
        }
      }
    }
    int p = INT_MAX;
    for (int i = 0; i < 256; i++) {
      if (dp[n][i] != INT_MAX) {
        p = min(p, dp[n][i]);
      }
    }
    cout << p << endl;
  }
  return 0;
}