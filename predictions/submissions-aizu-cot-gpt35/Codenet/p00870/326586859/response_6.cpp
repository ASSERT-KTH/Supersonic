#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

#define rep(i, x, y) for (int i = (x); i < (y); ++i)

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

  vector<int> sum_len(n);
  rep(i, 0, n) {
    sum_len[i] = e[i].size();
  }

  static bool p[1 << 12];
  fill_n(p, 1 << 12, false);
  vector<vector<int>> heads(ts.size());
  rep(i, 0, ts.size()) p[0] = true;
  rep(i, 0, ts.size()) {
    rep(j, 0, n) {
      if (i + e[j].size() > ts.size() or e[j] != ts.substr(i, e[j].size()))
        continue;
      p[1 << j] = true;
      heads[i].push_back(j);
    }
  }

  int ans = 0;
  for (int i = ts.size() - 1; i >= 0; --i) {
    rep(j, 1, 1 << n) {
      if (p[j] or i + sum_len[j] > ts.size())
        continue;
      for (int k : heads[i]) {
        if ((j >> k) & 1)
          continue;
        int i2 = i + e[k].size();
        if (p[j & (~(1 << k))]) {
          p[j] = true;
          break;
        }
      }
    }
    if (p[(1 << n) - 1])
      ++ans;
  }

  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
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