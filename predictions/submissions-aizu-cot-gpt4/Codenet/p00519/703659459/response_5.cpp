#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define INF 999999999
vector<int> pass[6000];
int n, k;
int c[6000];
int r[6000];
int d[6000];
bool used[6000];
void dfs(int v, int u, int f, int end, bool visited[6000]) {
  if (visited[u])
    return;
  visited[u] = true;
  d[u] = min(d[u], d[v] + c[v]);
  if (f >= end)
    return;
  ll pass_size = pass[u].size();
  rep(i, pass_size) { dfs(v, pass[u][i], f + 1, end, visited); }
}
int dijk(int s, int g) {
  rep(i, 6000) d[i] = INF;
  rep(i, 6000) used[i] = false;
  d[s] = 0;
  bool visited[6000] = {};
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({0, s});
  while (!pq.empty()) {
    int v = pq.top().second;
    pq.pop();
    if (used[v])
      continue;
    used[v] = true;
    fill(visited, visited+6000, false);
    ll pass_size = pass[v].size();
    rep(i, pass_size) {
      dfs(v, pass[v][i], 1, r[v], visited);
    }
  }
  return d[g];
}
int main() {
  cin >> n >> k;
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