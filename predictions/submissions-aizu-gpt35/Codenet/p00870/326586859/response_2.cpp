#include <bits/stdc++.h>
using namespace std;
// #define rep(i, x, y) for (int i = (x); i < (y); ++i)
// #define debug(x) #x << "=" << (x)
// #ifdef DEBUG
// #define _GLIBCXX_DEBUG
// #define print(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
// #else
// #define print(x)
// #endif
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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> e(n);
    string ts;
    int concatenated_len = 0;
    for(int i = 0; i < n; ++i) {
        cin >> e[i];
        concatenated_len += e[i].size();
    }
    for(int i = 0; i < m; ++i) {
        string t;
        cin >> t;
        ts += t;
    }
    vector<int> sum_len(1 << n);
    for(int i = 0; i < (1 << n); ++i) {
        for(int j = 0; j < n; ++j) {
            if(((i >> j) & 1) == 0)
                continue;
            sum_len[i] += e[j].size();
        }
    }
    static bool p[2][1 << 12];
    memset(p, false, sizeof(p));
    vector<vector<int>> heads(ts.size());
    for(int i = 0; i < ts.size(); ++i) p[0][0] = true;
    for(int i = 0; i < ts.size(); ++i) {
        for(int j = 0; j < n; ++j) {
            if(i + e[j].size() > ts.size() || e[j] != ts.substr(i, e[j].size()))
                continue;
            p[0][1 << j] = true;
            heads[i].push_back(j);
        }
    }
    int ans = 0, cur = 0, prev = 1;
    for(int i = ts.size() - 1; i >= 0; --i) {
        cur ^= 1, prev ^= 1;
        memcpy(p[cur], p[prev], sizeof(p[cur]));
        for(int j = 1; j < (1 << n); ++j) {
            if(p[cur][j] || i + sum_len[j] > ts.size())
                continue;
            for(int k : heads[i]) {
                if(((j >> k) & 1) == 0)
                    continue;
                int i2 = i + e[k].size();
                if(p[prev][j & (~(1 << k))]) {
                    p[cur][j] = true;
                    break;
                }
            }
        }
        if(p[cur][(1 << n) - 1])
            ++ans;
    }
    cout << ans << endl;
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  cout.setf(ios::fixed);
  cout.precision(10);
  while(true) {
    int n, m;
    cin >> n >> m;
    if(n == 0 && m == 0)
      break;
    solve();
  }
  return 0;
}