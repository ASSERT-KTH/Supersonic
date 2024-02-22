#include <iostream>
#include <vector>
using namespace std;
int main() {
  int V, E;
  cin >> V >> E;
  vector<vector<int>> edge(V);
  vector<int> state(V, 0);
  for (int i = 0; i < E; ++i) {
    int s, t;
    cin >> s >> t;
    edge[s].push_back(t);
    state[t]++;
  }
  vector<int> ans;
  ans.reserve(V);
  int stateSize = state.size();
  for (int i = 0; i < stateSize; ++i) {
    if (state[i] == 0)
      ans.emplace_back(i);
  }
  int ansSize = ans.size();
  for (int i = 0; i < ansSize; ++i) {
    int edgeSize = edge[ans[i]].size();
    for (int j = 0; j < edgeSize; ++j) {
      int t = edge[ans[i]][j];
      state[t]--;
      if (state[t] == 0)
        ans.emplace_back(t);
    }
    ansSize = ans.size();
  }
  for (const auto &a : ans) {
    cout << a << endl;
  }
  return 0;
}