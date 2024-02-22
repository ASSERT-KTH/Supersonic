#include <iostream>
#include <vector>
using namespace std;
int main() {
  int V, E;
  cin >> V >> E;
  vector<vector<int>> edge(V); // Initialize edge to size V
  vector<int> state(V, 0);
  for (int i = 0; i < E; i++) {
    int s, t;
    cin >> s >> t;
    edge[s].push_back(t);
    state[t]++;
  }
  vector<int> ans;
  for (int i = 0; i < V; i++) { // Use V instead of state.size()
    if (state[i] == 0)
      ans.push_back(i);
  }
  for (int i = 0; i < ans.size(); i++) {
    int ansSize = edge[ans[i]].size(); // Store size in variable
    for (int j = 0; j < ansSize; j++) { // Use variable instead of calling size() in each iteration
      int t = edge[ans[i]][j];
      state[t]--;
      if (state[t] == 0)
        ans.push_back(t);
    }
  }
  for (const auto &i : ans) { // Use range-based for loop for printing
    cout << i << endl;
  }
  return 0;
}