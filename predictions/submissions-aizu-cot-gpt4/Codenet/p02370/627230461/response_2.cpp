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
    edge[s].push_back(t);
    state[t]++;
  }
  queue<int> ans;
  for (int i = 0; i < state.size(); i++) {
    if (state[i] == 0)
      ans.push(i);
  }
  while (!ans.empty()) {
    int s = ans.front();
    ans.pop();
    cout << s << endl;
    for (auto t : edge[s]) {
      state[t]--;
      if (state[t] == 0)
        ans.push(t);
    }
  }
  return 0;
}