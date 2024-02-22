#include <iostream>
#include <vector>
#include <queue>
#include <stack>

struct Edge {
  int tgt_;
  Edge(int t) { tgt_ = t; }
};

typedef std::vector<std::vector<Edge>> Adj_list;

std::vector<int> topological_sort(const Adj_list& G) {
  const int V = G.size();
  std::vector<int> topological_order;
  topological_order.reserve(V);

  std::queue<int> S;
  std::vector<int> inorder(V, 0);
  for (const auto& edges : G) {
    for (const Edge& e : edges) {
      inorder[e.tgt_]++;
    }
  }

  for (int i = 0; i < V; i++) {
    if (inorder[i] == 0) {
      S.push(i);
    }
  }

  while (!S.empty()) {
    int v = S.front();
    S.pop();
    topological_order.emplace_back(v);

    for (const Edge& e : G[v]) {
      inorder[e.tgt_]--;
      if (inorder[e.tgt_] == 0) {
        S.push(e.tgt_);
      }
    }
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