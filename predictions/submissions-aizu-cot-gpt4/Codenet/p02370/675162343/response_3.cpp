#include <iostream>
#include <vector>
#include <cassert>

struct Edge {
  int tgt_;
  Edge(int t) : tgt_(t) {}
};

typedef std::vector<std::vector<Edge>> Adj_list;

std::vector<int> topological_sort(Adj_list& G) {
  const int V = G.size();
  std::vector<int> S;
  std::vector<int> inorder(V, 0);
  for (int i = 0; i < V; i++) {
    for (const Edge &e : G[i]) {
      inorder[e.tgt_]++;
    }
  }
  for (int i = 0; i < V; i++) {
    if (inorder[i] == 0) {
      S.push_back(i);
    }
  }
  assert(!S.empty());
  std::vector<int> topological_order;
  topological_order.reserve(V);
  while (!S.empty()) {
    int v = S.back();
    S.pop_back();
    topological_order.push_back(v);
    for (const Edge &e : G[v]) {
      inorder[e.tgt_]--;
      if (inorder[e.tgt_] == 0) {
        S.push_back(e.tgt_);
      }
    }
  }
  for (int i = 0; i < V; i++) {
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
    G[s].push_back(Edge(t));
  }
  std::vector<int> ans = topological_sort(G);
  for (int i = 0; i < V; i++) {
    std::cout << ans[i] << std::endl;
  }
}