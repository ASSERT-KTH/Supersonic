#include <algorithm>
#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < n; ++i)

int n, m;

int dpru(const std::vector<int>& c, const std::vector<int>& v) {
  std::vector<int> dp(m + 1, 0);
  for (int i = 0; i < n; ++i) {
    for (int j = m; j >= c[i]; --j) {
      dp[j] = std::max(dp[j], dp[j - c[i]] + v[i]);
    }
  }
  return dp[m];
}

int main() {
  while (std::cin >> n >> m) {
    std::vector<int> c(n);
    std::vector<std::vector<int>> v(3, std::vector<int>(n));

    rep(i, n) {
      std::string s;
      int t;
      std::getline(std::cin, s);
      std::getline(std::cin, s);
      std::cin >> t;
      c[i] = t;
      rep(j, 3) std::cin >> v[j][i];
    }

    int res = 0;
    rep(i, 3) res = std::max(res, dpru(c, v[i]));
    std::cout << res << std::endl;
  }
}