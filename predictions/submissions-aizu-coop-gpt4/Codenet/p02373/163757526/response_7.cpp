#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
const int MAXN = 100005;
const int LOGN = 20;

void dfs(int start_node, vector<vector<int>>& adjList, vector<ii>& path, vector<int>& idx_in_path) {
  stack<pair<int, pair<int, ii>>> dfsStack;
  dfsStack.push({start_node, {0, {0, start_node}}});
  int path_size = 0;
  while (!dfsStack.empty()) {
    int u = dfsStack.top().first;
    int depth = dfsStack.top().second.first;
    ii current_path = dfsStack.top().second.second;
    dfsStack.pop();
    idx_in_path[u] = path_size;
    path[path_size++] = current_path;
    for (int v : adjList[u]) {
      dfsStack.push({v, {depth + 1, {depth, u}}});
      path[path_size++] = current_path;
    }
  }
}

void build(vector<ii>& path, vector<vector<ii>>& ST) {
  int n = path.size();
  int h = ceil(log2(n + 1));
  for (int i = 0; i < n; i++)
    ST[0][i] = path[i];
  for (int i = 1; i < h; i++)
    for (int j = 0; j + (1 << i) <= n; j++)
      ST[i][j] = min(ST[i - 1][j], ST[i - 1][j + (1 << (i - 1))]);
}

int lca(int u, int v, vector<int>& idx_in_path, vector<vector<ii>>& ST) {
  int l = idx_in_path[u], r = idx_in_path[v];
  if (l > r)
    swap(l, r);
  r++;
  int p = 31 - __builtin_clz(r - l);
  return min(ST[p][l], ST[p][r - (1 << p)]).second;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int num_nodes;
  cin >> num_nodes;
  vector<vector<int>> adjList(num_nodes);
  for (int u = 0; u < num_nodes; u++) {
    int num_neighbors;
    cin >> num_neighbors;
    for (int i = 0; i < num_neighbors; i++) {
      int v;
      cin >> v;
      adjList[u].push_back(v);
    }
  }
  vector<ii> path(num_nodes << 1);
  vector<int> idx_in_path(num_nodes);
  dfs(0, adjList, path, idx_in_path);
  vector<vector<ii>> ST(LOGN, vector<ii>(num_nodes << 1));
  build(path, ST);
  int num_queries;
  cin >> num_queries;
  for (int i = 0; i < num_queries; i++) {
    int u, v;
    cin >> u >> v;
    cout << lca(u, v, idx_in_path, ST) << '\n';
  }
  return 0;
}