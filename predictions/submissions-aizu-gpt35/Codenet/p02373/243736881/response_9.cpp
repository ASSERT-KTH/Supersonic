#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int color[100010], par[100010], depth[100010];
int top[100010];
bool vis[100010];
int n;
vector<vector<int>> g;
unordered_map<int, int> goUp;
void dfs(int u, int p, int d, int &c) {
  par[u] = p, depth[u] = d, vis[u] = true;
  int sz = 0, mx = -1;
  for (int v : g[u]) {
    if (v == p)
      continue;
    dfs(v, u, d + 1, c), sz++;
    if (sz == 1 || depth[v] > mx)
      mx = depth[v], goUp[u] = v;
  }
  if (sz == 0 || mx - d + 1 > 200) {
    while (u != -1)
      vis[u] = false, color[u] = c, top[u] = sz == 0 ? u : -1, u = goUp[u];
    c++;
  }
  if (sz == 1 && mx - d + 1 <= 200)
    goUp[u] = goUp[par[u]];
}
int solve(int u, int v) {
  while (color[u] != color[v]) {
    if (depth[top[u]] > depth[top[v]])
      swap(u, v);
    v = goUp[top[v]];
  }
  while (u != v) {
    if (depth[u] > depth[v])
      swap(u, v);
    v = par[v];
  }
  return u;
}
int main() {
  cin >> n;
  g.assign(n, {});
  rep(i, n) {
    int k;
    cin >> k;
    rep(j, k) {
      int c;
      cin >> c;
      g[i].push_back(c);
    }
  }
  int c = 0;
  dfs(0, -1, 0, c);
  int q;
  cin >> q;
  rep(i, q) {
    int u, v;
    cin >> u >> v;
    cout << solve(u, v) << endl;
  }
}