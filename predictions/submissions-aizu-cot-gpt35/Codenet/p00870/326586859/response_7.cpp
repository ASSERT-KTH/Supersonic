#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void solve(int n, int m) {
  vector<string> e(n);
  int concatenated_len = 0;
  for (int i = 0; i < n; ++i) {
    cin >> e[i];
    concatenated_len += e[i].size();
  }
  vector<string> ts_vec;
  ts_vec.reserve(m);
  for (int i = 0; i < m; ++i) {
    string t;
    cin >> t;
    ts_vec.push_back(t);
  }
  vector<int> sum_len;
  sum_len.reserve(1 << n);
  for (int i = 0; i < (1 << n); ++i) {
    int len = 0;
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1)
        len += e[j].size();
    }
    sum_len.push_back(len);
  }
  vector<vector<bool>> p(ts_vec.size(), vector<bool>(1 << n));
  vector<vector<int>> heads(ts_vec.size());
  for (int i = 0; i < ts_vec.size(); ++i) {
    p[i][0] = true;
    for (int j = 0; j < n; ++j) {
      if (i + e[j].size() > ts_vec.size() || e[j] != ts_vec[i].substr(0, e[j].size()))
        continue;
      p[i][pow(2, j)] = true;
      heads[i].push_back(j);
    }
  }
  int ans = 0;
  for (int i = ts_vec.size() - 1; i >= 0; --i) {
    for (int j = 1; j < (1 << n); ++j) {
      if (p[i][j] || i + sum_len[j] > ts_vec.size())
        continue;
      int k_count = __builtin_popcount(j);
      for (int k : heads[i]) {
        if (k_count != n - 1)
          continue;
        int i2 = i + e[k].size();
        p[i][j] = p[i][j] || p[i2][j & (~(1 << k))];
      }
    }
    ans += p[i][(1 << n) - 1];
  }
  cout << ans << endl;
}

int main() {
  for (;;) {
    int n, m;
    cin >> n >> m;
    if (n == 0 && m == 0)
      break;
    solve(n, m);
  }
  return 0;
}