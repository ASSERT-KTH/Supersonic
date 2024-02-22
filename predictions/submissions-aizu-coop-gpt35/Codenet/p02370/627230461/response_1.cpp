#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
  int V, E;
  cin >> V >> E;
  
  vector<vector<int>> edge(10001);
  vector<int> indegree(V, 0);

  for (int i = 0; i < E; i++) {
    int s, t;
    cin >> s >> t;
    edge[s].push_back(t);
    indegree[t]++;
  }

  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 0; i < V; i++) {
    if (indegree[i] == 0)
      pq.push(i);
  }

  vector<int> ans;
  while (!pq.empty()) {
    int u = pq.top();
    pq.pop();
    ans.push_back(u);

    for (auto v : edge[u]) {
      indegree[v]--;
      if (indegree[v] == 0)
        pq.push(v);
    }
  }

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << endl;
  }

  return 0;
}