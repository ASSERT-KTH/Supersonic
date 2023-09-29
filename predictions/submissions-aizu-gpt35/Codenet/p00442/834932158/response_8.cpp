#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
typedef vector<int> vi;
const int inf = 1e9 + 7;
class t_sort {
public:
  int n;
  vi ans, deg;
  vector<vi> G;
  void init(int N) {
    n = N;
    deg.resize(n);
    G.resize(n);
  }
  void add_edge(int from, int to) {
    G[from].push_back(to);
    deg[to]++;
  }
  void tsort() {
    vi order;
    order.reserve(n);
    rep(i, n) if (deg[i] == 0) order.push_back(i);
    rep(i, order.size()) {
      int v = order[i];
      ans.push_back(v);
      for (int u : G[v])
        if (--deg[u] == 0)
          order.push_back(u);
    }
  }
};
map<pair<int, int>, int> mp;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  t_sort t;
  t.init(n);
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    t.add_edge(x, y);
    mp[{x, y}] = 1;
  }
  t.tsort();
  vi ans = t.ans;
  rep(i, n) cout << ans[i] + 1 << '\n';
  int res = 1;
  rep(i, n - 1) {
    if (mp[{ans[i], ans[i + 1]}] == 0)
      res = 0;
  }
  cout << (res == 1 ? 0 : 1) << '\n';
  return 0;
}