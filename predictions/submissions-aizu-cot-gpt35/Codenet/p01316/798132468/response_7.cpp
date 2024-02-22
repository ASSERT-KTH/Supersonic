#include <iostream>
#include <cstring>
using namespace std;

const int INF = 100000000;

int dp[20001][256];

int main() {
  int n, m;
  while (cin >> n >> m, n) {
    int b[m];
    int a[n + 1];
    for (int i = 0; i < m; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) cin >> a[i];

    memset(dp, INF, sizeof(dp));
    dp[0][128] = 1;

    for (int i = 0; i < n; i++) {
      for (int j = max(0, a[i + 1] - b[0]); j <= min(255, a[i + 1] + b[0]); j++) {
        if (dp[i][j] != INF) {
          int tmp = a[i + 1] - j;
          dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + tmp * tmp);
        }
      }
      for (int k = 1; k < m; k++) {
        for (int j = max(0, a[i + 1] - b[k]); j <= min(255, a[i + 1] + b[k]); j++) {
          if (dp[i][j] != INF) {
            int tmp = a[i + 1] - j;
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + tmp * tmp);
          }
        }
      }
    }

    int p = INF;
    for (int i = 0; i < 256; i++) {
      p = min(p, dp[n][i]);
    }
    cout << p - 1 << endl;
  }
}