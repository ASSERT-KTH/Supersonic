#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define INF 999999999
vector<int> pass[6000];
int n, k;
int c[6000];
int r[6000];
int d[6000];
bool used[6000];
void dfs(int v, int u, int f, int end, bool visited[6000]) {
  if (visited[u]) return;
  visited[u] = true;
  d[u] = min(d[u], d[v] + c[v]);
  if (f >= end) return;
  for (auto i : pass[u]) dfs(v, i, f + 1, end, visited);
}
int dijk(int s, int g) {
  rep(i, 6000) d[i] = INF;
  rep(i, 6000) used[i] = false;
  d[s] = 0;
  while (1) {
    int v = -1;
    rep(u, n) if (!used[u] && (v == -1 || d[u] < d[v])) v = u;
    if (v == -1) break;
    used[v] = true;
    for (auto i : pass[v]) {
      bool visited[6000] = {};
      dfs(v, i, 1, r[v], visited);
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