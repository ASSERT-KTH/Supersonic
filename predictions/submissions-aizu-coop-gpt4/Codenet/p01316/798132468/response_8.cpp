#include <bits/stdc++.h>
using namespace std;
#define r(i, n) for (int i = 0; i < n; i++)
#define INF 1000000000
int dp[20001][256];
int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) != EOF, n) {
    int b[m];
    int a[n + 1];
    r(i, m) scanf("%d", &b[i]);
    r(i, n) scanf("%d", &a[i + 1]);
    r(i, n + 1) r(j, 256) dp[i][j] = -INF;
    dp[0][128] = 1;
    r(i, n) r(j, 256) if (dp[i][j] > -INF) r(k, m) {
      int p = j + b[k];
      if (p > 255)
        p = 255;
      if (p < 0)
        p = 0;
      int diff = (a[i + 1] - p) * (a[i + 1] - p);  // Calculate once
      dp[i + 1][p] = max(dp[i + 1][p], dp[i][j] + diff);
    }
    int p = -INF;
    r(i, 256) if (dp[n][i] > -INF) p = max(p, dp[n][i]);
    printf("%d\n", p - 1);
  }
  return 0;
}