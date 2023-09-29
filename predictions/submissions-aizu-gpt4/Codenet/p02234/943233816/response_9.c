#include <stdio.h>
#include <algorithm>
#include <vector>

const int INF = 1e9;
std::vector<std::vector<int>> dp;

int matrixChainOrder(const std::vector<int>& p) {
  const int n = p.size();
  for (int i = 0; i < n; ++i) {
    dp[i][i] = 0;
  }
  for (int l = 2; l < n; ++l) {
    for (int i = 0; i < n - l; ++i) {
      int j = i + l;
      dp[i][j] = INF;
      for (int k = i; k < j; ++k) {
        dp[i][j] = std::min(dp[i][j],
                            dp[i][k] + dp[k + 1][j] + p[i] * p[k + 1] * p[j + 1]);
      }
    }
  }
  return dp[0][n - 2];
}

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> p(n + 1);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &p[i]);
  }
  scanf("%d", &p[n]);
  
  dp.resize(n + 1, std::vector<int>(n + 1, 0));
  printf("%d\n", matrixChainOrder(p));
  return 0;
}