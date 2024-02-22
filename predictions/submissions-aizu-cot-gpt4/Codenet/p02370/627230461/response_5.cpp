#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

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

  queue<int> q;
  for (int i = 0; i < state.size(); i++) {
    if (state[i] == 0)
      q.push(i);
  }

  while (!q.empty()) {
    int v = q.front();
    q.pop();
    cout << v << endl;
    for (auto &t : edge[v]) {
      state[t]--;
      if (state[t] == 0)
        q.push(t);
    }
  }
  
  return 0;
}