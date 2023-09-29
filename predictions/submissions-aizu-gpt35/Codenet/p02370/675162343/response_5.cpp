#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int tgt_;
  Edge(int t) : tgt_(t) {}
};
typedef vector<vector<Edge>> Adj_list;
vector<int> topological_sort(const Adj_list& G) {
  const int V = G.size();
  vector<int> S;
  vector<int> inorder(V, 0);
  for (int i = 0; i < V; ++i)
    for (const Edge& e : G[i])
      ++inorder[e.tgt_];
  for (int i = 0; i < V; ++i)
    if (inorder[i] == 0)
      S.push_back(i);
  assert(!S.empty());
  vector<int> topological_order;
  topological_order.reserve(V);
  while (!S.empty()) {
    const int v = S.back();
    S.pop_back();
    topological_order.push_back(v);
    for (int i = G[v].size() - 1; i >= 0; --i) {
      const Edge& e = G[v][i];
      --inorder[e.tgt_];
      if (inorder[e.tgt_] == 0)
        S.push_back(e.tgt_);
    }
  }
  assert(topological_order.size() == V);
  return topological_order;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int V, E;
  cin >> V >> E;
  Adj_list G(V);
  for (int i = 0; i < E; ++i) {
    int s, t;
    cin >> s >> t;
    G[s].emplace_back(t);
  }
  const vector<int> ans = topological_sort(G);
  for (int i = 0; i < V; ++i)
    cout << ans[i] << '\n';
}