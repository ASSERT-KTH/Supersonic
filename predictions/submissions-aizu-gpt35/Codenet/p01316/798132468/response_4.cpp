#include <bits/stdc++.h>
using namespace std;
#define r(i, n) for (int i = 0; i < n; i++)
#define INF 100000000
int dp[20001][256];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  while (cin >> n >> m, n) {
    int b[m], a[n + 1];
    r(i, m) cin >> b[i];
    r(i, n) cin >> a[i + 1];
    r(i, n + 1) r(j, 256) dp[i][j] = INF;
    dp[0][128] = 1;
    r(i, n) r(k, m) {
      int aj = a[i + 1]; // reduce memory accesses
      r(j, 256) {
        if (dp[i][j] != INF) {
          int p = j + b[k];
          p = (p > 255) ? 255 : (p < 0) ? 0 : p; // reduce conditional jumps
          int val = dp[i][j] + (aj - p) * (aj - p);
          dp[i + 1][p] = min(dp[i + 1][p], val);
        }
      }
    }
    int p = 100000000;
    r(i, 256) if (dp[n][i] != INF) p = min(p, dp[n][i]);
    cout << p - 1 << endl;
  }
  return 0;
}