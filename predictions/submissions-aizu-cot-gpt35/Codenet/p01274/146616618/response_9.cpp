#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

constexpr int INF = 1e9;
constexpr int N = 100000;

int main() {
  int n, m;
  std::vector<int> hp;
  hp.reserve(101);
  
  while (std::cin >> n, n) {
    hp.resize(n);
    for (int i = 0; i < n; i++)
      std::cin >> hp[i];
    
    std::vector<std::pair<int, int>> mg[2];
    mg[0].reserve(m);
    mg[1].reserve(m);
    
    std::cin >> m;
    for (int i = 0, cost, dam; i < m; i++) {
      std::string name, type;
      std::cin >> name >> cost >> type >> dam;
      if (dam)
        mg[type == "All"].emplace_back(dam, cost);
    }
    
    int dp[2][N + 1] = {};
    for (int i = 0; i < 2; i++)
      std::fill(dp[i], dp[i] + N + 1, INF);
    
    for (int k = 0; k < 2; k++) {
      for (const auto& p : mg[k]) {
        for (int i = p.f, j = (N / p.f + 1) * p.f; i <= j; ++i) {
          dp[k][std::min(N, i)] = std::min(dp[k][std::min(N, i)], dp[k][i - p.f] + p.s);
        }
      }
    }
    
    for (int i = 0; i < 2; i++) {
      for (int j = N; j >= 0; j--) {
        dp[i][j] = std::min(dp[i][j], dp[i][j + 1]);
      }
    }
    
    int64_t ans = INF;
    for (int i = 0; i <= N; i++) {
      int64_t cost = dp[1][i];
      cost += std::accumulate(hp.begin(), hp.end(), 0LL, [i](int64_t sum, const auto& val) {
        return sum + dp[0][std::max(0, val - i)];
      });
      ans = std::min(ans, cost);
    }
    
    std::cout << ans << '\n';
  }
  
  return 0;
}