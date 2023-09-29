#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using Graph = vector<vector<int>>;
struct LCA {
  const int n, log2_n;
  Graph parent;
  vector<int> depth;
  LCA(const Graph &g, int root)
      : n(g.size()), log2_n(log2(n) + 1), parent(log2_n, vector<int>(n)),
        depth(n) {
    dfs(g, root, -1, 0);
    rep(k, 0, log2_n - 1) {
      rep(v, 0, n) {
        if (parent[k][v] < 0)
          parent[k + 1][v] = -1;
        else
          parent[k + 1][v] = parent[k][parent[k][v]];
      }
    }
  }
  void dfs(const Graph &g, int s, int p, int d) {
    parent[0][s] = p;
    depth[s] = d;
    for (int v : g[s]) {
      if (v == p)
        continue;
      dfs(g, v, s, d + 1);
    }
  }
  int get(int u, int v) {
    if (depth[u] > depth[v])
      swap(u, v);
    for (int k = 0; k < log2_n; k++) {
      if ((depth[v] - depth[u]) >> k & 1) {
        v = parent[k][v];
      }
    }
    if (u == v)
      return u;
    for (int k = log2_n - 1; k >= 0; k--) {
      if (parent[k][u] != parent[k][v]) {
        u = parent[k][u];
        v = parent[k][v];
      }
    }
    return parent[0][u];
  }
};
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  Graph g(n);
  rep(i, 0, n) {
    int k;
    cin >> k;
    rep(j, 0, k) {
      int c;
      cin >> c;
      g[i].push_back(c);
    }
  }
  int q;
  cin >> q;
  LCA lca(g, 0);
  rep(i, 0, q) {
    int u, v;
    cin >> u >> v;
    cout << lca.get(u, v) << endl;
  }
  return 0;
}