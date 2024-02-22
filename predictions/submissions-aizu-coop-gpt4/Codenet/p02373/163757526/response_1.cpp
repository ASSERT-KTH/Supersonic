#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>
#define MAXN 100005
#define LOGN 20
using namespace std;

int idx_in_path[MAXN], path[MAXN << 1][2], adjList[MAXN][MAXN], ST[LOGN][MAXN << 1], path_size = 0;

void dfs(int root, int num_nodes) {
  stack<pair<int, int>> s;
  s.push({root, 0});
  while (!s.empty()) {
    auto [u, depth] = s.top(); s.pop();
    idx_in_path[u] = path_size;
    path[path_size][0] = depth;
    path[path_size++][1] = u;
    for (int i = 0; i < num_nodes; i++) {
      if (adjList[u][i] == 1) {
        s.push({i, depth + 1});
        path[path_size][0] = depth;
        path[path_size++][1] = u;
      }
    }
  }
}

void build(int n) {
  int h = ceil(log2(n + 1));
  for (int i = 0; i < n; i++)
    ST[0][i] = i;
  for (int i = 1; i < h; i++)
    for (int j = 0; j + (1 << i) <= n; j++)
      ST[i][j] = (path[ST[i - 1][j]][0] < path[ST[i - 1][j + (1 << (i - 1))]][0]) ? ST[i - 1][j] : ST[i - 1][j + (1 << (i - 1))];
}

int lca(int u, int v) {
  int l = idx_in_path[u], r = idx_in_path[v];
  if (l > r)
    swap(l, r);
  r++;
  int p = 31 - __builtin_clz(r - l);
  return path[(path[ST[p][l]][0] < path[ST[p][r - (1 << p)]][0]) ? ST[p][l] : ST[p][r - (1 << p)]][1];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int num_nodes;
  cin >> num_nodes;
  for (int u = 0; u < num_nodes; u++) {
    int num_neighbors;
    cin >> num_neighbors;
    for (int i = 0; i < num_neighbors; i++) {
      int v;
      cin >> v;
      adjList[u][v] = 1;
    }
  }
  dfs(0, num_nodes);
  build(path_size);
  int num_queries;
  cin >> num_queries;
  for (int i = 0; i < num_queries; i++) {
    int u, v;
    cin >> u >> v;
    cout << lca(u, v) << "\n";
  }
  return 0;
}