#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
  int V, E;
  cin >> V >> E;
  vector<vector<int>> edge(V+1);
  vector<int> state(V+1, 0);
  for (int i = 0; i < E; i++) {
    int s, t;
    cin >> s >> t;
    edge[s].push_back(t);
    state[t]++;
  }
  queue<int> q;
  for (int i = 1; i <= V; i++) {
    if (state[i] == 0)
      q.push(i);
  }
  vector<int> ans;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    ans.push_back(u);
    for (int i = 0; i < edge[u].size(); i++) {
      int v = edge[u][i];
      state[v]--;
      if (state[v] == 0)
        q.push(v);
    }
  }
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << endl;
  }
  return 0;
}