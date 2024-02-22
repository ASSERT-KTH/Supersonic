#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int B = 200;
int n;
vector<vector<int>> g;
vector<int> color;
vector<int> par;
vector<int> depth;
vector<int> top;
vector<int> goUp;

void dfs(int v, vector<bool>& vis, vector<int>& tord) {
  vis[v] = true;
  tord.push_back(v);
  for (int c : g[v]) {
    if (!vis[c]) {
      par[c] = v;
      depth[c] = depth[v] + 1;
      dfs(c, vis, tord);
    }
  }
}

void decomp(int root) {
  vector<bool> vis(n, false);
  vector<int> tord;
  dfs(root, vis, tord);
  vis.assign(n, false);
  int c = 0;
  for (int u : tord) {
    if (vis[u])
      continue;
    vis[u] = true;
    color[u] = c;
    goUp[u] = par[u];
    top[u] = u;
    int k = 1;
    for (int c : g[u]) {
      if (!vis[c] && k < B) {
        vis[c] = true;
        color[c] = c;
        goUp[c] = par[u];
        top[c] = u;
        k++;
      }
    }
    c++;
  }
}

int solve(int u, int v) {
  while (u != v) {
    assert(u != -1 && v != -1);
    if (depth[u] > depth[v])
      u = par[u];
    else if (depth[u] < depth[v])
      v = par[v];
    else {
      u = par[u];
      v = par[v];
    }
  }
  return u;
}

int main() {
  cin >> n;
  g.assign(n, {});
  color.assign(n, -1);
  par.assign(n, -1);
  depth.assign(n, 0);
  top.assign(n, -1);
  goUp.assign(n, -1);

  rep(i, n) {
    int k;
    cin >> k;
    rep(j, k) {
      int c;
      cin >> c;
      g[i].push_back(c);
      par[c] = i;
    }
  }
  decomp(0);
  int q;
  cin >> q;
  rep(i, q) {
    int u, v;
    cin >> u >> v;
    cout << solve(u, v) << endl;
  }
}