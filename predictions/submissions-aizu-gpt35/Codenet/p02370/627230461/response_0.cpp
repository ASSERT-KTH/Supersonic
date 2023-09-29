#include <iostream>
#include <vector>
#include <queue> // Added library for queue
using namespace std;
int main() {
  int V, E;
  cin >> V >> E;
  vector<vector<int>> edge(V + 1); // Reduced size of edge vector to V+1
  vector<int> state(V + 1, 0); // Reduced size of state vector to V+1
  for (int i = 0; i < E; i++) {
    int s, t;
    cin >> s >> t;
    edge[s].push_back(t);
    state[t]++;
  }
  queue<int> q; // Using queue to keep track of nodes with 0 state
  for (int i = 1; i <= V; i++) { // Starting loop from 1 as node 0 doesn't exist
    if (state[i] == 0)
      q.push(i);
  }
  vector<int> ans;
  while (!q.empty()) { // Using while loop instead of nested for loops
    int curr = q.front();
    q.pop();
    ans.push_back(curr);
    for (int i = 0; i < edge[curr].size(); i++) {
      int t = edge[curr][i];
      state[t]--;
      if (state[t] == 0)
        q.push(t);
    }
  }
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << endl;
  }
  return 0;
}