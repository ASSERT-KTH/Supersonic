#include <iostream>
#include <vector>
#include <string>
using namespace std;

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
  for (int i = 0; i < (1 << n); ++i) {
    for (int j = 0; j < n; ++j) {
      if (((i >> j) & 1) == 0)
        continue;
      sum_len[i] += e[j].size();
    }
  }
  const int MAX_LEN = ts.size();
  const int MAX_MASK = (1 << n) - 1;
  static bool p[MAX_LEN][MAX_MASK + 1];
  for (int i = 0; i < MAX_LEN; ++i) {
    fill_n(p[i], MAX_MASK + 1, false);
  }
  vector<vector<int>> heads(MAX_LEN);
  for (int i = 0; i < MAX_LEN; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i + e[j].size() > MAX_LEN || e[j] != ts.substr(i, e[j].size()))
        continue;
      p[i][1 << j] = true;
      heads[i].push_back(j);
    }
  }
  int ans = 0;
  for (int i = MAX_LEN - 1; i >= 0; --i) {
    for (int j = 1; j <= MAX_MASK; ++j) {
      if (p[i][j] || i + sum_len[j] > MAX_LEN)
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
    if (p[i][MAX_MASK])
      ++ans;
  }
  cout << ans << endl;
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  cout.setf(ios::fixed);
  cout.precision(10);
  for (;;) {
    int n, m;
    cin >> n >> m;
    if (n == 0 && m == 0)
      break;
    solve(n, m);
  }
  return 0;
}