#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef vector<int> Vector;
typedef vector<Vector> Matrix;

struct Edge {
  int to, c;
};

void maxUpdate(int &a, int b) { a = max(a, b); }

void mul(Matrix &res, Matrix &a, Matrix &b) {
  int N = a.size();
  res = a;

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      for(int k = 0; k < N; k++) {
        if (a[i][k] >= 0 && b[k][j] >= 0)
          maxUpdate(res[i][j], a[i][k] + b[k][j]);
      }
    }
  }
}

int V, K, E, dp[155][155], prv[155][155];
vector<vector<Edge>> adj;

void restore(int step, int v) {
  int c = step;
  vector<int> path;
  while (v != -1) {
    path.push_back(v);
    v = prv[c--][v];
  }
  reverse(path.begin(), path.end());

  for(int i = 0; i < step + 1; i++) cout << path[i] << (i < step ? " " : "\n");
}

bool shortPhase() {
  memset(dp, -1, sizeof(dp));
  memset(prv, -1, sizeof(prv));
  for(int v = 0; v < V; v++) dp[0][v] = 0;
  int max_score = -1, step = -1, terminal = -1;

  for(int i = 0; i < 150; i++) {
    for(int v = 0; v < V; v++) {
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
    cout << step << endl;
    restore(step, terminal);
    return true;
  }
  if (max_score == -1) {
    cout << -1 << endl;
    return true;
  }
  return false;
}

int calcMinStep() {
  Matrix mat[21], ini(V, Vector(V, -1));
  for(int v = 0; v < V; v++) for (Edge &e : adj[v]) { maxUpdate(ini[v][e.to], e.c); }
  mat[0] = ini;
  for(int i = 0; i < 20; i++) mul(mat[i + 1], mat[i], mat[i]);
  int res = 0;
  Matrix x(V, Vector(V, -1)), nx;
  for(int v = 0; v < V; v++) x[v][v] = 0;
  for(int h = 19; h >= 0; h--) {
    mul(nx, x, mat[h]);
    int max_score = 0;
    for(int u = 0; u < V; u++) for(int v = 0; v < V; v++) maxUpdate(max_score, nx[u][v]);
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
    cout << (ans > (int)1e6 ? -1 : ans) << endl;
  }
}

int main() {
  cin >> V >> E >> K;
  adj.assign(V, vector<Edge>());
  for(int i = 0; i < E; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    adj[u].push_back(Edge{v, c});
  }
  solve();
}