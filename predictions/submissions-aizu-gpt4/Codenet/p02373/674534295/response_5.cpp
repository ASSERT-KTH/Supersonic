#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;

struct Edge {
  int s, d;
};

struct LowestCommonAncestor {
  vector<vector<int>> parent;
  vector<int> depth;
  int log2_n;
  
  LowestCommonAncestor(const vector<vector<Edge>> &g, int root)
    : log2_n(log2(g.size()) + 1), parent(log2_n, vector<int>(g.size())),
      depth(g.size()) {
    dfs(g, root, -1, 0);
    for (int k = 0; k + 1 < log2_n; ++k) {
      for (int v = 0; v < parent[k].size(); ++v) {
        if (parent[k][v] < 0)
          parent[k + 1][v] = -1;
        else
          parent[k + 1][v] = parent[k][parent[k][v]];
      }
    }
  }
  
  void dfs(const vector<vector<Edge>> &g, int s, int p, int d) {
    parent[0][s] = p;
    depth[s] = d;
    for (auto &e : g[s]) {
      if (e.d == p)
        continue;
      dfs(g, e.d, s, d + 1);
    }
  }
  
  int get(int u, int v) {
    if (depth[u] > depth[v])
      swap(u, v);
    rep(k, 0, log2_n) {
      if ((depth[v] - depth[u]) >> k & 1) {
        v = parent[k][v];
      }
    }
    if (u == v)
      return u;
    for (int k = log2_n - 1; k >= 0; --k) {
      if (parent[k][u] != parent[k][v]) {
        u = parent[k][u];
        v = parent[k][v];
      }
    }
    return parent[0][u];
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<Edge>> g(n);
  rep(i, 0, n) {
    int k;
    cin >> k;
    rep(j, 0, k) {
      int c;
      cin >> c;
      g[i].push_back({i, c});
    }
  }
  int q;
  cin >> q;
  LowestCommonAncestor lca(g, 0);
  rep(i, 0, q) {
    int u, v;
    cin >> u >> v;
    cout << lca.get(u, v) << "\n";
  }
  return 0;
}