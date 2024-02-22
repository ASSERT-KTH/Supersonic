#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

typedef std::vector<int> Ary;
typedef std::vector<Ary> Mat;

struct Edge {
  int to, c;
};

void maxUpdate(int &a, int b) {
  a = std::max(a, b);
}

void mul(Mat &res, Mat &a, Mat &b) {
  int N = a.size();
  res = a;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k < N; ++k) {
        if (a[i][k] >= 0 && b[k][j] >= 0) {
          maxUpdate(res[i][j], a[i][k] + b[k][j]);
        }
      }
    }
  }
}

int V, K, E;
std::vector<std::vector<Edge>> adj;
int dp[155][155], prv[155][155];

void restore(int step, int v) {
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

bool shortPhase() {
  memset(dp, -1, sizeof(dp));
  memset(prv, -1, sizeof(prv));
  for (int v = 0; v < V; ++v) {
    dp[0][v] = 0;
  }
  int max_score = -1, step = -1, terminal = -1;
  for (int i = 0; i < 150; ++i) {
    for (int v = 0; v < V; ++v) {
      if (dp[i][v] == -1) {
        continue;
      }
      for (Edge e : adj[v]) {
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

int calcMinStep() {
  Mat mat[21], ini(V, Ary(V, -1));
  for (int v = 0; v < V; ++v) {
    for (Edge e : adj[v]) {
      maxUpdate(ini[v][e.to], e.c);
    }
  }
  mat[0] = ini;
  for (int i = 0; i < 20; ++i) {
    mul(mat[i + 1], mat[i], mat[i]);
  }
  int res = 0;
  Mat x(V, Ary(V, -1)), nx;
  for (int v = 0; v < V; ++v) {
    x[v][v] = 0;
  }
  for (int h = 19; h >= 0; --h) {
    mul(nx, x, mat[h]);
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
  if (!shortPhase()) {
    int ans = calcMinStep();
    std::cout << (ans > 1e6 ? -1 : ans) << std::endl;
  }
}

int main() {
  std::cin >> V >> E >> K;
  adj.assign(V, std::vector<Edge>());
  for (int i = 0; i < E; ++i) {
    int u, v, c;
    std::cin >> u >> v >> c;
    adj[u].push_back(Edge{v, c});
  }
  solve();
}