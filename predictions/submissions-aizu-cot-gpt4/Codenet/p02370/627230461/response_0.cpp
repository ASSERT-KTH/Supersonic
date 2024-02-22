#include <iostream>
#include <vector>
using namespace std;
int main() {
  int V, E;
  cin >> V >> E;
  vector<vector<int>> edge(V);
  vector<int> state(V, 0);
  for (int i = 0; i < E; i++) {
    int s, t;
    cin >> s >> t;
    edge[s].push_back(t);
    state[t]++;
  }
  vector<int> ans;
  ans.reserve(V);
  for (int i = 0; i < V; i++) {
    if (state[i] == 0)
      ans.emplace_back(i);
  }
  for (int i = 0; i < ans.size(); i++) {
    for (auto &t : edge[ans[i]]) {
      state[t]--;
      if (state[t] == 0)
        ans.emplace_back(t);
    }
  }
  for (auto &i : ans) {
    cout << i << endl;
  }
  return 0;
}