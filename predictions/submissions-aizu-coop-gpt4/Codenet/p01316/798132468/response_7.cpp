#include <bits/stdc++.h>
using namespace std;
#define r(i, n) for (int i = 0; i < n; i++)
#define INF 100000000
int dp[2][256];

int main() {
  int n, m;
  while (cin >> n >> m, n) {
    vector<int> b(m), a(n + 1);
    r(i, m) cin >> b[i];
    for (int i = 1; i <= n; i++) cin >> a[i];
    fill(dp[0], dp[0]+256, INF);  // use std::fill to initialize dp array
    dp[0][128] = 1;
    for (int i = 0; i < n; i++) {
      fill(dp[(i+1)%2], dp[(i+1)%2]+256, INF);  // initialize the next dp array
      for (int j = 0; j < 256; j++) {
        if (dp[i%2][j] == INF) continue;  // skip if dp[i][j] equals INF
        for (int k = 0; k < m; k++) {
          int p = j + b[k];
          p = min(255, p);
          p = max(0, p);
          dp[(i+1)%2][p] = min(dp[(i+1)%2][p], dp[i%2][j] + (a[i+1] - p) * (a[i+1] - p));
        }
      }
    }
    int p = *min_element(dp[n%2], dp[n%2]+256);  // use std::min_element to find the minimal value
    cout << p - 1 << endl;
  }
  return 0;
}