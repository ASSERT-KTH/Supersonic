#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define for_(i, a, b) for (int i = (a); i < (b); ++i)
#define for_rev(i, a, b) for (int i = (a); i >= (b); --i)

using namespace std;

typedef vector<int> Ary;
typedef vector<Ary> Mat;

struct Edge {
  int to, c;
};

int V, K, E, dp[155][155], prv[155][155];
vector<vector<Edge>> adj;

void maxUpdate(int &a, int b) {
  a = max(a, b);
}

void mul(Mat &res, Mat &a, Mat &b) {
  int N = a.size();
  Mat temp(N, Ary(N, -1));
  for_(i, 0, N) for_(k, 0, N) if (a[i][k] >= 0) for_(j, 0, N) if (b[k][j] >= 0)
    maxUpdate(temp[i][j], a[i][k] + b[k][j]);
  res.swap(temp);
}

void restore(int step, int v) {
  vector<int> path;
  for (int c = step; c >= 0; --c) {
    path.push_back(v);
    v = prv[c][v];
  }
  for (auto it = path.rbegin(); it != path.rend(); ++it)
    cout << *it << (it + 1 != path.rend() ? " " : "\n");
}

bool shortPhase() {
  memset(dp, -1, sizeof(dp));
  memset(prv, -1, sizeof(prv));
  dp[0][0] = 0;
  int max_score = -1, step = -1, terminal = -1;
  for_(i, 0, 150) {
    bool update = false;
    for_(v, 0, V) {
      if (dp[i][v] == -1) continue;
      for (Edge e : adj[v]) {
        if (dp[i + 1][e.to] < dp[i][v] + e.c) {
          dp[i + 1][e.to] = dp[i][v] + e.c;
          prv[i + 1][e.to] = v;
          if (max_score < dp[i + 1][e.to]) {
            max_score = dp[i + 1][e.to];
            terminal = e.to;
            update = true;
          }
        }
      }
    }
    if (!update || max_score >= K) {
      step = i + 1;
      break;
    }
  }
  if (max_score >= K) {
    cout << step << "\n";
    restore(step, terminal);
    return true;
  }
  return false;
}

int calcMinStep() {
  Mat mat[21], ini(V, Ary(V, -1));
  for_(v, 0, V) for (Edge e : adj[v]) { maxUpdate(ini[v][e.to], e.c); }
  mat[0] = ini;
  for_(i, 0, 20) mul(mat[i + 1], mat[i], mat[i]);
  int res = 0;
  Mat x(V, Ary(V, -1));
  for_(v, 0, V) x[v][v] = 0;
  for_rev(h, 19, 0) {
    Mat nx;
    mul(nx, x, mat[h]);
    int max_score = 0;
    for_(u, 0, V) for_(v, 0, V) maxUpdate(max_score, nx[u][v]);
    if (max_score < K) {
      x.swap(nx);
      res += 1 << h;
    }
  }
  return res + 1;
}

int main() {
  cin >> V >> E >> K;
  adj.resize(V);
  for_(i, 0, E) {
    int u, v, c;
    cin >> u >> v >> c;
    adj[u].push_back(Edge{v, c});
  }
  if (!shortPhase()) {
    int ans = calcMinStep();
    cout << (ans > (int)1e6 ? -1 : ans) << "\n";
  }
  return 0;
}