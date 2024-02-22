#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAXN = 100005;
const int LOGN = 20;
int idx_in_path[MAXN];
pair<int, int> path[2 * MAXN];
vector<int> adjList[MAXN];
int path_size = 0;

void dfs(int u, int depth = 0) {
  idx_in_path[u] = path_size;
  path[path_size++] = make_pair(depth, u);
  for (int v : adjList[u]) {
    dfs(v, depth + 1);
    path[path_size++] = make_pair(depth, u);
  }
}

pair<int, int> ST[LOGN][2 * MAXN];

void build(int n) {
  int h = ceil(log2(n + 1));
  memcpy(ST[0], path, n * sizeof(pair<int, int>));
  for (int i = 1; i < h; i++) {
    for (int j = 0; j + (1 << i) <= n; j++) {
      ST[i][j] = (ST[i - 1][j].first < ST[i - 1][j + (1 << (i - 1))].first) ? ST[i - 1][j] : ST[i - 1][j + (1 << (i - 1))];
    }
  }
}

int lca(int u, int v) {
  int l = idx_in_path[u], r = idx_in_path[v];
  if (l > r)
    swap(l, r);
  r++;
  int p = 31 - __builtin_clz(r - l);
  return (ST[p][l].first < ST[p][r - (1 << p)].first) ? ST[p][l].second : ST[p][r - (1 << p)].second;
}

int main() {
  int num_nodes;
  cin >> num_nodes;
  for (int u = 0; u < num_nodes; u++) {
    int num_neighbors;
    cin >> num_neighbors;
    for (int i = 0; i < num_neighbors; i++) {
      int v;
      cin >> v;
      adjList[u].push_back(v);
    }
  }
  dfs(0);
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