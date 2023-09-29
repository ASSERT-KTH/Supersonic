#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

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
  queue<int> ans;
  for (int i = 0; i < V; i++) {
    if (state[i] == 0)
      ans.push(i);
  }
  while (!ans.empty()) {
    int u = ans.front();
    ans.pop();
    cout << u << "\n";
    for (auto &v : edge[u]) {
      state[v]--;
      if (state[v] == 0)
        ans.push(v);
    }
  }
  return 0;
}