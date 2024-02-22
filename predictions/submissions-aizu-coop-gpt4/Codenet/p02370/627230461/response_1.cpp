#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); // Faster I/O
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

  queue<int> q;
  for (int i = 0; i < V; i++) {
    if (state[i] == 0)
      q.push(i);
  }

  vector<int> ans;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    ans.push_back(v);

    for (const auto& t : edge[v]) {
      state[t]--;
      if (state[t] == 0)
        q.push(t);
    }
  }

  for (const auto& v : ans) {
    cout << v << "\n";
  }

  return 0;
}