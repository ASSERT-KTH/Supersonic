#include <bits/stdc++.h>
using namespace std;
#define int long long
#define repi(i, m, n) for (int i = m; i < n; i++)
#define rep(i, n) repi(i, 0, n)
#define pb(x) push_back(x)
typedef pair<int, int> P;
const int INF = 1e18 + 7;
class t_sort {
public:
  int n;
  vector<int> ans, deg;
  vector<vector<int>> G;
  void init(int N) {
    n = N;
    deg.resize(n);
    G.resize(n);
  }
  void add_edge(int from, int to) {
    G[from].pb(to);
    deg[to]++;
  }
  void tsort() {
    stack<int> st;
    rep(i, n) if (deg[i] == 0) st.push(i);
    while (!st.empty()) {
      int v = st.top();
      st.pop();
      ans.pb(v);
      rep(i, G[v].size()) if (--deg[G[v][i]] == 0) st.push(G[v][i]);
    }
  }
};
vector<bool> edges[200005];
signed main() {
  int n, m;
  scanf("%lld%lld", &n, &m);
  t_sort t;
  t.init(n);
  rep(i, n) edges[i].resize(n, false);
  rep(i, m) {
    int x, y;
    scanf("%lld%lld", &x, &y);
    x--;
    y--;
    t.add_edge(x, y);
    edges[x][y] = true;
  }
  t.tsort();
  vector<int> ans = t.ans;
  rep(i, n) printf("%lld\n", ans[i] + 1);
  int res = 1;
  rep(i, n - 1) {
    if (!edges[ans[i]][ans[i + 1]])
      res = 0;
  }
  printf("%lld\n", res == 1 ? 0 : 1);
  return 0;
}