#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int tgt_;

  explicit Edge(int t) : tgt_(t) {}
};

typedef vector<vector<Edge>> Adj_list;

vector<int> topological_sort(Adj_list G) {
  const int V = G.size();
  vector<int> inorder(V, 0);

  for (int i = 0; i < V; i++)
    for (Edge &e : G[i])
      inorder[e.tgt_]++;
  
  stack<int> S;
  for (int i = 0; i < V; i++)
    if (inorder[i] == 0)
      S.push(i);
  
  assert(!S.empty());
  
  vector<int> topological_order;
  topological_order.reserve(V);
  
  while (!S.empty()) {
    int v = S.top();
    S.pop();
    topological_order.push_back(v);
    for (auto &e : G[v]) {
      int &inorder_tgt = inorder[e.tgt_];
      inorder_tgt--;
      if (inorder_tgt == 0)
        S.push(e.tgt_);
    }
  }
  
  for (int i = 0; i < V; i++)
    assert(inorder[i] == 0);
  
  return topological_order;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int V, E;
  cin >> V >> E;

  Adj_list G(V);
  for (int i = 0; i < E; i++) {
    int s, t;
    cin >> s >> t;
    G[s].push_back(Edge(t));
  }

  vector<int> ans = topological_sort(G);
  for (int i : ans)
    cout << i << "\n";
}