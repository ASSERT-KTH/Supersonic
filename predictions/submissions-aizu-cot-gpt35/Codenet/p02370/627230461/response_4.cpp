#include <iostream>
#include <vector>
#include <deque>
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
  deque<int> ans;
  ans.reserve(V);
  for (int i = 0; i < V; i++) {
    if (state[i] == 0)
      ans.emplace_back(i);
  }
  while (!ans.empty()) {
    int node = ans.front();
    ans.pop_front();
    for (int next : edge[node]) {
      state[next]--;
      if (state[next] == 0)
        ans.emplace_back(next);
    }
  }
  for (int i = 0; i < V; i++) {
    cout << i << endl;
  }
  return 0;
}