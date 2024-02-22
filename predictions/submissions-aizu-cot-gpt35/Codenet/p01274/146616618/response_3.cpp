#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <algorithm>

constexpr int INF = 1e9;
constexpr int N = 100000;

int main() {
  int n, m;
  std::array<int, 101> hp;

  while (std::cin >> n, n) {
    for (int i = 0; i < n; i++)
      std::cin >> hp[i];

    std::vector<std::pair<int, int>> mg[2];
    std::cin >> m;
    for (int i = 0, cost, dam; i < m; i++) {
      std::string name, type;
      std::cin >> name >> cost >> type >> dam;
      if (dam)
        mg[type == "All"].emplace_back(dam, cost);
    }

    std::array<std::array<int, N + 10>, 2> dp = {};
    for (int i = 0; i < 2; i++)
      for (int j = 1; j < N + 10; j++)
        dp[i][j] = INF;

    for (int k = 0; k < 2; k++)
      for (const auto& p : mg[k])
        for (int j = p.first; j <= (N / p.first + 1) * p.first; j++)
          dp[k][std::min(N, j)] =
              std::min(dp[k][std::min(N, j)], dp[k][j - p.first] + p.second);

    for (int i = 0; i < 2; i++)
      for (int j = N; j >= 0; j--)
        dp[i][j] = std::min(dp[i][j], dp[i][j + 1]);

    int max_hp = *std::max_element(hp.begin(), hp.begin() + n);
    int ans = INF;

    for (int i = 0; i <= N; i++) {
      int cost = dp[1][i];
      for (int j = 0; j < n; j++)
        cost += dp[0][std::max(0, hp[j] - i)];
      ans = std::min(ans, cost);
    }

    std::cout << ans << '\n';
  }

  return 0;
}