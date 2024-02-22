#include <bits/stdc++.h>
using namespace std;
typedef vector<list<int>> Adj_list;
vector<int> topological_sort(Adj_list G) {
  const int V = G.size();
  deque<int> S;
  vector<int> inorder(V, 0);
  for (int i = 0; i < V; i++)
    for (const int &e : G[i])
      inorder[e]++;
  for (int i = 0; i < V; i++)
    if (inorder[i] == 0)
      S.push_front(i);
  assert(!S.empty());
  vector<int> topological_order;
  while (!S.empty()) {
    int v = S.front();
    S.pop_front();
    topological_order.push_back(v);
    for (auto it = G[v].rbegin(); it != G[v].rend(); ++it) {
      const int &e = *it;
      inorder[e]--;
      if (inorder[e] == 0)
        S.push_front(e);
    }
  }
  for (int i = 0; i < V; i++)
    assert(inorder[i] == 0);
  return topological_order;
}
int main() {
  int V, E;
  cin >> V >> E;
  Adj_list G(V);
  for (int i = 0; i < E; i++) {
    int s, t;
    cin >> s >> t;
    G[s].push_back(t);
  }
  vector<int> ans;
  ans.reserve(V);
  ans = topological_sort(G);
  for (int i = 0; i < V; i++)
    cout << ans[i] << endl;
}