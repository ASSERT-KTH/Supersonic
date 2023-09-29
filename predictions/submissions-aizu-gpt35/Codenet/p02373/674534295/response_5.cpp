#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define all(c) begin(c), end(c)
const int INF =
    sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
template <class T> bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T> bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
using Weight = int;
struct Edge {
  int s, d;
  Weight w;
  Edge(int s, int d, Weight w = 1) : s(s), d(d), w(w){};
  bool operator<(const Edge &e) const { return w < e.w; }
};
using Edges = vector<Edge>;
using Graph = vector<Edges>;
using Array = vector<Weight>;
using Matrix = vector<Array>;
struct LowestCommonAncestor {
  const int n, log2_n;
  vector<vector<int>> parent;
  vector<int> depth;
  LowestCommonAncestor(const Graph &g, int root)
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
    g[i].reserve(k);
    rep(j, 0, k) {
      int c;
      cin >> c;
      g[i].emplace_back(i, c);
    }
  }
  int q;
  cin >> q;
  vector<int> queries(q);
  rep(i, 0, q) {
    int u, v;
    cin >> u >> v;
    queries[i] = u * n + v;
  }
  LowestCommonAncestor lca(g, 0);
  rep(i, 0, q) {
    int u = queries[i] / n, v = queries[i] % n;
    cout << lca.get(u, v) << endl;
  }
  return 0;
}