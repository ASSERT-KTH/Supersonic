#include <bits/stdc++.h>
using namespace std;
#define int long long
#define UNIQUE(v) v.erase(unique(all(v)), v.end())
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
const int inf = 1e9 + 7;
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
    queue<int> q;
    rep(i, n) if (deg[i] == 0) q.push(i);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      ans.pb(v);
      for (auto u : G[v]) {
        if (--deg[u] == 0) q.push(u);
      }
    }
  }
};

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

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
  }
  t.tsort();
  vector<int> ans = t.ans;
  for (auto x : ans) cout << x + 1 << "\n";
  for (int i = 0; i < n - 1; i++) {
    if (t.deg[ans[i]] != 0) {
      cout << "1\n";
      return 0;
    }
  }
  cout << "0\n";
  return 0;
}