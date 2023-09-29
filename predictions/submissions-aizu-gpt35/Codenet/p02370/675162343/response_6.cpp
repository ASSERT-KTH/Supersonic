#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int tgt_;
  Edge(int t) { tgt_ = t; }
};
typedef vector<vector<Edge>> Adj_list;
vector<int> topological_sort(Adj_list G) {
  const int V = G.size();
  vector<int> S;
  vector<int> inorder(V, 0);
  for (int i = 0; i < V; i++)
    for (Edge &e : G[i])
      inorder[e.tgt_]++;
  for (int i = 0; i < V; i++)
    if (inorder[i] == 0)
      S.push_back(i);
  assert(S.size() > 0);
  vector<int> topological_order;
  while (!S.empty()) {
    int v = S.back();
    S.pop_back();
    topological_order.push_back(v);
    for (Edge &e : G[v]) {
      inorder[e.tgt_]--;
      if (inorder[e.tgt_] == 0)
        S.push_back(e.tgt_);
    }
  }
  for (int i = 0; i < V; i++)
    assert(inorder[i] == 0);
  return topological_order;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int V, E;
  cin >> V >> E;
  Adj_list G(V);
  for (int i = 0; i < E; i++) {
    int s, t;
    cin >> s >> t;
    G[s].push_back(Edge(t));
  }
  vector<int> ans = topological_sort(G);
  for (int i = 0; i < V; i++)
    cout << ans[i] << "\n";
  return 0;
}