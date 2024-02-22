#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef pair<int, int> ii;
typedef vector<int> vi;
const int MAXN = 100005;
const int LOGN = 20;
int idx_in_path[MAXN];
ii path[MAXN << 1];
vi adjList[MAXN];
int path_size = 0;
int log[MAXN+1];

void dfs(int u, int depth = 0) {
  idx_in_path[u] = path_size;
  path[path_size++] = ii(depth, u);
  for (int v : adjList[u]) {
    dfs(v, depth + 1);
    path[path_size++] = ii(depth, u);
  }
}

ii ST[LOGN][MAXN << 1];

void build(int n) {
  for (int i = 0; i < n; i++)
    ST[0][i] = path[i];

  #pragma omp parallel for
  for (int i = 1; i <= log[n]; i++)
    for (int j = 0; j + (1 << i) <= n; j++)
      ST[i][j] = (ST[i - 1][j] < ST[i - 1][j + (1 << (i - 1))]) ? ST[i - 1][j] : ST[i - 1][j + (1 << (i - 1))];
}

int lca(int u, int v) {
  int l = idx_in_path[u], r = idx_in_path[v];
  if (l > r) { int temp = l; l = r; r = temp; }
  r++;
  int p = log[r - l];
  return (ST[p][l] < ST[p][r - (1 << p)]) ? ST[p][l].se : ST[p][r - (1 << p)].se;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  log[1] = 0;
  for (int i = 2; i <= MAXN; i++)
    log[i] = log[i/2] + 1;
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