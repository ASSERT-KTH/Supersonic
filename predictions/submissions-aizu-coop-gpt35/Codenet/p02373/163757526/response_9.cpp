void dfs(int u, int depth = 0) {
  static int path_size = 0; // Local variable to track path size
  idx_in_path[u] = path_size;
  path[path_size++] = ii(depth, u);
  for (int v : adjList[u]) {
    dfs(v, depth + 1);
    path[path_size++] = ii(depth, u);
  }
}