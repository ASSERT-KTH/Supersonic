#include <iostream>
#include <vector>
#include <climits>
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
    dp[0][128] = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 256; j++) {
        if (dp[i][j] != INT_MAX) {
          for (int k = 0; k < m; k++) {
            int p = j + b[k];
            if (p > 255) {
              p = 255;
            }
            if (p < 0) {
              p = 0;
            }
            dp[i + 1][p] = min(dp[i + 1][p], dp[i][j] + (a[i + 1] - p) * (a[i + 1] - p));
          }
        }
      }
    }
    int min_cost = INT_MAX;
    for (int i = 0; i < 256; i++) {
      if (dp[n][i] != INT_MAX) {
        min_cost = min(min_cost, dp[n][i]);
      }
    }
    cout << min_cost - 1 << endl;
  }
}