#include <bits/stdc++.h>
using namespace std;
#define rep(i, x, y) for (int i = (x); i < (y); ++i)

bool match(const string &s, const string &t, int pos) {
  if (pos + s.size() > t.size())
    return false;
  rep(i, 0, s.size()) {
    if (s[i] != t[pos + i])
      return false;
  }
  return true;
}

void solve(int n, int m) {
  vector<string> e(n);
  rep(i, 0, n) cin >> e[i];
  string ts;
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
  fill_n((bool *)p, 5000 * (1 << 12), false);
  rep(i, 0, ts.size()) p[i][0] = true;
  vector<int> masks(ts.size());
  rep(i, 0, ts.size()) {
    rep(j, 0, n) {
      if (match(e[j], ts, i)) {
        masks[i] |= 1 << j;
        p[i][1 << j] = true;
      }
    }
  }
  int ans = 0;
  for (int i = ts.size() - 1; i >= 0; --i) {
    rep(j, 1, 1 << n) {
      if (p[i][j] or i + sum_len[j] > ts.size())
        continue;
      if (p[i + e[__builtin_ctz(j)][j & (~masks[i])]) {
        p[i][j] = true;
        ++ans;
      }
    }
  }
  cout << ans << endl;
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  for (;;) {
    int n, m;
    cin >> n >> m;
    if (n == 0 and m == 0)
      break;
    solve(n, m);
  }
  return 0;
}