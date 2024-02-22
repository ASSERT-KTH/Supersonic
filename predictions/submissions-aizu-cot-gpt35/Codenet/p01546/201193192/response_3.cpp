#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

#define for_(i, a, b) for (int i = (a); i < (b); ++i)

struct Edge {
  int to, c;
};

using Ary = vector<int>;
using Mat = vector<Ary>;

int V, K, E;
vector<vector<Edge>> adj;
bool dp[155][155];
int prv[155][155];

void restore(int step, int v) {
  int c = step;
  while (v != -1) {
    cout << v << (c > 0 ? " " : "\n");
    v = prv[c--][v];
  }
}

bool shortPhase() {
  memset(dp, false, sizeof(dp));
  memset(prv, -1, sizeof(prv));
  for_(v, 0, V) dp[0][v] = true;
  int max_score = -1, step = -1, terminal = -1;
  int i = 0;
  while (max_score < K && i < 150) {
    for_(v, 0, V) {
      if (!dp[i][v])
        continue;
      for (Edge e : adj[v]) {
        if (!dp[i + 1][e.to] && dp[i][v] + e.c >= 0) {
          dp[i + 1][e.to] = true;
          prv[i + 1][e.to] = v;
          if (max_score < dp[i + 1][e.to]) {
            max_score = dp[i + 1][e.to];
            terminal = e.to;
          }
        }
      }
    }
    step = i + 1;
    i++;
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
  Mat ini(V, Ary(V, -1));
  for_(v, 0, V) {
    for (Edge e : adj[v]) {
      ini[v][e.to] = e.c;
    }
  }
  Mat x = ini;
  int res = 0;
  int h = 0;
  while (h < 20) {
    Mat nx(V, Ary(V, -1));
    for_(i, 0, V) {
      for_(j, 0, V) {
        for_(k, 0, V) {
          if (x[i][k] >= 0 && ini[k][j] >= 0) {
            nx[i][j] = max(nx[i][j], x[i][k] + ini[k][j]);
          }
        }
      }
    }
    int max_score = 0;
    for_(u, 0, V) {
      for_(v, 0, V) {
        max_score = max(max_score, nx[u][v]);
      }
    }
    if (max_score < K) {
      x = nx;
      res += 1 << h;
    } else {
      break;
    }
    h++;
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