#include <bits/stdc++.h>
using namespace std;
#define r(i, n) for (int i = 0; i < n; i++)
#define INF 100000000
int dp[2][256];
main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  while (cin >> n >> m, n) {
    int b[m];
    int a[n + 1];
    r(i, m) cin >> b[i];
    r(i, n) cin >> a[i + 1];
    r(j, 256) dp[0][j] = INF;
    dp[0][128] = 1;
    int curr = 1, prev = 0;
    r(i, n) {
      r(j, 256) dp[curr][j] = INF;
      r(j, 256) if (dp[prev][j] != INF) r(k, m) {
        int p = j + b[k];
        if (p > 255)
          p = 255;
        if (p < 0)
          p = 0;
        dp[curr][p] =
            min(dp[curr][p], dp[prev][j] + (a[i + 1] - p) * (a[i + 1] - p));
      }
      swap(curr, prev);
    }
    int p = 100000000;
    r(i, 256) if (dp[prev][i] != INF) p = min(p, dp[prev][i]);
    cout << p - 1 << endl;
  }
}