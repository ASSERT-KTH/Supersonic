#include <iostream>
#include <array>
using namespace std;

const int MAX_NODES = 10001;

int main() {
  int V, E;
  cin >> V >> E;
  array<vector<int>, MAX_NODES> edge;
  array<int, MAX_NODES> state{};
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
  for (const auto& node : ans) {
    for (const auto& target : edge[node]) {
      --state[target];
      if (state[target] == 0)
        ans.push_back(target);
    }
  }
  for (const auto& node : ans) {
    cout << node << endl;
  }
  return 0;
}