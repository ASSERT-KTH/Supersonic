#include <iostream>
#include <vector>
using namespace std;

int main() {
  int V, E;
  cin >> V >> E;
  
  vector<vector<int>> edge(V); // Allocate the vector to the exact size needed
  vector<int> state(V, 0);

  for (int i = 0; i < E; ++i) {
    int s, t;
    cin >> s >> t;
    edge[s].push_back(t);
    state[t]++;
  }
  
  vector<int> ans;
  ans.reserve(V); // Preallocate memory

  for (int i = 0, size = state.size(); i < size; ++i) {
    if (state[i] == 0)
      ans.emplace_back(i);
  }

  for (int i = 0, size = ans.size(); i < size; ++i) {
    for (int t : edge[ans[i]]) {
      if (--state[t] == 0)
        ans.emplace_back(t);
    }
  }

  for (int i : ans) {
    cout << i << endl;
  }

  return 0;
}