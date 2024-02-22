#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef pair<int, int> ii;
typedef vector<int> vi;
const int MAXN = 100005;
const int LOGN = 20;
int idx_in_path[MAXN];
int path[MAXN << 1];
vi adjList[MAXN];
int path_size = 0;

void dfs(int u, int depth = 0) {
  idx_in_path[u] = path_size;
  path[path_size++] = u;
  for (int v : adjList[u]) {
    dfs(v, depth + 1);
  }
  path[path_size++] = u;
}

int lca(int u, int v) {
  int l = idx_in_path[u], r = idx_in_path[v];
  if (l > r)
    swap(l, r);
  r++;
  int min_depth = INT_MAX;
  int lca_node = -1;
  for (int i = l; i <= r; i++) {
    if (path[i] < min_depth) {
      min_depth = path[i];
      lca_node = path[i];
    }
  }
  return lca_node;
}

int main() {
  #pragma GCC optimize("O2")
  int num_nodes;
  scanf("%d", &num_nodes);
  for (int u = 0; u < num_nodes; u++) {
    int num_neighbors;
    scanf("%d", &num_neighbors);
    for (int i = 0; i < num_neighbors; i++) {
      int v;
      scanf("%d", &v);
      adjList[u].push_back(v);
    }
  }
  dfs(0);
  int num_queries;
  scanf("%d", &num_queries);
  for (int i = 0; i < num_queries; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    printf("%d\n", lca(u, v));
  }
  return 0;
}