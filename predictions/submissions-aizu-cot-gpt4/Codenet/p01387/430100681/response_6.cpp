int main() {
  scanf("%d %d", &N, &Q);
  CentroidPathDecomposition gg(N);
  vector<int> vs;
  for (int i = 0; i < N; i++) {
    scanf("%d", &X[i]);
    vs.emplace_back(X[i]);
  }
  sort(begin(vs), end(vs));
  vs.erase(unique(begin(vs), end(vs)), end(vs));
  for (int i = 1; i < N; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    --x, --y;
    g[x].emplace_back(y);
    g[y].emplace_back(x);
    gg.AddEdge(x, y);
  }
  dfs(0, -1, tree.makeset());
  gg.Build();
  for (int i = 0; i < Q; i++) {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    --x, --y;
    int lca = gg.LCA(x, y);
    int ng = -1, ok = (int)vs.size() - 1;
    auto sum = [&](int v) {
      int ret = 0;
      int upper_bound_x = tree.upper_bound(nodes[x], vs[v]);
      int upper_bound_y = tree.upper_bound(nodes[y], vs[v]);
      int upper_bound_lca = tree.upper_bound(nodes[lca], vs[v]);
      int upper_bound_parent_lca = lca ? tree.upper_bound(nodes[parent[lca]], vs[v]) : 0;
      ret += upper_bound_x;
      ret += upper_bound_y;
      ret -= upper_bound_lca;
      ret -= upper_bound_parent_lca;
      return ret;
    };
    while (ok - ng > 1) {
      int mid = (ok + ng) >> 1;
      if (sum(mid) >= z)
        ok = mid;
      else
        ng = mid;
    }
    printf("%d\n", vs[ok]);
  }
}