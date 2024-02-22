#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <cstring>
using namespace std;

constexpr int MAX_SCORE = -1;
constexpr int MAX_V = 155;
constexpr int MAX_E = 155;

struct Edge {
  int to, c;
};

void maxUpdate(int &a, int b) { a = max(a, b); }

void mul(vector<vector<int>> &res, vector<vector<int>> &a, vector<vector<int>> &b) {
  int N = a.size();
  res = a;
  for(int i=0; i<N; ++i) {
    for(int j=0; j<N; ++j) {
      for(int k=0; k<N; ++k) {
        if (a[i][k] >= 0 && b[k][j] >= 0)
          maxUpdate(res[i][j], a[i][k] + b[k][j]);
      }
    }
  }
}

bool shortPhase(int V, int K, vector<vector<Edge>> adj) {
  array<array<int, MAX_V>, MAX_V> dp;
  array<array<int, MAX_V>, MAX_V> prv;
  memset(dp.data(), -1, dp.size()*sizeof(int));
  memset(prv.data(), -1, prv.size()*sizeof(int));
  for(int v=0; v<V; ++v) {
    dp[0][v] = 0;
  }

  int max_score = MAX_SCORE;
  int step = MAX_SCORE;
  int terminal = MAX_SCORE;

  for(int i=0; i<150; ++i) {
    for(int v=0; v<V; ++v) {
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

  if (max_score == MAX_SCORE) {
    cout << -1 << endl;
    return true;
  }

  return false;
}

int main() {
  int V, K, E;
  cin >> V >> E >> K;
  
  vector<vector<Edge>> adj(V, vector<Edge>());
  for(int i=0; i<E; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    adj[u].push_back(Edge{v, c});
  }

  solve(V, E, K, adj);
}