#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

const int MAX_N = 12;
const int MAX_M = 5000;

void solve(int n, int m) {
  vector<string> e(n);
  rep(i, 0, n) {
    cin >> e[i];
  }

  string ts;
  stringstream ss;
  rep(i, 0, m) {
    string t;
    cin >> t;
    ss << t;
  }
  ts = ss.str();

  vector<int> sum_len(1 << n);
  rep(i, 0, 1 << n) {
    rep(j, 0, n) {
      if (((i >> j) & 1) == 0)
        continue;
      sum_len[i] += e[j].size();
    }
  }

  static bool p[MAX_M][1 << MAX_N] = {false};
  vector<int> heads[MAX_M];
  rep(i, 0, ts.size()) p[i][0] = true;

  rep(i, 0, ts.size()) {
    rep(j, 0, n) {
      if (i + e[j].size() > ts.size() or e[j] != ts.substr(i, e[j].size()))
        continue;
      p[i][1 << j] = true;
      heads[i].emplace_back(j);
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