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
  fill_n((bool *)p, 2000 * (1 << 12), false);
  vector<vector<int>> heads(ts.size());
  rep(i, 0, ts.size()) p[i][0] = true;
  rep(i