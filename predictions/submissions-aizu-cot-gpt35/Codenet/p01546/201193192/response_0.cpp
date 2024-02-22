#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

typedef vector<int> Ary;
typedef vector<Ary> Mat;
typedef pair<int, int> pii;
struct Edge {
  int to, c;
};

void maxUpdate(int &a, int b) { a = max(a, b); }

void mul(Mat &res, Mat &a, Mat &b) {
  int N = a.size();
  res = a;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j <= i; ++j) {
      res[i][j] = -1;
      for (int k = 0; k < N; ++k) {
        if (a[i][k] >= 0 && b[k][j] >= 0)
          maxUpdate(res[i][j], a[i][k] + b[k][j]);
      }
      res[j][i] = res[i][j];
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
  for (int i = 0; i < step + 1; ++i) cout << path[i] << (i < step ? " " : "\n");
}

bool shortPhase() {
  memset(dp, -1, sizeof(dp));
  memset(prv, -1, sizeof(prv));
  for (int v = 0; v < V; ++v) dp[0][v] = 0;

  priority_queue<pii> pq;
  int max_score = -1, step = -1, terminal = -1;
  for (int i = 0; i < 150; ++i) {
    for (int v = 0; v < V; ++v) {
      if (dp[i][v] == -1)
        continue;
      for (Edge e : adj[v]) {
        if (dp[i + 1][e.to] < dp[i][v] + e.c) {
          dp[i + 1][e.to] = dp[i][v] + e.c;
          prv[i + 1][e.to] = v;
          pq.push({dp[i + 1][e.to], e.to});
          if (max_score < dp[i + 1][e.to]) {
            max_score = dp[i + 1][e.to];
            terminal = e.to;
          }
        }
      }
    }
    while (!pq.empty() && pq.top().first > dp[i + 1][pq.top().second]) pq.pop();
    if (!pq.empty() && pq.top().first >= K) {
      step = i + 1;
      break;
    }
  }
  if (step != -1) {
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
  Mat mat[6], ini(V, Ary(V, -1));
  for (int v = 0; v < V; ++v) {
    for (Edge e : adj[v]) {
      maxUpdate(ini[v][e.to], e.c);
    }
  }
  mat[0] = ini;
  for (int i = 0; i < 5; ++i) {
    mul(mat[i + 1], mat[i], mat[i]);
  }

  int res = 0;
  Mat x(V, Ary(V, -1)), nx;
  for (int v = 0; v < V; ++v) x[v][v] = 0;
  for (int h = 4; h >= 0; --h) {
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
    cout << (ans > (int)1e6 ? -1 : ans) << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> V >> E >> K;
  adj.assign(V, vector<Edge>());
  for (int i = 0; i < E; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    adj[u].push_back(Edge{v, c});
  }
  solve();

  return 0;
}