#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int n, m;
  while (cin >> n >> m, n) {
    vector<int> b(m);
    vector<int> a(n + 1);
    for (int i = 0; i < m; i++) {
      cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int dp[256];
    fill(dp, dp + 256, 100000000);
    dp[128] = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < 256; j++) {
        if (dp[j] != 100000000) {
          for (int k = 0; k < m; k++) {
            int p = j + b[k];
            if (p > 255) {
              p = 255;
            }
            if (p < 0) {
              p = 0;
            }
            dp[p] = min(dp[p], dp[j] + (a[i] - p) * (a[i] - p));
          }
        }
      }
    }
    int p = 100000000;
    for (int i = 0; i < 256; i++) {
      p = min(p, dp[i]);
    }
    cout << p - 1 << endl;
  }
  return 0;
}