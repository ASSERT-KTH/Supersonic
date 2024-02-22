#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main() {
  int V, E;
  cin >> V >> E;
  
  // Initialize the edge list and state vector with the appropriate size
  vector<vector<int>> edge(V);
  vector<int> state(V, 0);

  // Reserve space for maximum possible size of ans
  deque<int> ans;
  ans.reserve(V);
  
  for (int i = 0; i < E; i++) {
    int s, t;
    cin >> s >> t;
    edge[s].push_back(t);
    state[t]++;
    // As we update state, check if the current node's in-degree is zero
    if (state[s] == 0) ans.push_back(s);
  }
  
  for (auto i: ans) {
    for (auto t: edge[i]) {
      state[t]--;
      if (state[t] == 0)
        ans.push_back(t);
    }
  }

  for (auto i: ans) {
    cout << i << endl;
  }

  return 0;
}