#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int B = 200;
int n;
vector<vector<int>> g;
vector<int> color, par, depth, top, goUp;
vector<bool> vis;
void dfs(int v, int p, int d) {
  par[v] = p, depth[v] = d, vis[v] = true;
  for (int c : g[v]) {
    if (!vis[c])
      dfs(c, v, d + 1);
  }
}
void decomp(int root) {
  vis.assign(n, false);
  dfs(root, -1, 0);
  int c = 0;
  rep(i, n) {
    if (!vis[i]) 
      continue;
    if (par[i] == -1 || vis[par[i]])
      top[i] = i, color[i] = c++;
    else
      top[i] = top[par[i]], color[i] = color[par[i]];
    goUp[i] = (par[i] == -1 ? -1 : (vis[par[i]] ? par[i] : goUp[par[i]]));
    if ((i == root || goUp[i] != par[i]) && (i != top[i] || i == root)) 
      continue;
    int u = i;
    while (u != -1) {
      vis[u] = false;
      u = goUp[u];
    }
  }
}
int solve(int u, int v) {
  while (color[u] != color[v]) {
    if (depth[top[u]] > depth[top[v]])
      u = goUp[u];
    else
      v = goUp[v];
  }
  while (u != v) {
    if (depth[u] > depth[v])
      u = par[u];
    else
      v = par[v];
  }
  return u;
}
int main() {
  cin >> n;
  g.resize(n);
  color.resize(n), par.resize(n, -1), depth.resize(n);
  top.resize(n), goUp.resize(n);
  rep(i, n) {
    int k;
    cin >> k;
    rep(j, k) {
      int c;
      cin >> c, c--;
      g[i].push_back(c), g[c].push_back(i);
    }
  }
  decomp(0);
  int q;
  cin >> q;
  rep(i, q) {
    int u, v;
    cin >> u >> v, u--, v--;
    cout << solve(u, v) + 1 << endl;
  }
  return 0;
}