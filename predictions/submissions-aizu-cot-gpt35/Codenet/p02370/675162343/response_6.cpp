#include <iostream>
#include <vector>
#include <cassert>

struct Edge {
  int tgt_;
  Edge(int t) { tgt_ = t; }
};

typedef std::vector<std::vector<Edge>> Adj_list;

std::vector<int> topological_sort(Adj_list& G) {
  const size_t V = G.size();
  std::vector<int> S;
  std::vector<int> inorder(V, 0);
  for (size_t i = 0; i < V; i++) {
    for (Edge& e : G[i]) {
      inorder[e.tgt_]++;
    }
  }
  for (size_t i = 0; i < V; i++) {
    if (inorder[i] == 0) {
      S.push_back(i);
    }
  }
  assert(S.size() > 0);
  std::vector<int> topological_order;
  topological_order.reserve(V);
  while (!S.empty()) {
    size_t v = S.back();
    S.pop_back();
    topological_order.emplace_back(v);
    for (size_t i = G[v].size(); i > 0; i--) {
      Edge e = G[v][i - 1];
      inorder[e.tgt_]--;
      if (inorder[e.tgt_] == 0) {
        S.push_back(e.tgt_);
      }
    }
  }
  for (size_t i = 0; i < V; i++) {
    assert(inorder[i] == 0);
  }
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
  for (int i = 0; i < V; i++) {
    std::cout << ans[i] << std::endl;
  }
  return 0;
}