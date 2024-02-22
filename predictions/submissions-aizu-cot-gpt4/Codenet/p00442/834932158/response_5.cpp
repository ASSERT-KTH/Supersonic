#include <iostream>
#include <vector>
#include <stack>
#include <utility>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

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
    for(ll i = 0; i < n; i++) if (deg[i] == 0) st.push(i);
    while (!st.empty()) {
      ll v = st.top();
      st.pop();
      ans.push_back(v);
      for(ll i = 0; i < G[v].size(); i++) if (--deg[G[v][i]] == 0) st.push(G[v][i]);
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, m;
  cin >> n >> m;
  t_sort t;
  t.init(n);
  for(ll i = 0; i < m; i++) {
    ll x, y;
    cin >> x >> y;
    x--;
    y--;
    t.add_edge(x, y);
  }
  t.tsort();
  vector<ll> ans = t.ans;
  for(ll i = 0; i < n; i++) cout << ans[i] + 1 << '\n';
  ll res = 1;
  for(ll i = 0; i < n - 1; i++) {
    bool found = false;
    for(ll j = 0; j < t.G[ans[i]].size(); j++) {
      if(t.G[ans[i]][j] == ans[i+1]) {
        found = true;
        break;
      }
    }
    if(!found) {
      res = 0;
      break;
    }
  }
  cout << (res == 1 ? 0 : 1) << '\n';
  return 0;
}