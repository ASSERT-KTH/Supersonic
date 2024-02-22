// ... (The unchanged part of the code)
void dfs(int idx, int par, OrderedMultiSet<int>::Node *par_set) {
  parent[idx] = par;
  tree.insert_key(par_set, X[idx]);
  nodes[idx] = par_set;
  for (auto &to : g[idx])
    if (to != par)
      dfs(to, idx, par_set);
}

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
      ret += tree.upper_bound(nodes[x], vs[v]);
      ret += tree.upper_bound(nodes[y], vs[v]);
      ret -= tree.upper_bound(nodes[lca], vs[v]);
      if (lca)
        ret -= tree.upper_bound(nodes[parent[lca]], vs[v]);
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
// ... (The unchanged part of the code)