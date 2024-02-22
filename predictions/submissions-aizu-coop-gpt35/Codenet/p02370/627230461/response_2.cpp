#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

int main() {
  int V, E;
  cin >> V >> E;

  vector<unordered_set<int>> edge(V);
  vector<int> state(V, 0);
  unordered_set<int> zeroIncomingEdges;

  for (int i = 0; i < E; i++) {
    int s, t;
    cin >> s >> t;
    edge[s].insert(t);
    state[t]++;
  }

  for (int i = 0; i < V; i++) {
    if (state[i] == 0)
      zeroIncomingEdges.insert(i);
  }

  vector<int> ans;
  queue<int> q;

  for (int node : zeroIncomingEdges) {
    q.push(node);
  }

  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    ans.push_back(curr);

    for (int next : edge[curr]) {
      state[next]--;
      if (state[next] == 0)
        q.push(next);
    }
  }

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << endl;
  }

  return 0;
}