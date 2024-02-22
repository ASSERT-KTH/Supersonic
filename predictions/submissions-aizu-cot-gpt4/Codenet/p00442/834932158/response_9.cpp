#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pll;

class TSort {
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
    queue<ll> q;
    for(ll i = 0; i < n; i++) if (deg[i] == 0) q.push(i);
    while (!q.empty()) {
      ll v = q.front();
      q.pop();
      ans.push_back(v);
      for(auto& child : G[v]) if (--deg[child] == 0) q.push(child);
    }
  }
};

set<Pll> edges;

int main() {
  ll n, m;
  scanf("%lld%lld", &n, &m);
  TSort t;
  t.init(n);
  for(ll i = 0; i < m; i++) {
    ll x, y;
    scanf("%lld%lld", &x, &y);
    x--; y--;
    t.add_edge(x, y);
    edges.insert(Pll(x, y));
  }
  t.tsort();
  vector<ll> ans = t.ans;
  for(ll i = 0; i < n; i++) printf("%lld\n", ans[i] + 1);
  ll res = 1;
  for(ll i = 0; i < n - 1; i++) {
    if (edges.find(Pll(ans[i], ans[i + 1])) == edges.end())
      res = 0;
  }
  printf("%lld\n", res == 1 ? 0 : 1);
  return 0;
}