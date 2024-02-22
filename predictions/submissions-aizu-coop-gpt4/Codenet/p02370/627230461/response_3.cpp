#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int V, E;
  cin >> V >> E;
  vector<vector<int>> edge(V);    // optimize memory allocation
  vector<int> state(V, 0);
  for (int i = 0; i < E; i++) {
    int s, t;
    cin >> s >> t;
    edge[s].push_back(t);
    state[t]++;
  }
  
  queue<int> ans;                 // use a queue instead of vector
  for (int i = 0; i < state.size(); i++) {
    if (state[i] == 0)
      ans.push(i);
  }
  while (!ans.empty()) {          // use a while loop to process the queue
    int v = ans.front();
    ans.pop();
    cout << v << endl;
    for (int t : edge[v]) {
      if (--state[t] == 0)        // decrement and check simultaneously
        ans.push(t);
    }
  }
  return 0;
}