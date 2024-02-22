#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 100000000;

int main() {
  int n, m;
  while (cin >> n >> m, n) {
    vector<int> b(m);
    vector<int> a(n + 1);
    for (int i = 0; i < m; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<vector<int>> dp(n + 1, vector<int>(256, INF));
    dp[0][128] = 1;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 256; j++) {
        if (dp[i][j] != INF) {
          int dp_ij = dp[i][j];
          for (int k = 0; k < m; k++) {
            int p = j + b[k];
            if (p > 255) p = 255;
            if (p < 0) p = 0;
            dp[i + 1][p] = min(dp[i + 1][p], dp_ij + (a[i + 1] - p) * (a[i + 1] - p));
          }
        }
      }
    }

    int p = 100000000;
    for (int i = 0; i < 256; i++) {
      if (dp[n][i] != INF) p = min(p, dp[n][i]);
    }
    cout << p - 1 << endl;
  }
  return 0;
}