#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

typedef std::pair<unsigned short, unsigned short> ii;
typedef std::vector<unsigned short> vi;

const unsigned short MAXN = 100005;
const unsigned short LOGN = 17;

unsigned short idx_in_path[MAXN];
ii path[(MAXN - 1) << 1];
std::vector<unsigned short> adjList[MAXN];
unsigned short path_size = 0;

void dfs(unsigned short u, unsigned short depth = 0) {
  idx_in_path[u] = path_size;
  path[path_size++] = ii(depth, u);
  for (unsigned short v : adjList[u]) {
    dfs(v, depth + 1);
    path[path_size++] = ii(depth, u);
  }
}

ii ST[LOGN][(MAXN - 1) << 1];

void build(unsigned short n) {
  unsigned short h = std::ceil(std::log2(n + 1));
  for (unsigned short i = 0; i < n; i++)
    ST[0][i] = path[i];
  for (unsigned short i = 1; i < h; i++) {
    for (unsigned short j = 0; j + (1 << i) <= n; j++) {
      ST[i][j] = std::min(ST[i - 1][j], ST[i - 1][j + (1 << (i - 1))]);
    }
  }
}

unsigned short lca(unsigned short u, unsigned short v) {
  unsigned short l = idx_in_path[u], r = idx_in_path[v];
  if (l > r)
    std::swap(l, r);
  r++;
  unsigned short p = LOGN - 1 - __builtin_clz(r - l);
  return std::min(ST[p][l], ST[p][r - (1 << p)]).second;
}

int main() {
  unsigned short num_nodes;
  std::cin >> num_nodes;
  for (unsigned short u = 0; u < num_nodes; u++) {
    unsigned short num_neighbors;
    std::cin >> num_neighbors;
    for (unsigned short i = 0; i < num_neighbors; i++) {
      unsigned short v;
      std::cin >> v;
      adjList[u].push_back(v);
    }
  }
  dfs(0);
  build(path_size);
  unsigned short num_queries;
  std::cin >> num_queries;
  for (unsigned short i = 0; i < num_queries; i++) {
    unsigned short u, v;
    std::cin >> u >> v;
    std::cout << lca(u, v) << std::endl;
  }
  return 0;
}