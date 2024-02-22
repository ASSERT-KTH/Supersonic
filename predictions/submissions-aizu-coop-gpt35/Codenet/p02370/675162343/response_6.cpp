#include <iostream>
#include <vector>
#include <deque>
#include <stack>

struct Edge {
  int tgt_;
  Edge(int t) { tgt_ = t; }
};

typedef std::vector<std::vector<Edge>> Adj_list;

std::vector<int> topological_sort(const Adj_list& G) {
  const int V = G.size();
  std::deque<int> topological_order;
  std::vector<int> inorder(V, 0);
  std::stack<int> S;

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
    int v = S.top();
    S.pop();
    topological_order.push_back(v);

    int size = G[v].size();
    for (int i = size - 1; i >= 0; i--) {
      Edge e = G[v][i];
      inorder[e.tgt_]--;
      if (inorder[e.tgt_] == 0) {
        S.push(e.tgt_);
      }
    }
  }

  return std::vector<int>(topological_order.begin(), topological_order.end());
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