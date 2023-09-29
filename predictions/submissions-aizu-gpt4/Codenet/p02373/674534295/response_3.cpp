#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Edge {
  int s, d;
};

struct LowestCommonAncestor {
  const int n, log2_n;
  vector<vector<int>> parent;
  vector<int> depth;
  LowestCommonAncestor(const vector<vector<Edge>> &g, int root)
      : n(g.size()), log2_n(log2(n) + 1), parent(log2_n, vector<int>(n)),
        depth(n) {
    dfs(g, root, -1, 0);
    for (int k = 0; k + 1 < log2_n; k++) {
      for (int v = 0; v < n; v++) {
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<Edge>> g(n);
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int c;
      cin >> c;
      g[i].emplace_back(Edge{i, c});
    }
  }
  int q;
  cin >> q;
  LowestCommonAncestor lca(g, 0);
  for (int i = 0; i < q; i++) {
    int u, v;
    cin >> u >> v;
    cout << lca.get(u, v) << '\n';
  }
  return 0;
}