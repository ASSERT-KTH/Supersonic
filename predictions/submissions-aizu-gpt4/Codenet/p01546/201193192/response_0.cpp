#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

#define for_(i, a, b) for (int i = (a); i < (b); ++i)

struct Edge {
  int to, c;
};

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
  for_(i, 0, 150) {
    for_(v, 0, V) {
      if (dp[i][v] == -1)
        continue;
      for (Edge& e : adj[v]) {
        int new_score = dp[i][v] + e.c;
        if (dp[i + 1][e.to] < new_score) {
          dp[i + 1][e.to] = new_score;
          prv[i + 1][e.to] = v;
          if (max_score < new_score) {
            max_score = new_score;
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

int main() {
  cin >> V >> E >> K;
  adj.resize(V);
  for_(i, 0, E) {
    int u, v, c;
    cin >> u >> v >> c;
    adj[u].push_back(Edge{v, c});
  }
  shortPhase();
}