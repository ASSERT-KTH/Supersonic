#include <iostream>
#include <algorithm>
using namespace std;

#define INF 100000000

int dp[256];

int main() {
  int n, m;
  while (cin >> n >> m, n) {
    int b[m];
    int a[n + 1];

    for (int i = 0; i < m; i++) {
      cin >> b[i];
    }

    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }

    for (int i = 0; i < 256; i++) {
      dp[i] = INF;
    }
    dp[128] = 1;

    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < 256; j++) {
        if (dp[j] != INF) {
          for (int k = 0; k < m; k++) {
            int p = j + b[k];
            if (__builtin_expect(p > 255, 0)) {
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
      if (dp[i] != INF) {
        p = min(p, dp[i]);
      }
    }

    cout << p - 1 << endl;
  }
}