#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int tgt_;
  Edge(int t) : tgt_(t) {}
};

typedef vector<vector<Edge>> Adj_list;

vector<int> topological_sort(Adj_list& G) {
  const int V = G.size();
  vector<int> S;
  S.reserve(V);  // reserve memory for stack
  vector<int> inorder(V, 0);
  for (int i = 0; i < V; ++i)  // Use pre-increment
    for (Edge& e : G[i])  // reference to avoid copy
      ++inorder[e.tgt_];  // Use pre-increment
  for (int i = 0; i < V; ++i)  // Use pre-increment
    if (inorder[i] == 0)
      S.push_back(i);
  assert(!S.empty());
  vector<int> topological_order;
  topological_order.reserve(V);  // reserve memory for result
  while (!S.empty()) {
    int v = S.back();
    S.pop_back();
    topological_order.push_back(v);
    for (int i = G[v].size() - 1; i >= 0; --i) {  // Use pre-decrement
      Edge& e = G[v][i];  // reference to avoid copy
      if (--inorder[e.tgt_] == 0)  // Use pre-decrement
        S.push_back(e.tgt_);
    }
  }
  for (int i = 0; i < V; ++i)  // Use pre-increment
    assert(inorder[i] == 0);
  return topological_order;
}

int main() {
  int V, E;
  cin >> V >> E;
  Adj_list G(V);
  G.reserve(E);  // reserve memory for the adjacency list
  for (int i = 0; i < E; ++i) {  // Use pre-increment
    int s, t;
    cin >> s >> t;
    G[s].emplace_back(t);
  }
  vector<int> ans = topological_sort(G);
  for (int i : ans)
    cout << i << endl;
}