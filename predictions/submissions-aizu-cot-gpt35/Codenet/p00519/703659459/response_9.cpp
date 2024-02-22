#include <iostream>
#include <vector>
#include <limits>

constexpr int MAX_NODES = 6000;
constexpr int INF = std::numeric_limits<int>::max();

std::vector<std::vector<int>> pass(MAX_NODES);
std::vector<int> c(MAX_NODES);
std::vector<int> r(MAX_NODES);
std::vector<int> d(MAX_NODES, INF);
std::vector<bool> used(MAX_NODES);

void dfs(int v, int u, int f, int end, std::vector<bool>& visited) {
  if (visited[u])
    return;
  visited[u] = true;
  d[u] = std::min(d[u], d[v] + c[v]);
  if (f >= end)
    return;
  for (auto i : pass[u]) {
    dfs(v, i, f + 1, end, visited);
  }
}

int dijk(int s, int g) {
  std::fill(d.begin(), d.end(), INF);
  std::fill(used.begin(), used.end(), false);
  d[s] = 0;
  while (true) {
    int v = -1;
    for (int u = 0; u < MAX_NODES; u++) {
      if (!used[u] && (v == -1 || d[u] < d[v]))
        v = u;
    }
    if (v == -1)
      break;
    used[v] = true;
    for (auto i : pass[v]) {
      std::vector<bool> visited(MAX_NODES, false);
      dfs(v, i, 1, r[v], visited);
    }
  }
  return d[g];
}

int main() {
  int n, k;
  std::cin >> n >> k;
  for (int i = 0; i < n; i++) {
    std::cin >> c[i] >> r[i];
  }
  pass.reserve(k);
  for (int i = 0; i < k; i++) {
    int a, b;
    std::cin >> a >> b;
    a--, b--;
    pass[a].emplace_back(b);
    pass[b].emplace_back(a);
  }
  std::cout << dijk(0, n - 1) << std::endl;
  return 0;
}