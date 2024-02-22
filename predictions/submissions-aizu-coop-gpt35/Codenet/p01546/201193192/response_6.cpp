#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

#define for_(i, a, b) for (int i = (a); i < (b); ++i)
#define for_rev(i, a, b) for (int i = (a); i >= (b); --i)

const int MAX_V = 155;
const int MAX_E = 155;

struct Edge {
  int to, c;
};

void maxUpdate(int &a, int b) { a = std::max(a, b); }

void mul(int res[MAX_V][MAX_V], int a[MAX_V][MAX_V], int b[MAX_V][MAX_V], int N) {
  for_(i, 0, N) {
    for_(j, 0, N) {
      res[i][j] = a[i][j];
      for_(k, 0, N) {
        if (a[i][k] >= 0 && b[k][j] >= 0) {
          maxUpdate(res[i][j], a[i][k] + b[k][j]);
        }
      }
    }
  }
}

int V, K, E;
int dp[2][MAX_V];
int prv[2][MAX_V];
std::vector<std::vector<Edge>> adj;

void restore(int step, int v) {
  int c = step;
  std::vector<int> path;
  while (v != -1) {
    path.push_back(v);
    v = prv[c--][v];
  }
  std::reverse(path.begin(), path.end());
  for_(i, 0, step + 1) std::cout << path[i] << (i < step ? " " : "\n");
}

bool shortPhase() {
  memset(dp, -1, sizeof(dp));
  memset(prv, -1, sizeof(prv));
  for_(v, 0, V) dp[0][v] = 0;
  int max_score = -1, step = -1, terminal = -1;
  for_(i, 0, 150) {
    for_(v, 0, V) {
      if (dp[i % 2][v] == -1)
        continue;
      for (Edge e : adj[v]) {
        if (dp[(i + 1) % 2][e.to] < dp[i % 2][v] + e.c) {
          dp[(i + 1) % 2][e.to] = dp[i % 2][v] + e.c;
          prv[(i + 1) % 2][e.to] = v;
          if (max_score < dp[(i + 1) % 2][e.to]) {
            max_score = dp[(i + 1) % 2][e.to];
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
  int mat[21][MAX_V][MAX_V];
  int ini[MAX_V][MAX_V];
  for_(v, 0, V) {
    for (Edge e : adj[v]) {
      maxUpdate(ini[v][e.to], e.c);
    }
  }
  memcpy(mat[0], ini, sizeof(ini));
  for_(i, 0, 20) {
    mul(mat[i + 1], mat[i], mat[i], V);
  }
  int res = 0;
  int x[MAX_V][MAX_V], nx[MAX_V][MAX_V];
  memset(x, -1, sizeof(x));
  for_(v, 0, V) x[v][v] = 0;
  for_rev(h, 19, 0) {
    mul(nx, x, mat[h], V);
    int max_score = 0;
    for_(u, 0, V) {
      for_(v, 0, V) {
        maxUpdate(max_score, nx[u][v]);
      }
    }
    if (max_score < K) {
      memcpy(x, nx, sizeof(nx));
      res += 1 << h;
    }
  }
  return res + 1;
}

void solve() {
  if (!shortPhase()) {
    int ans = calcMinStep();
    std::cout << (ans > (int)1e6 ? -1 : ans) << std::endl;
  }
}

int main() {
  std::cin >> V >> E >> K;
  adj.assign(V, std::vector<Edge>());
  for_(i, 0, E) {
    int u, v, c;
    std::cin >> u >> v >> c;
    adj[u].push_back(Edge{v, c});
  }
  solve();
}