#include <iostream>
#include <vector>
#include <cassert>

struct Edge {
  int tgt_;
  Edge(int t) { tgt_ = t; }
};

typedef std::vector<std::vector<Edge>> Adj_list;

std::vector<int> topological_sort(Adj_list& G) {
  const int V = G.size();
  std::vector<int> S;
  std::vector<int> inorder(V, 0);
  
  for (auto& edges : G)
    for (Edge& e : edges)
      inorder[e.tgt_]++;
  
  S.reserve(V);
  for (int i = 0; i < V; i++)
    if (inorder[i] == 0)
      S.emplace_back(i);
  
  assert(S.size() > 0);
  
  std::vector<int> topological_order;
  topological_order.reserve(V);
  
  while (!S.empty()) {
    int v = S.back();
    S.pop_back();
    topological_order.emplace_back(v);
    
    for (int i = G[v].size() - 1; i >= 0; i--) {
      Edge& e = G[v][i];
      inorder[e.tgt_]--;
      if (inorder[e.tgt_] == 0)
        S.emplace_back(e.tgt_);
    }
  }
  
  assert(inorder[0] == 0); // Assuming the graph is connected
  
  return topological_order;
}

int main() {
  int V, E;
  std::cin >> V >> E;
  
  Adj_list G(V);
  
  for (int i = 0; i < E; i++) {
    int s, t;
    std::cin >> s >> t;
    G[s].emplace_back(t);
  }
  
  std::vector<int> ans = topological_sort(G);
  
  for (int vertex : ans)
    std::cout << vertex << '\n';
  
  return 0;
}