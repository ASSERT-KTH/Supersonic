#include <iostream>
#include <vector>
#include <algorithm>

#define INF 100000000

int main() {
  int n, m;
  while (std::cin >> n >> m, n) {
    std::vector<int> b(m);
    std::vector<int> a(n + 1);
    for (int i = 0; i < m; i++) std::cin >> b[i];
    for (int i = 0; i < n; i++) std::cin >> a[i + 1];
    
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(256, INF));
    dp[0][128] = 1;
    
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 256; j++) {
        if (dp[i][j] != INF) {
          for (int k = 0; k < m; k++) {
            int p = j + b[k];
            p = std::max(std::min(p, 255), 0);
            dp[i + 1][p] = std::min(dp[i + 1][p], dp[i][j] + (a[i + 1] - p) * (a[i + 1] - p));
          }
        }
      }
    }
    
    int p = dp[n][0];
    for (int i = 1; i < 256; i++) {
      if (dp[n][i] != INF) p = std::min(p, dp[n][i]);
    }
    std::cout << p - 1 << std::endl;
  }
  return 0;
}