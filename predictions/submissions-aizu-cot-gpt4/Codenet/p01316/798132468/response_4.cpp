#include <cstdio>
#include <algorithm>
#define r(i, n) for (int i = 0; i < n; i++)
#define INF 100000000

int dp[20001][256];
int minJ[20001];
int maxJ[20001];

int main() {
  int n, m;
  std::fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(int), INF);
  while (scanf("%d%d", &n, &m), n) {
    int b[m];
    int a[n + 1];
    r(i, m) scanf("%d", &b[i]);
    r(i, n) scanf("%d", &a[i + 1]);

    std::fill(minJ, minJ+n+1, 256);
    std::fill(maxJ, maxJ+n+1, 0);

    dp[0][128] = 1;
    minJ[0] = maxJ[0] = 128;
    r(i, n) for (int j = minJ[i]; j <= maxJ[i]; ++j) r(k, m) {
      int p = std::clamp(j + b[k], 0, 255);
      dp[i + 1][p] = std::min(dp[i + 1][p], dp[i][j] + (a[i + 1] - p) * (a[i + 1] - p));
      minJ[i + 1] = std::min(minJ[i + 1], p);
      maxJ[i + 1] = std::max(maxJ[i + 1], p);
    }
    int p = *std::min_element(dp[n] + minJ[n], dp[n] + maxJ[n] + 1);
    printf("%d\n", p - 1);
  }
  return 0;
}