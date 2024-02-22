#include <iostream>
#include <vector>
#include <algorithm>

struct Edge {
  int to, c;
};

void maxUpdate(int& a, int b) {
  a = std::max(a, b);
}

void mul(std::vector<std::vector<int>>& a, const std::vector<std::vector<int>>& b) {
  int N = a.size();
  std::vector<std::vector<int>> res(N, std::vector<int>(N, -1));
  
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k < N; ++k) {
        if (a[i][k] >= 0 && b[k][j] >= 0) {
          maxUpdate(res[i][j], a[i][k] + b[k][j]);
        }
      }
    }
  }
  
  a = res;
}

void restore(int step, int v, const std::vector<std::vector<int>>& prv) {
  int c = step;
  std::vector<int> path;
  
  while (v != -1) {
    path.push_back(v);
    v = prv[c--][v];
  }
  
  std::reverse(path.begin(), path.end());
  
  for (int i = 0; i < step + 1; ++i) {
    std::cout << path[i] << (i < step ? " " : "\n");
  }
}

bool shortPhase(const std::vector<std::vector<Edge>>& adj, int V, int K) {
  std::vector<std::vector<int>> dp(155, std::vector<int>(155, -1));
  std::vector<std::vector<int>> prv(155, std::vector<int>(155, -1));
  
  for (int v = 0; v < V; ++v) {
    dp[0][v] = 0;
  }
  
  int max_score = -1, step = -1, terminal = -1;
  
  for (int i = 0; i < 150; ++i) {
    for (int v = 0; v < V; ++v) {
      if (dp[i][v] == -1) {
        continue;
      }
      
      for (const Edge& e : adj[v]) {
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
    restore(step, terminal, prv);
    return true;
  }
  
  if (max_score == -1) {
    std::cout << -1 << std::endl;
    return true;
  }
  
  return false;
}

int calcMinStep(const std::vector<std::vector<Edge>>& adj, int V, int K) {
  std::vector<std::vector<int>> ini(V, std::vector<int>(V, -1));
  
  for (int v = 0; v < V; ++v) {
    for (const Edge& e : adj[v]) {
      maxUpdate(ini[v][e.to], e.c);
    }
  }
  
  std::vector<std::vector<int>> x(V, std::vector<int>(V, -1)), nx;
  
  for (int v = 0; v < V; ++v) {
    x[v][v] = 0;
  }
  
  std::vector<std::vector<int>> mat = ini;
  int res = 0;
  
  for (int h = 19; h >= 0; --h) {
    mul(nx, x, mat);
    int max_score = 0;
    
    for (int u = 0; u < V; ++u) {
      for (int v = 0; v < V; ++v) {
        maxUpdate(max_score, nx[u][v]);
      }
    }
    
    if (max_score < K) {
      x = nx;
      res += 1 << h;
    }
  }
  
  return res + 1;
}

void solve() {
  int V, E, K;
  std::cin >> V >> E >> K;
  
  std::vector<std::vector<Edge>> adj(V, std::vector<Edge>());
  
  for (int i = 0; i < E; ++i) {
    int u, v, c;
    std::cin >> u >> v >> c;
    adj[u].push_back(Edge{v, c});
  }
  
  if (!shortPhase(adj, V, K)) {
    int ans = calcMinStep(adj, V, K);
    std::cout << (ans > (int)1e6 ? -1 : ans) << std::endl;
  }
}

int main() {
  solve();
  return 0;
}