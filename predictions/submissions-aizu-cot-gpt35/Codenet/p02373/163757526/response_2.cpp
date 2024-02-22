#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

typedef std::pair<int, int> pii;
typedef std::vector<int> vi;

const int MAXN = 100005;
const int LOGN = 20;

int idx_in_path[MAXN];
std::vector<pii> path;
std::vector<vi> adjList;

void dfs(int u, int depth, std::vector<pii>& path) {
  idx_in_path[u] = path.size();
  path.push_back(pii(depth, u));
  for (int v : adjList[u]) {
    dfs(v, depth + 1, path);
    path.push_back(pii(depth, u));
  }
}

std::vector<std::vector<pii>> ST;

void build(int n) {
  int h = std::ceil(std::log2(n + 1));
  ST.resize(h, std::vector<pii>(n));
  for (int i = 0; i < n; i++)
    ST[0][i] = path[i];
  for (int i = 1; i < h; i++)
    for (int j = 0; j + (1 << i) <= n; j++)
      ST[i][j] = std::min(ST[i - 1][j], ST[i - 1][j + (1 << (i - 1))]);
}

int lca(int u, int v) {
  int l = idx_in_path[u], r = idx_in_path[v];
  if (l > r)
    std::swap(l, r);
  r++;
  int p = 31 - __builtin_clz(r - l);
  return std::min(ST[p][l], ST[p][r - (1 << p)]).second;
}

int main() {
  int num_nodes;
  std::cin >> num_nodes;
  adjList.resize(num_nodes);
  for (int u = 0; u < num_nodes; u++) {
    int num_neighbors;
    std::cin >> num_neighbors;
    for (int i = 0; i < num_neighbors; i++) {
      int v;
      std::cin >> v;
      adjList[u].push_back(v);
    }
  }
  dfs(0, 0, path);
  build(path.size());
  int num_queries;
  std::cin >> num_queries;
  for (int i = 0; i < num_queries; i++) {
    int u, v;
    std::cin >> u >> v;
    std::cout << lca(u, v) << std::endl;
  }
  return 0;
}