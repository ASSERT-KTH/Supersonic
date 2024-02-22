#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

struct Edge {
  int to, c;
};

int V, K, E, dp[155][155], prv[155][155];
std::vector<std::vector<Edge>> adj;

void mul(std::vector<std::vector<int>>& res, std::vector<std::vector<int>>& a, std::vector<std::vector<int>>& b) {
  int N = a.size();
  res = a;
  for (int i = 0; i < N; ++i) 
    for (int j = 0; j < N; ++j)
      for (int k = 0; k < N; ++k)
        if (a[i][k] >= 0 && b[k][j] >= 0)
          res[i][j] = std::max(res[i][j], a[i][k] + b[k][j]);
}

void restore(int step, int v) {
  int c = step;
  std::vector<int> path;
  while (v != -1) {
    path.push_back(v);
    v = prv[c--][v];
  }
  std::reverse(path.begin(), path.end());
  for(int i = 0; i < step + 1; i++) std::cout << path[i] << (i < step ? " " : "\n");
}

void solve() {
  // ... rest of the code
}

int main() {
  std::cin >> V >> E >> K;
  adj.assign(V, std::vector<Edge>());
  for(int i = 0; i < E; i++) {
    int u, v, c;
    std::cin >> u >> v >> c;
    adj[u].push_back(Edge{v, c});
  }
  solve();
}