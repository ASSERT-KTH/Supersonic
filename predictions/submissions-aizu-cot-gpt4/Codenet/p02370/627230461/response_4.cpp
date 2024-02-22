#include <iostream>
#include <vector>
using namespace std;

int main() {
  int V, E;
  cin >> V >> E;
  vector<vector<int>> edge(V);   // Optimized memory usage
  vector<int> state(V, 0);
  for (int i = 0; i < E; ++i) {  // Using prefix increment
    int s, t;
    cin >> s >> t;
    edge[s].push_back(t);
    state[t]++;
  }
  vector<int> ans;
  for (int i = 0; i < state.size(); ++i) {  // Using prefix increment
    if (state[i] == 0)
      ans.push_back(i);
  }
  for (size_t i = 0, len = ans.size(); i < len; ++i) {  // Calculating size before loop
    for (int &t : edge[ans[i]]) {  // Using range-based for loop
      state[t]--;
      if (state[t] == 0)
        ans.push_back(t);
    }
  }
  for (int &x : ans) {  // Using range-based for loop
    cout << x << endl;
  }
  return 0;
}