#include <bits/stdc++.h>
using namespace std;
#define rep(i, x, y) for (int i = (x); i < (y); ++i)

// Removed debug and print macros for simplicity

const int inf = 1e9;
const int64_t inf64 = 1e18;
const double eps = 1e-9;

void solve(int n, int m) {
  vector<string> e(n);
  stringstream ts;
  int concatenated_len = 0;
  rep(i, 0, n) {
    cin >> e[i];
    concatenated_len += e[i].size();
  }
  rep(i, 0, m) {
    string t;
    cin >> t;
    ts << t;
  }

  string ts_str = ts.str();
  
  vector<int> sum_len(1 << n);
  rep(i, 0, 1 << n) {
    rep(j, 0, n) {
      if (((i >> j) & 1) == 0)
        continue;
      sum_len[i] += e[j].size();
    }
  }

  static bool p[5000][1 << 12];
  fill_n((bool *)p, 5000 * (1 << 12), false);
  vector<vector<int>> heads(ts_str.size());

  for (int i = ts_str.size() - 1; i >= 0; --i) {
    p[i][0] = true;
    for (int j = 1; j < (1 << n); ++j) {
      if (p[i][j] or i + sum_len[j] > ts_str.size())
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
  for (;;) {
    int n, m;
    cin >> n >> m;
    if (n == 0 and m == 0)
      break;
    solve(n, m);
  }
  return 0;
}