#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
  int V, E;
  cin >> V >> E;
  
  vector<vector<int>> edge;
  edge.resize(V);

  vector<int> state;
  state.resize(V);

  unordered_set<int> noIncomingEdges;
  
  for (int i = 0; i < E; i++) {
    int s, t;
    cin >> s >> t;
    edge[s].push_back(t);
    state[t]++;
  }
  
  for (int i = 0; i < V; i++) {
    if (state[i] == 0)
      noIncomingEdges.insert(i);
  }
  
  vector<int> ans;
  ans.reserve(V);
  
  while (!noIncomingEdges.empty()) {
    int currentVertex = *noIncomingEdges.begin();
    noIncomingEdges.erase(noIncomingEdges.begin());
    ans.push_back(currentVertex);
    
    for (int targetVertex : edge[currentVertex]) {
      state[targetVertex]--;
      if (state[targetVertex] == 0)
        noIncomingEdges.insert(targetVertex);
    }
  }
  
  for (int i = 0; i < V; i++) {
    cout << ans[i] << endl;
  }
  
  return 0;
}