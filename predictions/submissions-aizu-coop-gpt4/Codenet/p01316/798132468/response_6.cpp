#include <bits/stdc++.h>
using namespace std;
#define r(i, n) for (int i = 0; i < n; i++)
#define INF 100000000

int main() {
  int n, m;
  while (cin >> n >> m, n) {
    vector<int> b(m);
    vector<int> a(n + 1);
    r(i, m) cin >> b[i];
    r(i, n) cin >> a[i + 1];
    vector<vector<int>> dp(n + 1, vector<int>(256, INF));
    dp[0][128] = 1;

    r(i, n) r(j, 256) r(k, m) {
      int p = j + b[k];
      p = min(max(p, 0), 255);
      int cost = (a[i + 1] - p) * (a[i + 1] - p);
      dp[i + 1][p] = min(dp[i + 1][p], dp[i][j] + cost);
    }

    int p = *min_element(dp[n].begin(), dp[n].end());
    cout << p - 1 << endl;
  }
  return 0;
}