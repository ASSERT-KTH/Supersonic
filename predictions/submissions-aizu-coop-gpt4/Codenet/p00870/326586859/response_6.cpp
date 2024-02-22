#include <bits/stdc++.h>
using namespace std;
#define rep(i, x, y) for (int i = (x); i < (y); ++i)
#define debug(x) #x << "=" << (x)
#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define print(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define print(x)
#endif
const int inf = 1e9;
const int64_t inf64 = 1e18;
const double eps = 1e-9;
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) {
  os << "[";
  for (const auto &v : vec) {
    os << v << ",";
  }
  os << "]";
  return os;
}
void solve(int n, int m) {
  vector<string> e(n);
  string ts;
  int concatenated_len = 0;
  rep(i, 0, n) {
    cin >> e[i];
    concatenated_len += e[i].size();
  }
  rep(i, 0, m) {
    string t;
    cin >> t;
    ts += t;
  }
  vector<int> sum_len(1 << n);
  rep(i, 0, 1 << n) {
    for (int j = 0; j < n; ++j) {
      if (i & (1 << j)) {
        sum_len[i] += e[j].size();
      }
    }
  }
  static bool p[5000][1 << 12];
  fill_n((bool *)p, 5000 * (1 << 12), false);
  vector<vector<int>> heads(ts.size());
  rep(i, 0, ts.size()) p[i][0] = true;
  rep(i, 0, ts.size()) {
    for (int j = 0; j < n; ++j) {
      if (i + e[j].size() <= ts.size() && e[j] == ts.substr(i, e[j].size())) {
        p[i][1 << j] = true;
        heads[i].push_back(j);
      }
    }
  }
  int ans = 0;
  for (int i = ts.size() - 1; i >= 0; --i) {
    for (int j = 1; j < (1 << n); ++j) {
      if (p[i][j] || i + sum_len[j] > ts.size()) continue;
      for (int k : heads[i]) {
        if (j & (1 << k)) {
          int i2 = i + e[k].size();
          if (p[i2][j ^ (1 << k)]) { //Use bitwise XOR to get the remaining subset
            p[i][j] = true;
            break;
          }
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