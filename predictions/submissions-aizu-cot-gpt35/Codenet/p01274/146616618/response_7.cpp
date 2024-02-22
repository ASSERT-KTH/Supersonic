#include <iostream>
#include <vector>
#include <limits>

#define INF std::numeric_limits<ll>::max()

typedef std::pair<int, int> P;
typedef long long ll;

int main() {
  int n, m;
  while (std::cin >> n && n) {
    std::vector<int> hp(n);
    for (int i = 0; i < n; i++)
      std::cin >> hp[i];
    
    std::vector<P> mg[2];
    std::cin >> m;
    mg[0].reserve(m);
    mg[1].reserve(m);
    for (int i = 0, cost, dam; i < m; i++) {
      std::string name, type;
      std::cin >> name >> cost >> type >> dam;
      if (dam)
        mg[type == "All"].push_back(P(dam, cost));
    }
    
    std::vector<std::vector<int>> dp(2, std::vector<int>(N + 10, 0));
    for (int k = 0; k < 2; k++)
      for (const auto& monster : mg[k])
        for (int j = monster.f; j <= N; j += monster.f)
          dp[k][j] = std::min(dp[k][j], dp[k][j - monster.f] + monster.s);
    
    for (int i = 0; i < 2; i++)
      for (int j = N; j > 0; j--)
        dp[i][j] = std::min(dp[i][j], dp[i][j + 1]);
    
    ll ans = INF;
    for (int i = 0; i <= mg[1].size(); i++) {
      ll cost = dp[1][i];
      for (int j = 0; j < n; j++)
        cost += dp[0][std::max(0, hp[j] - i)];
      ans = std::min(ans, cost);
    }
    
    std::cout << ans << std::endl;
  }
  
  return 0;
}