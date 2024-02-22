#include <iostream>
#include <vector>
#include <algorithm>

inline void r(int i, int n) {
  for (int i = 0; i < n; i++)
}

inline int INF() {
  return 100000000;
}

int main() {
  int n, m;
  while (std::cin >> n >> m, n) {
    std::vector<int> b(m);
    std::vector<int> a(n + 1);
    r(i, m) std::cin >> b[i];
    r(i, n) std::cin >> a[i + 1];
    
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(256, INF()));
    dp[0][128] = 1;
    
    r(i, n) r(j, 256) {
      if (dp[i][j] != INF()) {
        r(k, m) {
          int p = j + b[k];
          if (p > 255)
            p = 255;
          if (p < 0)
            p = 0;
          dp[i + 1][p] = std::min(dp[i + 1][p], dp[i][j] + (a[i + 1] - p) * (a[i + 1] - p));
        }
      }
    }
    
    auto minIt = std::min_element(dp[n].begin(), dp[n].end());
    int p = *minIt;
    
    if (p != INF()) {
      std::cout << p - 1 << std::endl;
    }
  }
}