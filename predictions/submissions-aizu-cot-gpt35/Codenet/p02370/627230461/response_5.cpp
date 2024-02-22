#include <iostream>
#include <vector>
using namespace std;
int main() {
  int V, E;
  cin >> V >> E;
  vector<vector<int>> edge(V);
  vector<bool> state(V, false);
  for (int i = 0; i < E; i++) {
    int s, t;
    cin >> s >> t;
    edge[s].push_back(t);
    state[t] = true;
  }
  vector<int> ans;
  for (int i = 0; i < V; i++) {
    if (!state[i]) {
      ans.push_back(i);
      state[i] = true;
      for (int j : edge[i]) {
        state[j]--;
        if (!state[j]) {
          ans.push_back(j);
          state[j] = true;
        }
      }
    }
  }
  for (int i : ans) {
    cout << i << '\n';
  }
  return 0;
}