#include <cstdio>
#include <vector>
#include <stack>
#include <map>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const ll inf = 1e9 + 7;
const ll INF = 1e18 + 7;

class t_sort {
public:
  ll n;
  vector<ll> ans, deg;
  vector<vector<ll>> G;
  void init(ll N) {
    n = N;
    deg.resize(n);
    G.resize(n);
  }
  void add_edge(ll from, ll to) {
    G[from].push_back(to);
    deg[to]++;
  }
  void tsort() {
    stack<ll> st;
    for(ll i = 0; i < n; i++)
      if (deg[i] == 0) st.push(i);
    while (!st.empty()) {
      ll v = st.top();
      st.pop();
      ans.push_back(v);
      for(ll i = 0; i < G[v].size(); i++) 
        if (--deg[G[v][i]] == 0) st.push(G[v][i]);
    }
  }
};

map<pll, ll> mp;

int main() {
  ll n, m;
  scanf("%lld%lld", &n, &m);
  t_sort t;
  t.init(n);
  for(ll i = 0; i < m; i++) {
    ll x, y;
    scanf("%lld%lld", &x, &y);
    x--;
    y--;
    t.add_edge(x, y);
    mp[pll(x, y)] = 1;
  }
  t.tsort();
  vector<ll> ans = t.ans;
  for(ll i = 0; i < n; i++) 
    printf("%lld\n", ans[i] + 1);
  ll res = 1;
  for(ll i = 0; i < n - 1; i++) {
    if (mp[pll(ans[i], ans[i + 1])] == 0)
      res = 0;
  }
  printf("%lld\n", res == 1 ? 0 : 1);
  return 0;
}