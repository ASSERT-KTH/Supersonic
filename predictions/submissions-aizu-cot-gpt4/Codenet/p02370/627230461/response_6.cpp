#include <iostream>
#include <vector>
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
  vector<int> ans;
  for (const auto& s : state) {
    if (s == 0)
      ans.push_back(&s - &state[0]);
  }
  for (const auto& a : ans) {
    for (const auto& e : edge[a]) {
      const int& t = e;
      state[t]--;
      if (state[t] == 0)
        ans.push_back(t);
    }
  }
  for (const auto& a : ans) {
    cout << a << endl;
  }
  return 0;
}