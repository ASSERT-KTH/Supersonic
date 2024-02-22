#include <iostream>
#include <vector>
#include <stack>
#include <cassert>
using namespace std;

typedef vector<vector<int>> Adj_list;

vector<int> topological_sort(Adj_list G) {
  const int V = G.size();
  vector<int> inorder(V, 0);
  
  for (int i = 0; i < V; i++)
    for (const int &e : G[i])
      inorder[e]++;
      
  stack<int> S;
  for (int i = 0; i < V; i++)
    if (inorder[i] == 0)
      S.push(i);
  
  assert(!S.empty());
  
  vector<int> topological_order;
  topological_order.reserve(V);
  
  while (!S.empty()) {
    int v = S.top();
    S.pop();
    topological_order.push_back(v);
    
    for (const int &e : G[v]) {
      inorder[e]--;
      if (inorder[e] == 0)
        S.push(e);
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
  
  vector<int> ans = topological_sort(G);
  for (int i = 0; i < V; i++)
    cout << ans[i] << endl;
}