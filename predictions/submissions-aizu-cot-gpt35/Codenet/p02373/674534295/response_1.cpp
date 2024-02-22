#include <iostream>
#include <vector>
#include <algorithm>

#define rep(i, a, b) for (int i = (a); i < (b); ++i)

using Weight = int;

struct Edge {
  int s, d;
  Weight w;
  Edge(int s, int d, Weight w = 1) : s(s), d(d), w(w) {};
};

using Edges = std::vector<Edge>;
using Graph = std::vector<std::vector<int>>;
using Array = std::vector<Weight>;

struct LowestCommonAncestor {
  const int n, log2_n;
  std::vector<std::vector<int>> parent;
  std::vector<int> depth;

  LowestCommonAncestor(const Graph& g, int root)
      : n(g.size()), log2_n(log2(n) + 1), parent(log2_n, std::vector<int>(n)),
        depth(n) {
    dfs(g, root, -1, 0);
    for (int k = 0; k + 1 < log2_n; ++k) {
      for (int v = 0; v < n; ++v) {
        parent[k + 1][v] = parent[k][parent[k][v]];
      }
    }
  }

  void dfs(const Graph& g, int s, int p, int d) {
    parent[0][s] = p;
    depth[s] = d;
    for (auto& e : g[s]) {
      if (e == p) continue;
      dfs(g, e, s, d + 1);
    }
  }

  int get(int u, int v) {
    if (depth[u] > depth[v]) std::swap(u, v);
    for (int k = 0; k < log2_n; ++k) {
      if ((depth[v] - depth[u]) >> k & 1) {
        v = parent[k][v];
      }
    }
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
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n;
  std::cin >> n;

  Graph g(n);
  rep(i, 0, n) {
    int k;
    std::cin >> k;
    g[i].resize(k);
    rep(j, 0, k) {
      std::cin >> g[i][j];
    }
  }

  int q;
  std::cin >> q;

  LowestCommonAncestor lca(g, 0);

  rep(i, 0, q) {
    int u, v;
    std::cin >> u >> v;
    std::cout << lca.get(u, v) << std::endl;
  }

  return 0;
}