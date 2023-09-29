#include <bits/stdc++.h>
using namespace std;
#define for_(i, a, b) for (int i = (a); i < (b); ++i)
#define for_rev(i, a, b) for (int i = (a); i >= (b); --i)
typedef vector<int> Ary;
typedef vector<Ary> Mat;
struct Edge {
  int to, c;
};
void maxUpdate(int &a, int b) { a = max(a, b); }
void mul(Mat &res, Mat &a, Mat &b) {
  int N = a.size();
  res = a;
  for_(i, 0, N) for_(j, 0, N) for_(k, 0, N) {
    if (a[i][k] >= 0 && b[k][j] >= 0)
      maxUpdate(res[i][j], a[i][k] + b[k][j]);
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
  for_(i, 0, step + 1) cout << path[i] << (i < step ? " " : "\n");
}
bool shortPhase() {
  memset(dp, -1, sizeof(dp));
  memset(prv, -1, sizeof(prv));
  for_(v, 0, V) dp[0][v] = 0;
  int max_score = -1, step = -1, terminal = -1;
  for_(i, 0, 100) {
    for_(v, 0, V) {
      if (dp[i][v] == -1)
        continue;
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
  Mat mat[21], ini(V, Ary(V, -1));
  for_(v, 0, V) for (Edge e : adj[v]) { maxUpdate(ini[v][e.to], e.c); }
  mat[0] = ini;
  for_(i, 0, 20) mul(mat[i + 1], mat[i], mat[i]);
  int res = 0;
  Mat x(V, Ary(V, -1)), nx;
  for_(v, 0, V) x[v][v] = 0;
  for_rev(h, 19, 0) {
    mul(nx, x, mat[h]);
    int max_score = 0;
    for_(u, 0, V) for_(v, 0, V) maxUpdate(max_score, nx[u][v]);
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
  for_(i, 0, E) {
    int u, v, c;
    cin >> u >> v >> c;
    adj[u].push_back(Edge{v, c});
  }
  solve();
}
