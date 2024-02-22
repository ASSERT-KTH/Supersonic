#include <bits/stdc++.h>
using namespace std;
typedef vector<int> Edge;
typedef list<vector<int>> Adj_list;
vector<int> topological_sort(Adj_list &G) {
  const int V = G.size();
  vector<int> inorder(V, 0);
  for (const auto &edges : G)
    for (int e : edges)
      inorder[e]++;
  queue<int> Q;
  for (int i = 0; i < V; i++)
    if (inorder[i] == 0)
      Q.push(i);
  assert(!Q.empty());
  vector<int> topological_order;
  topological_order.reserve(V);
  while (!Q.empty()) {
    int v = Q.front();
    Q.pop();
    topological_order.push_back(v);
    for (int e : G[v]) {
      inorder[e]--;
      if (inorder[e] == 0)
        Q.push(e);
    }
  }
  for (int i = 0; i < V; i++)
    assert(inorder[i] == 0);
  return topological_order;
}
int main() {
  int V, E;
  scanf("%d %d", &V, &E);
  Adj_list G(V);
  for (int i = 0; i < E; i++) {
    int s, t;
    scanf("%d %d", &s, &t);
    G[s].push_back(t);
  }
  vector<int> ans = topological_sort(G);
  for (int i = 0; i < V; i++)
    printf("%d\n", ans[i]);
  return 0;
}