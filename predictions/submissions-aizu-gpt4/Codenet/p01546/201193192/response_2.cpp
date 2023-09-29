#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAX 155

struct Edge {
  int to, c;
};

int V, K, E, dp[MAX][MAX], prv[MAX][MAX];
std::vector<std::vector<Edge>> adj;

void restore(int step, int v) {
  int c = step;
  std::vector<int> path;
  while (v != -1) {
    path.push_back(v);
    v = prv[c--][v];
  }
  std::reverse(path.begin(), path.end());
  for(int i = 0; i < step + 1; ++i) std::cout << path[i] << (i < step ? " " : "\n");
}

bool shortPhase() {
  memset(dp, -1, sizeof(dp));
  memset(prv, -1, sizeof(prv));
  for(int v = 0; v < V; ++v) dp[0][v] = 0;
  int max_score = -1, step = -1, terminal = -1;
  for(int i = 0; i < 150; ++i) {
    for(int v = 0; v < V; ++v) {
      if (dp[i][v] == -1)
        continue;
      for (Edge &e : adj[v]) {
        if (dp[i + 1][e.to] < dp[i][v] + e.c) {
          dp[i + 1][e.to] = dp[i][v] + e.c;
          prv[i + 1][e.to] = v;
          if (max_score < dp[i + 1][e.to]) {
            max_score = dp[i + 1][e.to];
            terminal = e.to;
          }
        }
      }
    }
    if (max_score >= K) {
      step = i + 1;
      break;
    }
  }
  if (max_score >= K) {
    std::cout << step << std::endl;
    restore(step, terminal);
    return true;
  }
  if (max_score == -1) {
    std::cout << -1 << std::endl;
    return true;
  }
  return false;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cin >> V >> E >> K;
  adj.resize(V);
  for(int i = 0; i < E; ++i) {
    int u, v, c;
    std::cin >> u >> v >> c;
    adj[u].push_back(Edge{v, c});
  }
  shortPhase();
  return 0;
}