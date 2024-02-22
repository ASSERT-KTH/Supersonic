#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int tgt_;
  Edge(int t) { tgt_ = t; }
};

typedef vector<vector<Edge>> Adj_list;

vector<int> topological_sort(const Adj_list& G) {
  const int V = G.size();
  vector<int> topological_order;
  unordered_set<int> inorder;
  set<int> S;

  for (int i = 0; i < V; i++) {
    for (auto &e : G[i]) {
      inorder.insert(e.tgt_);
    }
  }

  for (int i = 0; i < V; i++) {
    if (inorder.count(i) == 0) {
      S.insert(i);
    }
  }

  while (!S.empty()) {
    int v = *S.begin();
    S.erase(S.begin());
    topological_order.push(v);

    for (auto it = G[v].rbegin(); it != G[v].rend(); ++it) {
      Edge e = *it;
      inorder.erase(e.tgt_);
      if (inorder.count(e.tgt_) == 0) {
        S.insert(e.tgt_);
      }
    }
  }

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
}