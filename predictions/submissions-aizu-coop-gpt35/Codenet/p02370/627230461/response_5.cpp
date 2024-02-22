#include <iostream>
#include <vector>
using namespace std;

int main() {
  int V, E;
  cin >> V >> E;
  
  vector<vector<int>> edge;
  vector<int> state(V, 0);
  
  // Step 1: Remove fixed size of the edge vector
  edge.resize(V);
  
  for (int i = 0; i < E; i++) {
    int s, t;
    cin >> s >> t;
    edge[s].push_back(t);
    
    // Step 2: Increment in-degree count for each vertex
    state[t]++;
  }
  
  vector<int> ans;
  
  // Step 3: Iterate over ans instead of state
  for (int i = 0; i < V; i++) {
    if (state[i] == 0)
      ans.push_back(i);
  }
  
  // Step 4: Use a while loop instead of a for loop
  int index = 0;
  while (index < ans.size()) {
    int current = ans[index];
    index++;
    
    // Step 5: Use a range-based for loop
    for (int t : edge[current]) {
      state[t]--;
      if (state[t] == 0)
        ans.push_back(t);
    }
  }
  
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << endl;
  }
  
  return 0;
}