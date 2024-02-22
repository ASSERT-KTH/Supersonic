#include <iostream>
#include <vector>
using namespace std;

int main() {
  int V, E;
  cin >> V >> E;
  
  vector<vector<int>> edge(V);
  vector<int> state(V, 0);
  
  for (int i = 0; i < E; i++) {
    int s, t;
    cin >> s >> t;
    edge[s].push_back(t);
    state[t]++;
  }
  
  vector<int> ans;
  ans.reserve(V); // Reserve capacity for V elements
  
  for (int i = 0; i < V; i++) {
    if (state[i] == 0)
      ans.push_back(i);
  }
  
  for (int v : ans) {
    for (int t : edge[v]) {
      state[t]--;
      ans.push_back(t);
    }
  }
  
  for (int v : ans) {
    cout << v << endl;
  }
  
  return 0;
}