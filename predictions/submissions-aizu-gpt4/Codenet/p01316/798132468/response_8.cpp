#include <iostream>
#include <algorithm>
#define r(i, n) for (int i = 0; i < n; i++)
#define INF 100000000
int dp[20001][256];
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  while (std::cin >> n >> m, n) {
    int b[m];
    int a[n + 1];
    r(i, m) std::cin >> b[i];
    r(i, n) std::cin >> a[i + 1];
    std::fill(*dp, *dp + sizeof dp / sizeof **dp, INF);
    dp[0][128] = 0;
    r(i, n) r(j, 256) if (dp[i][j] != INF) r(k, m) {
      int p = std::clamp(j + b[k], 0, 255);
      dp[i + 1][p] = std::min(dp[i + 1][p], dp[i][j] + (a[i + 1] - p) * (a[i + 1] - p));
    }
    int p = *std::min_element(dp[n], dp[n] + 256);
    std::cout << p << '\n';
  }
}