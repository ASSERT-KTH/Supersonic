#include <iostream>
#include <vector>
#include <cassert>

typedef std::vector<std::vector<int>> Adj_list;

std::vector<int> topological_sort(const Adj_list& G) {
  const int V = G.size();
  std::vector<int> topological_order;
  std::vector<bool> inorder(V, false);

  for (const auto& edges : G) {
    for (int tgt : edges) {
      inorder[tgt] = true;
    }
  }

  std::vector<int> stack;
  for (int i = 0; i < V; i++) {
    if (!inorder[i]) {
      stack.push_back(i);
    }
  }
  assert(!stack.empty());

  while (!stack.empty()) {
    int v = stack.back();
    stack.pop_back();
    topological_order.push_back(v);

    for (int tgt : G[v]) {
      inorder[tgt]--;
      if (inorder[tgt] == 0) {
        stack.push_back(tgt);
      }
    }
  }

  assert(topological_order.size() == V);
  return topological_order;
}

int main() {
  int V, E;
  std::cin >> V >> E;

  // Error checking for invalid inputs
  if (V <= 0 || E < 0) {
    std::cerr << "Invalid input" << std::endl;
    return 1;
  }

  Adj_list G(V);
  for (int i = 0; i < E; i++) {
    int s, t;
    std::cin >> s >> t;

    // Error checking for invalid inputs
    if (s < 0 || s >= V || t < 0 || t >= V) {
      std::cerr << "Invalid input" << std::endl;
      return 1;
    }

    G[s].push_back(t);
  }

  std::vector<int> ans = topological_sort(G);
  for (int i = 0; i < V; i++) {
    std::cout << ans[i] << std::endl;
  }

  return 0;
}