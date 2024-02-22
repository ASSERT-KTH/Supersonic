#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 100005;
const int LOGN = 20;

vector<int> adjList[MAXN];
pii path[MAXN << 1];
int idx_in_path[MAXN];
int path_size = 0;

// DFS to prepare the path array
void dfs(int node, int depth = 0) {
  idx_in_path[node] = path_size;
  path[path_size++] = make_pair(depth, node);
  for (int child : adjList[node]) {
    dfs(child, depth + 1);
    path[path_size++] = make_pair(depth, node);
  }
}

pii ST[LOGN][MAXN << 1];

// Building the Sparse Table
void build(int n) {
  int h = ceil(log2(n + 1));
  for (int i = 0; i < n; i++)
    ST[0][i] = path[i];
  for (int i = 1; i < h; i++) {
    int step = (1 << i);
    int half_step = (1 << (i - 1));
    for (int j = 0; j + step <= n; j++)
      ST[i][j] = min(ST[i - 1][j], ST[i - 1][j + half_step]);
  }
}

// Query the LCA
int lca(int u, int v) {
  int l = idx_in_path[u], r = idx_in_path[v];
  if (l > r)
    swap(l, r);
  r++;
  int p = 31 - __builtin_clz(r - l);
  pii left_range = ST[p][l];
  pii right_range = ST[p][r - (1 << p)];
  return min(left_range, right_range).second;
}

int main() {
  ios::sync_with_stdio(false); 
  cin.tie(NULL);
  
  int num_nodes;
  cin >> num_nodes;
  for (int i = 0; i < num_nodes; i++) {
    int num_neighbors;
    cin >> num_neighbors;
    for (int j = 0; j < num_neighbors; j++) {
      int neighbor;
      cin >> neighbor;
      adjList[i].push_back(neighbor);
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