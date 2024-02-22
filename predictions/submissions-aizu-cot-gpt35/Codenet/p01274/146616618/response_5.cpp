#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#define INF 1e9

typedef std::pair<int, int> P;
typedef long long ll;

int main() {
  int n, m;
  while (std::cin >> n, n) {
    std::vector<int> hp(n);
    for (int i = 0; i < n; i++)
      std::cin >> hp[i];
    std::unordered_map<int, std::vector<P>> mg;
    std::cin >> m;
    for (int i = 0, cost, dam; i < m; i++) {
      std::string name, type;
      std::cin >> name >> cost >> type >> dam;
      if (dam)
        mg[type == "All"].push_back(P(dam, cost));
    }
    std::vector<std::vector<int>> dp(2, std::vector<int>(n + 10, INF));
    for (int k = 0; k < 2; k++)
      for (int i = 0; i < mg[k].size(); i++)
        for (int j = mg[k][i].first; j <= (n / mg[k][i].first + 1) * mg[k][i].first; j++)
          dp[k][std::min(n, j)] = std::min(dp[k][std::min(n, j)], dp[k][j - mg[k][i].first] + mg[k][i].second);
    for (int i = 0; i < 2; i++)
      std::transform(dp[i].rbegin(), dp[i].rend() - 1, dp[i].rbegin() + 1, dp[i].rbegin(), [](int x, int y) { return std::min(x, y); });
    ll ans = INF;
    for (int i = 0; i <= n; i++) {
      ll cost = dp[1][i];
      cost += std::accumulate(dp[0].begin(), dp[0].end(), 0LL, [i](ll x, int y) { return x + std::max(0, hp[y] - i); });
      ans = std::min(ans, cost);
    }
    std::cout << ans << std::endl;
  }
  return 0;
}