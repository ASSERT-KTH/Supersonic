#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define pb push_back
const int INF = 1e9;
const int MAXN = 6000;
vector<int> pass[MAXN];
int n, k, c[MAXN], r[MAXN], d[MAXN];
bool used[MAXN];
void dfs(int v, int u, int f, int end, bool visited[MAXN]) {
  if (visited[u]) return;
  visited[u] = true;
  d[u] = min(d[u], d[v] + c[v]);
  if (f >= end) return;
  for (int i : pass[u]) dfs(v, i, f + 1, end, visited);
}
int dijk(int s, int g) {
  rep(i, MAXN) d[i] = INF;
  rep(i, MAXN) used[i] = false;
  d[s] = 0;
  while (1) {
    int v = -1;
    rep(u, n) {
      if (!used[u] && (v == -1 || d[u] < d[v])) v = u;
    }
    if (v == -1) break;
    used[v] = true;
    for (int i : pass[v]) {
      bool visited[MAXN] = {};
      dfs(v, i, 1, r[v], visited);
    }
  }
  return d[g];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
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
  return 0;
}