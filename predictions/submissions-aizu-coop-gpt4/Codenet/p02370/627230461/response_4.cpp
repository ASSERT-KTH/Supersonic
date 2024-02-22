#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int V, E;
  cin >> V >> E;
  vector<vector<int>> edge(V);  // change to dynamic size
  vector<int> state(V, 0);
  queue<int> q;  // use queue instead of vector for ans
  for (int i = 0; i < E; i++) {
    int s, t;
    cin >> s >> t;
    edge[s].push_back(t);
    state[t]++;
  }
  for (int i = 0; i < V; i++) {  // integrate into initial loop
    if (state[i] == 0)
      q.push(i);
  }
  #pragma omp parallel for  // hint compiler to optimize loop
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    cout << v << endl;
    for (auto &t : edge[v]) {  // use range-based for loop
      state[t]--;
      if (state[t] == 0)
        q.push(t);
    }
  }
  return 0;
}