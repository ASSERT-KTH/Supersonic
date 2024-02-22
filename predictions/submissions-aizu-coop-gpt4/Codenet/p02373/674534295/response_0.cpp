// ... (same as before)

struct LowestCommonAncestor {
  // ... (same as before)

  int get(int u, int v) {
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

// ... (same as before)

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
      g[i].emplace_back(i, c);
    }
  }
  int q;
  cin >> q;
  LowestCommonAncestor lca(g, 0);
  rep(i, 0, q) {
    int u, v;
    cin >> u >> v;
    // Ensure that u is always the deeper node
    if (lca.depth[u] < lca.depth[v])
      swap(u, v);
    cout << lca.get(u, v) << endl;
  }
  return 0;
}