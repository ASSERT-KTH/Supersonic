#include <bits/stdc++.h>
using namespace std;

constexpr int inf = 1e9;
constexpr int64_t inf64 = 1e18;
constexpr double eps = 1e-9;

void solve(int n, int m) {
  vector<string> e(n);
  string ts;
  int concatenated_len = 0;
  for (int i = 0; i < n; ++i) {
    cin >> e[i];
    concatenated_len += e[i].size();
  }
  for (int i = 0; i < m; ++i) {
    string t;
    cin >> t;
    ts += t;
  }
  vector<int> sum_len(1 << n);
  for (int i = 0; i < 1 << n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (((i >> j) & 1) == 0)
        continue;
      sum_len[i] += e[j].size();
    }
  }
  static bool p[5000][1 << 12];
  fill_n((bool *)p, 5000 * (1 << 12), false);
  vector<vector<int>> heads(ts.size());
  for (int i = 0; i < ts.size(); ++i) {
    p[i][0] = true;
    for (int j = 0; j < n; ++j) {
      if (i + e[j].size() > ts.size() or e[j] != ts.substr(i, e[j].size()))
        continue;
      p[i][1 << j] = true;
      heads[i].push_back(j);
    }
  }
  int ans = 0;
  for (int i = ts.size() - 1; i >= 0; --i) {
    for (int j = 1; j < 1 << n; ++j) {
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
  cout << ans << endl;
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  cout.setf(ios::fixed);
  cout.precision(10);
  while (true) {
    int n, m;
    cin >> n >> m;
    if (n == 0 && m == 0)
      break;
    solve(n, m);
  }
  return 0;
}