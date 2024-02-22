#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void solve(int n, int m) {
  std::vector<std::string> e(n);
  std::string ts;
  int concatenated_len = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> e[i];
    concatenated_len += e[i].size();
  }
  for (int i = 0; i < m; ++i) {
    std::string t;
    std::cin >> t;
    ts += t;
  }
  std::vector<int> sum_len(1 << n);
  for (int i = 0; i < (1 << n); ++i) {
    for (int j = 0; j < n; ++j) {
      if (((i >> j) & 1) == 0)
        continue;
      sum_len[i] += e[j].size();
    }
  }
  std::vector<std::vector<int>> heads(ts.size());
  std::vector<std::vector<bool>> p(ts.size(), std::vector<bool>(1 << n, false));
  for (int i = 0; i < ts.size(); ++i) p[i][0] = true;
  for (int i = 0; i < ts.size(); ++i) {
    for (int j = 0; j < n; ++j) {
      if (i + e[j].size() > ts.size() || !std::equal(e[j].begin(), e[j].end(), ts.begin() + i))
        continue;
      p[i][1 << j] = true;
      heads[i].push_back(j);
    }
  }
  int ans = 0;
  for (int i = ts.size() - 1; i >= 0; --i) {
    for (int j = 1; j < (1 << n); ++j) {
      if (p[i][j] || i + sum_len[j] > ts.size())
        continue;
      for (int k : heads[i]) {
        if (((j >> k) & 1) == 0)
          continue;
        int i2 = i + e[k].size();
        if (p[i2][j & (~(1 << k))]) {
          p[i][j] = true;
          break;
        }
      }
    }
    if (p[i][(1 << n) - 1])
      ++ans;
  }
  std::cout << ans << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cout.setf(std::ios::fixed);
  std::cout.precision(10);
  for (;;) {
    int n, m;
    std::cin >> n >> m;
    if (n == 0 && m == 0)
      break;
    solve(n, m);
  }
  return 0;
}