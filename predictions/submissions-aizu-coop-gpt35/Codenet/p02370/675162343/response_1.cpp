#include <iostream>
#include <vector>
#include <stack>
#include <cassert>

typedef std::vector<std::vector<int>> Adj_list;

std::vector<int> topological_sort(const Adj_list& G) {
  const int V = G.size();
  std::vector<int> S;
  std::vector<int> inorder(V, 0);
  G.reserve(V);
  S.reserve(V);
  inorder.reserve(V);
  std::vector<int> topological_order;
  topological_order.reserve(V);

  for (int i = 0; i < V; i++) {
    for (int tgt : G[i]) {
      inorder[tgt]++;
    }
  }

  for (int i = 0; i < V; i++) {
    if (inorder[i] == 0) {
      S.push_back(i);
    }
  }

  assert(S.size() > 0);

  while (!S.empty()) {
    int v = S.back();
    S.pop_back();
    topological_order.push_back(v);
    
    for (const int& tgt : G[v]) {
      inorder[tgt]--;
      if (inorder[tgt] == 0) {
        S.emplace_back(tgt);
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
  G.reserve(V);
  for (int i = 0; i < E; i++) {
    int s, t;
    std::cin >> s >> t;
    G[s].push_back(t);
  }

  std::vector<int> ans = topological_sort(G);

  for (int i = 0; i < V; i++) {
    std::cout << ans[i] << std::endl;
  }

  return 0;
}