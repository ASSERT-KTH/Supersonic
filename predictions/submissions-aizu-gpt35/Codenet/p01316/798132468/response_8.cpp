#include <bits/stdc++.h>
using namespace std;
#define r(i, n) for (int i = 0; i < n; i++)
#define INF 100000000
const int maxn = 20005, maxm = 256;
int dp[2][maxm];
main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  while (cin >> n >> m, n) {
    int b[m];
    int a[n + 1];
    r(i, m) cin >> b[i];
    r(i, n) cin >> a[i + 1];
    r(i, maxm) dp[0][i] = INF;
    dp[0][128] = 1;
    for (int i = 1; i <= n; i++) {
      r(j, maxm) dp[i % 2][j] = INF;
      r(j, maxm) if (dp[(i - 1) % 2][j] != INF) r(k, m) {
        int p = j + b[k];
        if (p > 255)
          p = 255;
        if (p < 0)
          p = 0;
        dp[i % 2][p] =
            min(dp[i % 2][p], dp[(i - 1) % 2][j] + (a[i] - p) * (a[i] - p));
      }
    }
    int p = 100000000;
    r(i, maxm) if (dp[n % 2][i] != INF) p = min(p, dp[n % 2][i]);
    cout << p - 1 << endl;
  }
}