#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

struct Edge {
  int s, d;
  Edge(int s, int d) : s(s), d(d) {};
};

using Edges = vector<Edge>;
using Graph = vector<Edges>;

struct LowestCommonAncestor {
  int n;
  vector<vector<int>> parent;
  vector<int> depth;

  LowestCommonAncestor(const Graph &g, int root)
      : n(g.size()), parent(log2(n) + 1, vector<int>(n)), depth(n) {
    dfs(g, root, -1, 0);
    for (int k = 0; k + 1 < parent.size(); k++) {
      for (int v = 0; v < n; v++) {
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
    for (auto &e : g[s]) {
      if (e.d == p)
        continue;
      dfs(g, e.d, s, d + 1);
    }
  }

  int get(int u, int v) {
    if (depth[u] > depth[v])
      swap(u, v);
    for (int k = 0; k < parent.size(); k++) {
      if ((depth[v] - depth[u]) >> k & 1) {
        v = parent[k][v];
      }
    }
    if (u == v)
      return u;
    for (int k = parent.size() - 1; k >= 0; k--) {
      if (parent[k][u] != parent[k][v]) {
        u = parent[k][u];
        v = parent[k][v];
      }
    }
    return parent[0][u];
  }
};

int main() {
  int n;
  scanf("%d", &n);
  Graph g(n);
  for(int i = 0; i < n; i++) {
    int k;
    scanf("%d", &k);
    for(int j = 0; j < k; j++) {
      int c;
      scanf("%d", &c);
      g[i].emplace_back(i, c);
    }
  }
  int q;
  scanf("%d", &q);
  LowestCommonAncestor lca(g, 0);
  for(int i = 0; i < q; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    printf("%d\n", lca.get(u, v));
  }
  return 0;
}