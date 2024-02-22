Weight Dfs(vector<int> &level, vector<int> &iter, int v, int t, Weight flow) {
  if (v == t)
    return flow;
  for (int &i = iter[v], N = g[v].size(); i < N; ++i) {
    Edge &e = g[v][i];
    if (e.weight > 0 && level[v] < level[e.dst]) {
      Weight d = Dfs(level, iter, e.dst, t, min(flow, e.weight));
      if (d > 0) {
        e.weight -= d;
        g[e.dst][e.rev].weight += d;
        return d;
      }
    }
  }
  return 0;
}