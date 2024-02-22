#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef pair<int, int> ii;
const int MAXN = 100005;
const int LOGN = 20;
int idx_in_path[MAXN];
ii path[MAXN << 1];
int adjList[MAXN][MAXN];
int path_size = 0;

void dfs(int root) {
  stack<pair<int, int>> st;
  st.push({root, 0});

  while (!st.empty()) {
    int u = st.top().first;
    int depth = st.top().second;
    st.pop();
    
    idx_in_path[u] = path_size;
    path[path_size++] = ii(depth, u);

    for (int i = 0; i < adjList[u][0]; i++) {
      int v = adjList[u][i + 1];
      st.push({v, depth + 1});
      path[path_size++] = ii(depth, u);
    }
  }
}

ii ST[LOGN][MAXN << 1];

void build(int n) {
  for (int i = 0; i < n; i++)
    ST[0][i] = path[i];

  for (int i = 1; (1 << i) <= n; i++) {
    for (int j = 0; j + (1 << i) <= n; j++) {
      ST[i][j] = min(ST[i - 1][j], ST[i - 1][j + (1 << (i - 1))]);
    }
  }
}

int lca(int u, int v) {
  int l = idx_in_path[u], r = idx_in_path[v];
  if (l > r)
    swap(l, r);
  r++;
  int p = 31 - __builtin_clz(r - l);
  return min(ST[p][l], ST[p][r - (1 << p)]).se;
}

int main() {
  int num_nodes;
  scanf("%d", &num_nodes);
  for (int u = 0; u < num_nodes; u++) {
    int num_neighbors;
    scanf("%d", &num_neighbors);
    adjList[u][0] = num_neighbors;
    for (int i = 0; i < num_neighbors; i++) {
      int v;
      scanf("%d", &v);
      adjList[u][i + 1] = v;
    }
  }
  dfs(0);
  build(path_size);
  int num_queries;
  scanf("%d", &num_queries);
  for (int i = 0; i < num_queries; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    printf("%d\n", lca(u, v));
  }
  return 0;
}