#include <iostream>
#include <vector>
using namespace std;
int main() {
  int V, E;
  cin >> V >> E;
  vector<vector<int>> edge(V);
  for (int i = 0; i < V; ++i) { //reserve space for inner vector
    edge[i].reserve(V-1);
  }
  vector<int> state(V, 0);
  for (int i = 0; i < E; ++i) {
    int s, t;
    cin >> s >> t;
    edge[s].push_back(t);
    state[t]++;
  }
  vector<int> ans;
  ans.reserve(V); //reserve space for ans vector
  int stateSize = state.size(); //store size in a variable
  for (int i = 0; i < stateSize; ++i) {
    if (state[i] == 0)
      ans.push_back(i);
  }
  for (int i = 0; i < ans.size(); ++i) {
    for (int j = 0; j < edge[ans[i]].size(); ++j) {
      int t = edge[ans[i]][j];
      state[t]--;
      if (state[t] == 0)
        ans.push_back(t);
    }
  }
  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i] << endl;
  }
  return 0;
}