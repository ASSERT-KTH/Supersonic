#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define INF INT_MAX

vvi pass;
vi c, r, d;
vector<bool> used;

void dfs(int v, int u, int f, int end) {
  if (used[u])
    return;
  used[u] = true;
  d[u] = min(d[u], d[v] + c[v]);
  if (f >= end)
    return;
  rep(i, pass[u].size()) { dfs(v, pass[u][i], f + 1, end); }
}

int dijk(int s, int g) {
  d.assign(d.size(), INF);
  used.assign(used.size(), false);
  d[s] = 0;
  
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({0, s});
  
  while (!pq.empty()) {
    int v = pq.top().second;
    pq.pop();
    
    if (used[v]) continue;
    used[v] = true;

    rep(i, pass[v].size()) {
      used.assign(used.size(), false);
      dfs(v, pass[v][i], 1, r[v]);
      if (!used[pass[v][i]] && d[pass[v][i]] != INF) {
          pq.push({d[pass[v][i]], pass[v][i]});
      }
    }
  }
  return d[g];
}

int main() {
  int n, k;
  cin >> n >> k;
  c.resize(n);
  r.resize(n);
  pass.resize(n);
  d.resize(n);
  used.resize(n);
  
  rep(i, n) cin >> c[i] >> r[i];
  rep(i, k) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    pass[a].pb(b);
    pass[b].pb(a);
  }
  cout << dijk(0, n - 1) << endl;
}