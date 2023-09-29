#include <bits/stdc++.h>
using namespace std;
#define r(i, n) for (int i = 0; i < n; i++)
#define INF 100000000
int dp[20001][256];
main() {
  int n, m;
  while (cin >> n >> m, n) {
    int b[m];
    int a[n + 1];
    r(i, m) cin >> b[i];
    r(i, n) cin >> a[i + 1];
    r(i, n + 1) r(j, 256) dp[i][j] = INF;
    dp[0][128] = 1;
    r(i, n) r(j, 256) if (dp[i][j] != INF) r(k, m) {
      int p = j + b[k];
      if (p > 255)
        p = 255;
      if (p < 0)
        p = 0;
      dp[i + 1][p] = min(dp[i + 1][p], dp[i][j] + (a[i + 1] - p) * (a[i + 1] - p));
    }
    int p = 100000000;
    r(i, 256) if (dp[n][i] != INF) p = min(p, dp[n][i]);
    cout << p - 1 << endl;
  }
}
