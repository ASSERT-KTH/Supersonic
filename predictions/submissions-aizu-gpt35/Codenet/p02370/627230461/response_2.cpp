#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
  int V, E;
  cin >> V >> E;
  vector<vector<int>> edge(V);
  vector<int> state(V, 0);

  for (int i = 0; i < E; i++) {
    int s, t;
    cin >> s >> t;
    edge[s-1].push_back(t-1);
    state[t-1]++;
  }

  queue<int> q;
  for (int i = 0; i < state.size(); i++) {
    if (state[i] == 0) {
      q.push(i);
    }
  }

  vector<int> ans;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    ans.push_back(u);
    for (int j = 0; j < edge[u].size(); j++) {
      int v = edge[u][j];
      state[v]--;
      if (state[v] == 0) {
        q.push(v);
      }
    }
  }

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i]+1 << endl;
  }

  return 0;
}