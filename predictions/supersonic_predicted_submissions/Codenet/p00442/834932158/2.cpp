#include <bits/stdc++.h>
using namespace std;
#define UNIQUE(v) v.erase(unique(all(v)), v.end());
#define ZIP(v) sort(all(v)), UNIQUE(v)
#define ADD(a, b) a = (a + b) % mod
#define SUB(a, b) a = (a + mod - b) % mod
#define MUL(a, b) a = (a * b) % mod
#define repi(i, m, n) for (int i = m; i < n; i++)
#define drep(i, n, m) for (int i = n; i >= m; i--)
#define rep(i, n) repi(i, 0, n)
#define rrep(i, n) repi(i, 1, n + 1)
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define dmp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define fi first
#define se second
typedef pair<int, int> P;
typedef pair<int, P> PP;
typedef vector<int> vi;
typedef deque<int> dq;
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
map<P, int> mp;
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
    mp[P(x, y)] = 1;
  }
  t.tsort();
  vector<int> ans = t.ans;
  rep(i, n) printf("%lld\n", ans[i] + 1);
  int res = 1;
  rep(i, n - 1) {
    if (mp[P(ans[i], ans[i + 1])] == 0)
      res = 0;
  }
  printf("%lld\n", res == 1 ? 0 : 1);
  return 0;
}
