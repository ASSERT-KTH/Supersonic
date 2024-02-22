#include <iostream>
#include <deque>
using namespace std;

int main() {
  int V, E;
  cin >> V >> E;

  // Allocate edge vector according to actual number of vertices
  vector<vector<int>> edge(V);
  vector<int> state(V, 0);

  for (int i = 0; i < E; i++) {
    int s, t;
    cin >> s >> t;
    edge[s].push_back(t);
    state[t]++;
  }

  // Use deque instead of vector for ans
  deque<int> ans;
  ans.reserve(V); // Reserve space for V elements

  // Compute size before loop
  int stateSize = state.size();
  for (int i = 0; i < stateSize; i++) {
    if (state[i] == 0)
      ans.push_back(i);
  }

  // Compute size before loop
  int ansSize = ans.size();
  for (int i = 0; i < ansSize; i++) {
    // Compute size before inner loop
    int edgeSize = edge[ans[i]].size();
    for (int j = 0; j < edgeSize; j++) {
      int t = edge[ans[i]][j];
      state[t]--;
      if (state[t] == 0)
        ans.push_back(t);
    }
    ans.pop_front(); // Efficiently remove element from front
    ansSize = ans.size(); // Update ansSize for the outer loop
  }

  // Compute size before loop
  ansSize = ans.size();
  for (int i = 0; i < ansSize; i++) {
    cout << ans[i] << endl;
  }

  return 0;
}