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
    rep(j, 0, n) {
      if (((i >> j) & 1) == 0)
        continue;
      sum_len[i] += e[j].size();
    }
  }
  static bool p[5000][1 << 12];
  memset(p, 0, sizeof(p));
  vector<vector<int>> heads(ts.size());
  rep(i, 0, ts.size()) p[i][0] = true;
  rep(i, 0, ts.size()) {
    rep(j, 0, n) {
      if (i + e[j].size() > ts.size() or e[j] != ts.substr(i, e[j].size()))
        continue;
      p[i][1 << j] = true;
      heads[i].push_back(j);
    }
  }
  int ans = 0;
  for (int i = ts.size() - 1; i >= 0; --i) {
    rep(j, 1, 1 << n) {
      if (p[i][j] or i + sum_len[j] > ts.size())
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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
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