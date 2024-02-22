#include <bits/stdc++.h>
using namespace std;
#define int long long
#define repi(i, m, n) for (int i = m; i < n; i++)
#define rep(i, n) repi(i, 0, n)
#define pb(x) push_back(x)
typedef pair<int, int> P;
typedef vector<int> vi;
typedef unordered_map<P, int, boost::hash<P>> umap;

class t_sort {
public:
  int n, res;
  vector<int> ans, deg;
  vector<vector<int>> G;
  umap mp; // using unordered_map instead of map
  void init(int N) {
    n = N;
    res = 1;
    deg.resize(n);
    G.resize(n);
  }
  void add_edge(int from, int to) {
    G[from].pb(to);
    deg[to]++;
    mp[P(from, to)] = 1; // storing edges in the unordered_map
  }
  void tsort() {
    stack<int> st;
    rep(i, n) if (deg[i] == 0) st.push(i);
    while (!st.empty()) {
      int v = st.top();
      st.pop();
      ans.pb(v);
      if (!ans.empty() && mp[P(ans.back(), v)] == 0)
        res = 0; // check for edge existence during topological sort
      rep(i, G[v].size()) if (--deg[G[v][i]] == 0) st.push(G[v][i]);
    }
  }
};

signed main() {
  int n, m;
  scanf("%lld%lld", &n, &m);
  t_sort t;
  t.init(n);
  rep(i, m) {
    int x, y;
    scanf("%lld%lld", &x, &y);
    x--;
    y--;
    t.add_edge(x, y);
  }
  t.tsort();
  vector<int> ans = t.ans;
  rep(i, n) printf("%lld\n", ans[i] + 1);
  printf("%lld\n", t.res == 1 ? 0 : 1);
  return 0;
}