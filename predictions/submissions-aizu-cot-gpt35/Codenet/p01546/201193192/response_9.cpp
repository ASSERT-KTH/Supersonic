#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define for_(i, a, b) for (int i = (a); i < (b); ++i)

struct Edge {
  int to, c;
};

const int MAX_V = 155;
const int MAX_E = 10005;
const int INF = 1e9;

int V, K, E;
int dp[MAX_V][MAX_V], prv[MAX_V][MAX_V];
std::vector<std::vector<Edge>> adj;

void maxUpdate(int &a, int b) {
  a = std::max(a, b);
}

void mul(int res[MAX_V][MAX_V], int a[MAX_V][MAX_V], int b[MAX_V][MAX_V]) {
  int N = V;
  for_(i, 0, N) {
    for_(j, 0, N) {
      res[i][j] = -INF;
      for_(k, 0, N) {
        if (a[i][k] >= 0 && b[k][j] >= 0) {
          maxUpdate(res[i][j], a[i][k] + b[k][j]);
        }
      }
    }
  }
}

void restore(int step, int v) {
  int c = step;
  std::vector<int> path;
  while (v != -1) {
    path.push_back(v);
    v = prv[c--][v];
  }
  std::reverse(path.begin(), path.end());
  for_(i, 0, step + 1) {
    std::cout << path[i] << (i < step ? " " : "\n");
  }
}

bool shortPhase() {
  memset(dp, -1, sizeof(dp));
  memset(prv, -1, sizeof(prv));
  for_(v, 0, V) {
    dp[0][v] = 0;
  }
  int max_score = -1, step = -1;
  for_(i, 0, 150) {
    for_(v, 0, V) {
      if (dp[i][v] == -1) {
        continue;
      }
      for (Edge e : adj[v]) {
        if (dp[i + 1][e.to] < dp[i][v] + e.c) {
          dp[i + 1][e.to] = dp[i][v] + e.c;
          prv[i + 1][e.to] = v;
          if (max_score < dp[i + 1][e.to]) {
            max_score = dp[i + 1][e.to];
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
    restore(step, std::max_element(dp[step], dp[step] + V) - dp[step]);
    return true;
  }
  if (max_score == -1) {
    std::cout << -1 << std::endl;
    return true;
  }
  return false;
}

int calcMinStep() {
  int res = 0;
  int x[MAX_V][MAX_V], nx[MAX_V][MAX_V];
  for_(v, 0, V) {
    for_(u, 0, V) {
      x[u][v] = (u == v ? 0 : -INF);
    }
    for (Edge e : adj[v]) {
      maxUpdate(x[v][e.to], e.c);
    }
  }
  for_(h, 19, -1) {
    mul(nx, x, x);
    int max_score = 0;
    for_(u, 0, V) {
      for_(v, 0, V) {
        maxUpdate(max_score, nx[u][v]);
      }
    }
    if (max_score < K) {
      for_(u, 0, V) {
        for_(v, 0, V) {
          x[u][v] = nx[u][v];
        }
      }
      res += 1 << h;
    }
  }
  return res + 1;
}

void solve() {
  if (!shortPhase()) {
    int ans = calcMinStep();
    std::cout << (ans > 1e6 ? -1 : ans) << std::endl;
  }
}

int main() {
  std::cin >> V >> E >> K;
  adj.reserve(V);
  for_(i, 0, E) {
    int u, v, c;
    std::cin >> u >> v >> c;
    adj[u].push_back(Edge{v, c});
  }
  solve();
}