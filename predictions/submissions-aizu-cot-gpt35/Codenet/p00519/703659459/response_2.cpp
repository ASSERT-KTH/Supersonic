#include <iostream>
#include <vector>
#include <algorithm>

constexpr int INF = 999999999;

std::vector<int> pass[6000];
int n, k;
int c[6000];
int r[6000];
int d[6000];
bool used[6000];

void dfs(int v, int u, int f, int end, bool visited[6000]) {
  if (visited[u])
    return;

  visited[u] = true;
  d[u] = std::min(d[u], d[v] + c[v]);

  if (f >= end)
    return;

  for (int& next : pass[u]) {
    dfs(v, next, f + 1, end, visited);
  }
}

int dijk(int s, int g) {
  std::fill(d, d + 6000, INF);
  std::fill(used, used + 6000, false);
  d[s] = 0;

  while (true) {
    int v = -1;
    for (int u = 0; u < n; u++) {
      if (!used[u] && (v == -1 || d[u] < d[v]))
        v = u;
    }

    if (v == -1)
      break;

    used[v] = true;
    for (int& next : pass[v]) {
      bool visited[6000] = {};
      dfs(v, next, 1, r[v], visited);
    }
  }

  return d[g];
}

int main() {
  std::cin >> n >> k;
  for (int i = 0; i < n; i++)
    std::cin >> c[i] >> r[i];

  for (int i = 0; i < k; i++) {
    int a, b;
    std::cin >> a >> b;
    a--, b--;
    pass[a].push_back(b);
    pass[b].push_back(a);
  }

  std::cout << dijk(0, n - 1) << std::endl;
}