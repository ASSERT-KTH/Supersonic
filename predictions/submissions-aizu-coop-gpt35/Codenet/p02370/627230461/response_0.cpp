#include <iostream>
#include <vector>
using namespace std;
int main() {
  int V, E;
  cin >> V >> E;
  vector<pair<int, int>> edge(E);
  vector<int> state(V, 0);
  for (auto& e : edge) {
    cin >> e.first >> e.second;
    state[e.second]++;
  }
  vector<int> ans;
  ans.reserve(V); // Preallocate memory for the ans vector
  int numZeroState = 0; // Number of vertices with zero incoming edges
  for (int i = 0; i < V; i++) {
    if (state[i] == 0) {
      ans.push_back(i);
      numZeroState++;
    }
  }
  for (int i = 0; i < numZeroState; i++) {
    int v = ans[i];
    for (auto& e : edge) {
      if (e.first == v) {
        int t = e.second;
        state[t]--;
        if (state[t] == 0) {
          ans.push_back(t);
          numZeroState++;
        }
      }
    }
  }
  for (auto& a : ans) {
    cout << a << endl;
  }
  return 0;
}