#include <iostream>
#include <vector>
#include <climits>

int main() {
  int n, m;
  while (std::cin >> n >> m, n) {
    std::vector<int> b;
    std::vector<int> a(n + 1);
    for (int i = 0; i < m; i++) {
      int x;
      std::cin >> x;
      b.emplace_back(x);
    }
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i];
    }
    
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(256, INT_MAX));
    dp[0][128] = 1;
    
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 256; j++) {
        if (dp[i][j] != INT_MAX) {
          for (int k = 0; k < m; k++) {
            int p = j + b[k];
            if (p > 255) p = 255;
            if (p < 0) p = 0;
            dp[i + 1][p] = std::min(dp[i + 1][p], dp[i][j] + (a[i + 1] - p) * (a[i + 1] - p));
          }
        }
      }
    }
    
    int p = INT_MAX;
    for (int i = 0; i < 256; i++) {
      if (dp[n][i] != INT_MAX) {
        p = std::min(p, dp[n][i]);
      }
    }
    
    std::cout << p - 1 << std::endl;
  }
}