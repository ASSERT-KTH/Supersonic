#include <iostream>
#include <vector>
using namespace std;

int main() {
  #pragma GCC optimize("O3")
  
  int V, E;
  cin >> V >> E;
  
  vector<int> state(V, 0);
  vector<pair<int, int>> edges(E);
  
  for (int i = 0; i < E; i++) {
    int s, t;
    cin >> s >> t;
    edges[i] = {s, t};
    state[t] = 1;
  }
  
  vector<int> ans;
  for (int i = 0; i < V; i++) {
    if (state[i] == 0)
      ans.push_back(i);
  }
  
  for (int i = 0; i < ans.size(); i++) {
    for (const auto& edge : edges) {
      if (edge.first == ans[i]) {
        int t = edge.second;
        state[t]--;
        if (state[t] == 0)
          ans.push_back(t);
      }
    }
  }
  
  for (const auto& vertex : ans) {
    cout << vertex << endl;
  }
  
  return 0;
}