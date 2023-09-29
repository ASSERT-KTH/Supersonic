#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int tgt_;
  Edge(int t) : tgt_(t) {}
};
typedef vector<vector<Edge>> Adj_list;
vector<int> topological_sort(const Adj_list& G) {
  const int V = G.size();
  vector<int> inorder(V, 0);
  for (int i = 0; i < V; i++)
    for (const Edge& e : G[i])
      inorder[e.tgt_]++;
  queue<int> S;
  for (int i = 0; i < V; i++)
    if (inorder[i] == 0)
      S.push(i);
  assert(!S.empty());
  vector<int> topological_order;
  while (!S.empty()) {
    int v = S.front();
    S.pop();
    topological_order.push_back(v);
    for (const Edge& e : G[v]) {
      int tgt = e.tgt_;
      inorder[tgt]--;
      if (inorder[tgt] == 0)
        S.push(tgt);
    }
  }
  assert((int)topological_order.size() == V);
  return topological_order;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int V, E;
  cin >> V >> E;
  Adj_list G(V);
  for (int i = 0; i < E; i++) {
    int s, t;
    cin >> s >> t;
    G[s].emplace_back(t);
  }
  vector<int> ans = topological_sort(G);
  for (int i = 0; i < V; i++)
    cout << ans[i] << '\n';
}