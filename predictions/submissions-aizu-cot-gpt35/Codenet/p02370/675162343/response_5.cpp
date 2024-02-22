#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using Adj_list = vector<vector<int>>;

void topological_sort(const Adj_list& G, vector<int>& topological_order) {
  const int V = G.size();
  vector<int> inorder(V, 0);
  for (int i = 0; i < V; i++)
    for (int tgt : G[i])
      inorder[tgt]++;
  queue<int> S;
  for (int i = 0; i < V; i++)
    if (inorder[i] == 0)
      S.push(i);
  while (!S.empty()) {
    int v = S.front();
    S.pop();
    topological_order.push_back(v);
    for (int tgt : G[v]) {
      inorder[tgt]--;
      if (inorder[tgt] == 0)
        S.push(tgt);
    }
  }
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
  topological_sort(G, ans);
  for (int i = 0; i < V; i++)
    cout << ans[i] << endl;
}