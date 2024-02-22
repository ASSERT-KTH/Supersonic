#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef pair<int, int> ii;
typedef vector<int> vi;
const int MAXN = 100005;
const int LOGN = 20;
int idx_in_path[MAXN];
vector<ii> path;
vector<vi> adjList;
int path_size = 0;

void dfs(int u, int depth = 0) {
  idx_in_path[u] = path_size;
  path.push_back(ii(depth, u));
  path_size++;
  for (int v : adjList[u]) {
    dfs(v, depth + 1);
    path.push_back(ii(depth, u));
    path_size++;
  }
}

vector<vector<ii>> ST;

void build(int n) {
  int h = 0;
  while ((1 << h) <= n) h++;
  ST.resize(h, vector<ii>(n));
  for (int i = 0; i < n; i++)
    ST[0][i] = path[i];
  for (int i = 1; i < h; i++)
    for (int j = 0; j + (1 << i) <= n; j++)
      ST[i][j] = min(ST[i - 1][j], ST[i - 1][j + (1 << (i - 1))]);
}

int lca(int u, int v) {
  int l = idx_in_path[u], r = idx_in_path[v];
  if (l > r)
    swap(l, r);
  r++;
  int p = 31 - __builtin_clz(r - l);
  return min(ST[p][l], ST[p][r - (1 << p)]).se;
}

inline ii min(ii a, ii b) {
  return (a.fi < b.fi) ? a : b;
}

inline void swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

inline void printf(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9)
    printf(x / 10);
  putchar('0' + x % 10);
}

int main() {
  int num_nodes;
  scanf("%d", &num_nodes);
  adjList.resize(num_nodes);
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
  build(path_size);
  int num_queries;
  scanf("%d", &num_queries);
  for (int i = 0; i < num_queries; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    printf(lca(u, v));
    putchar('\n');
  }
  return 0;
}