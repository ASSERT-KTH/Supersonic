#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

constexpr int INF = 100000000;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  
  int n, m;
  while (std::cin >> n >> m, n) {
    std::vector<int> b(m);
    std::vector<int> a(n + 1);
    for (auto& el : b) std::cin >> el;
    for (int i = 1; i <= n; i++) std::cin >> a[i];
    
    std::array<std::array<int, 256>, 20001> dp;
    for (auto& row : dp) std::fill(row.begin(), row.end(), INF);
    dp[0][128] = 1;
    
    for (int i = 0; i < n; i++) 
      for (int j = 0; j < 256; j++) 
        if (dp[i][j] != INF) 
          for (const auto& k : b) {
            int p = j + k;
            p = std::max(0, std::min(255, p));
            dp[i + 1][p] = std::min(dp[i + 1][p], dp[i][j] + (a[i + 1] - p) * (a[i + 1] - p));
          }
    
    int p = INF;
    for (const auto& el : dp[n])
      if (el != INF) p = std::min(p, el);
    std::cout << p - 1 << '\n';
  }
  return 0;
}