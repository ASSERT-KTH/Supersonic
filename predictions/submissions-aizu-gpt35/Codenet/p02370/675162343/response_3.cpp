#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int tgt_;
  Edge(int t) { tgt_ = t; }
};

typedef vector<vector<Edge>> Adj_list;

vector<int> topological_sort(const Adj_list& G) {
  const int V = G.size();
  vector<int> S, inorder(V, 0), topological_order(V);
  for (int i = 0; i < V; i++)
    for (const auto& e : G[i])
      inorder[e.tgt_]++;
  for (int i = 0; i < V; i++)
    if (inorder[i] == 0)
      S.push_back(i);
  assert(!S.empty());
  int idx = 0;
  while (!S.empty()) {
    int v = S.back();
    S.pop_back();
    topological_order[idx++] = v;
    for (int i = G[v].size() - 1; i >= 0; i--) {
      Edge e = G[v][i];
      inorder[e.tgt_]--;
      if (inorder[e.tgt_] == 0)
        S.push_back(e.tgt_);
    }
  }
  assert(idx == V);
  return topological_order;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int V, E;
  cin >> V >> E;
  Adj_list G(V);
  for (int i = 0; i < E; i++) {
    int s, t;
    cin >> s >> t;
    G[s].emplace_back(t);
  }
  auto ans = topological_sort(G);
  for (const auto& x : ans)
    cout << x << '\n';

  return 0;
}