#include <bits/stdc++.h>
using namespace std;
#define r(i, n) for (int i = 0; i < n; i++)
#define INF 100000000
int dp[256];
main() {
  int n, m;
  while (cin >> n >> m, n) {
    int b[m];
    int a[n + 1];
    r(i, m) cin >> b[i];
    r(i, n) cin >> a[i + 1];
    fill(dp, dp + 256, INF);
    dp[128] = 1;
    r(i, n) {
      int dp_next[256];
      fill(dp_next, dp_next + 256, INF);
      r(j, 256) if (dp[j] != INF) {
        int min_p = max(0, j - b[m - 1]);
        int max_p = min(255, j + b[0]);
        for (int p = min_p; p <= max_p; p++) {
          int diff = (a[i + 1] - p) * (a[i + 1] - p);
          dp_next[p] = min(dp_next[p], dp[j] + diff);
        }
      }
      copy(dp_next, dp_next + 256, dp);
    }
    int p = 100000000;
    r(i, 256) if (dp[i] != INF) p = min(p, dp[i]);
    cout << p - 1 << endl;
  }
}