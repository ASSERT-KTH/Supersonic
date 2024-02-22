#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int tgt_;
  Edge(int t) { tgt_ = t; }
};

typedef vector<vector<Edge>> Adj_list;

vector<int> topological_sort(Adj_list G) {
  const int V = G.size();
  vector<int> topological_order;
  vector<int> indegree(V, 0);
  queue<int> Q;
  
  for (int i = 0; i < V; i++) {
    for (const auto& e : G[i]) {
      indegree[e.tgt_]++;
    }
  }
  
  for (int i = 0; i < V; i++) {
    if (indegree[i] == 0) {
      Q.push(i);
    }
  }
  
  while (!Q.empty()) {
    int v = Q.front();
    Q.pop();
    topological_order.push_back(v);
    for (const auto& e : G[v]) {
      indegree[e.tgt_]--;
      if (indegree[e.tgt_] == 0) {
        Q.push(e.tgt_);
      }
    }
  }
  
  assert(topological_order.size() == V);
  
  return topological_order;
}

int main() {
  int V, E;
  cin >> V >> E;
  Adj_list G(V);
  
  for (int i = 0; i < E; i++) {
    int s, t;
    cin >> s >> t;
    G[s].push_back(Edge(t));
  }
  
  vector<int> ans = topological_sort(G);
  
  for (int i = 0; i < V; i++) {
    cout << ans[i] << endl;
  }
  
  return 0;
}