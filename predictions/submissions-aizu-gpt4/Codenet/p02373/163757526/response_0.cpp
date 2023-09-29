#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int LOGN = 20;
int idx_in_path[MAXN];
pair<int, int> path[MAXN << 1];
vector<int> adjList[MAXN];
int path_size = 0;
inline void dfs(int u, int depth = 0) {
  idx_in_path[u] = path_size;
  path[path_size++] = {depth, u};
  for (const auto& v : adjList[u]) {
    dfs(v, depth + 1);
    path[path_size++] = {depth, u};
  }
}
pair<int, int> ST[LOGN][MAXN << 1];
inline void build(int n) {
  int h = ceil(log2(n + 1));
  for (int i = 0; i < n; ++i)
    ST[0][i] = path[i];
  for (int i = 1; i < h; ++i)
    for (int j = 0; j + (1 << i) <= n; ++j)
      ST[i][j] = min(ST[i - 1][j], ST[i - 1][j + (1 << (i - 1))]);
}
inline int lca(int u, int v) {
  int l = idx_in_path[u], r = idx_in_path[v];
  if (l > r)
    swap(l, r);
  r++;
  int p = 31 - __builtin_clz(r - l);
  return min(ST[p][l], ST[p][r - (1 << p)]).second;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int num_nodes;
  cin >> num_nodes;
  for (int u = 0; u < num_nodes; ++u) {
    int num_neighbors;
    cin >> num_neighbors;
    adjList[u].resize(num_neighbors);
    for (auto& v : adjList[u])
      cin >> v;
  }
  dfs(0);
  build(path_size);
  int num_queries;
  cin >> num_queries;
  while(num_queries--) {
    int u, v;
    cin >> u >> v;
    cout << lca(u, v) << '\n';
  }
  return 0;
}