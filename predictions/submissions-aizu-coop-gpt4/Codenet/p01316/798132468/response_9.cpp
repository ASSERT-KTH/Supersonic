#include <bits/stdc++.h>
using namespace std;
#define r(i, n) for (int i = 0; i < n; i++)
#define INF 100000000

unordered_map<pair<int, int>, int> dp;
main() {
  int n, m;
  while (cin >> n >> m, n) {
    int b[m];
    int a[n + 1];
    r(i, m) cin >> b[i];
    r(i, n) cin >> a[i + 1];
    dp[{0,128}] = 1;
    r(i, n) r(j, 256) if (dp[{i, j}] != INF) r(k, m) {
      int p = j + b[k];
      if (p > 255)
        p = 255;
      if (p < 0)
        p = 0;
      int diff = (a[i + 1] - p) * (a[i + 1] - p);
      dp[{i + 1, p}] = min(dp[{i + 1, p}], dp[{i, j}] + diff);
    }
    int p = 100000000;
    r(i, 256) if (dp[{n, i}] != INF) p = min(p, dp[{n, i}]);
    cout << p - 1 << endl;
  }
}