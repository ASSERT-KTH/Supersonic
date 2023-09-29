#include <algorithm>
#include <iostream>
#include <vector>
#define REP(i, k, n) for (int i = k; i < n; i++)
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
typedef std::pair<int, int> P;
ll d[15][2005], dp[2005][2005];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, K;
  std::cin >> n >> K;
  std::vector<int> id, v[2005];
  rep(i, n) {
    int a, b;
    std::cin >> a >> b;
    id.push_back(b - 1);
    v[b - 1].push_back(a);
  }
  std::sort(id.begin(), id.end());
  id.erase(std::unique(id.begin(), id.end()), id.end());
  rep(i, id.size()) {
    int j = id[i];
    std::sort(v[j].begin(), v[j].end(), std::greater<int>());
  }
  std::fill(&d[0][0], &d[0][0] + sizeof(d) / sizeof(ll), 0);
  std::vector<P> p;
  rep(i, id.size()) {
    int j = id[i];
    REP(k, 1, v[j].size() + 1) {
      d[j][k] += d[j][k - 1] + v[j][k - 1] + (k - 1) * 2;
      p.emplace_back(k, d[j][k]);
    }
  }
  std::fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(ll), 0);
  rep(i, id.size()) {
    rep(j, K + 1) {
      ll res = dp[i][j];
      rep(k, v[id[i]].size() + 1) {
        if (j >= k) {
          res = std::max(res, dp[i][j - k] + d[id[i]][k]);
        }
      }
      dp[i + 1][j] = res;
    }
  }
  std::cout << dp[id.size()][K] << '\n';
  return 0;
}