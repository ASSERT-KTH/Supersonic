#include <iostream>
#include <vector>
#include <limits>

const int INF = std::numeric_limits<int>::max();
const int N = 100000;

int main() {
  int n, m;
  while (std::cin >> n, n) {
    std::vector<int> hp(n);
    for (int i = 0; i < n; i++)
      std::cin >> hp[i];
    
    std::vector<int> mg_all;
    std::vector<int> mg_single;
    
    std::cin >> m;
    for (int i = 0; i < m; i++) {
      std::string name, type;
      int cost, dam;
      std::cin >> name >> cost >> type >> dam;
      if (dam) {
        if (type == "All")
          mg_all.push_back(cost);
        else
          mg_single.push_back(cost);
      }
    }
    
    int dp[2][N] = {};
    for (int i = 0; i < 2; i++)
      for (int j = 1; j < N; j++)
        dp[i][j] = INF;
    
    for (int k = 0; k < 2; k++) {
      for (int i = 0; i < mg_all.size(); i++) {
        for (int j = mg_all[i]; j <= N; j++) {
          dp[k][j] = std::min(dp[k][j], dp[k][j - mg_all[i]] + mg_all[i]);
        }
      }
    }
    
    for (int i = 0; i < 2; i++) {
      for (int j = N - 1; j >= 0; j--) {
        dp[i][j] = std::min(dp[i][j], dp[i][j + 1]);
      }
    }
    
    int max_hp_diff[100];
    for (int j = 0; j < n; j++) {
      max_hp_diff[j] = hp[j];
      for (int i = 0; i < mg_single.size(); i++) {
        max_hp_diff[j] = std::max(max_hp_diff[j], hp[j] - mg_single[i]);
      }
    }
    
    int ans = INF;
    for (int i = 0; i < N; i++) {
      int cost = dp[1][i];
      for (int j = 0; j < n; j++) {
        cost += dp[0][max_hp_diff[j]];
      }
      ans = std::min(ans, cost);
    }
    
    std::cout << ans << std::endl;
  }
  
  return 0;
}