#include <iostream>
#include <vector>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
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
  for (int i = 0; i < V; ++i) {
    if (state[i] == 0)
      ans.push_back(i);
  }
  for (int i = 0; i < ans.size(); ++i) {
    for (const auto &j : edge[ans[i]]) {
      state[j]--;
      if (state[j] == 0)
        ans.push_back(j);
    }
  }
  for (const auto &i : ans) {
    cout << i << '\n';
  }
  return 0;
}