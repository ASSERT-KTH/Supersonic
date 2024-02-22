#include <iostream>
#include <vector>
using namespace std;

int main() {
  int V, E;
  cin >> V >> E;

  vector<vector<int>> edge;
  edge.resize(V);

  vector<int> state(V, 0);

  for (int i = 0; i < E; i++) {
    int s, t;
    cin >> s >> t;
    edge[s].push_back(t);
    state[t]++;
  }

  vector<int> ans;

  for (int i = 0; i < V; i++) {
    if (state[i] == 0)
      ans.push_back(i);
  }

  for (int i = 0; i < ans.size(); i++) {
    int currSize = ans.size();
    for (int j = 0; j < edge[ans[i]].size(); j++) {
      int t = edge[ans[i]][j];
      state[t]--;
      if (state[t] == 0)
        ans.push_back(t);
    }
    if (currSize != ans.size()) {
      i = currSize - 1;
    }
  }

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << endl;
  }

  return 0;
}