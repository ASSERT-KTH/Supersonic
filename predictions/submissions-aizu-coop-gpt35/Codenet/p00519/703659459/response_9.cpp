#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>

typedef long long ll;

const int INF = std::numeric_limits<int>::max();

std::unordered_map<int, std::vector<int>> adjList;
std::vector<int> c, r, d;
std::vector<bool> visited;

void dfs(int v, int u, int f, int end) {
  if (visited[u])
    return;
  visited[u] = true;
  d[u] = std::min(d[u], d[v] + c[v]);
  if (f >= end)
    return;
  for (int i : adjList[u]) {
    dfs(v, i, f + 1, end);
  }
}

int dijk(int s, int g) {
  int n = c.size();
  d.resize(n, INF);
  visited.resize(n, false);
  d[s] = 0;
  while (true) {
    int v = -1;
    for (int u = 0; u < n; u++) {
      if (!visited[u] && (v == -1 || d[u] < d[v]))
        v = u;
    }
    if (v == -1)
      break;
    visited[v] = true;
    for (int i : adjList[v]) {
      visited.assign(n, false); // Clear visited array
      dfs(v, i, 1, r[v]);
    }
  }
  return d[g];
}

int main() {
  int n, k;
  std::cin >> n >> k;
  c.resize(n);
  r.resize(n);
  for (int i = 0; i < n; i++) {
    std::cin >> c[i] >> r[i];
  }
  for (int i = 0; i < k; i++) {
    int a, b;
    std::cin >> a >> b;
    a--, b--;
    adjList[a].push_back(b);
    adjList[b].push_back(a);
  }
  std::cout << dijk(0, n - 1) << std::endl;

  return 0;
}