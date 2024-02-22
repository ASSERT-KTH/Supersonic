#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

int main() {
  int V, E;
  cin >> V >> E;

  vector<set<int>> edge(10001);
  vector<int> inDegree(V, 0);

  for (int i = 0; i < E; i++) {
    int s, t;
    cin >> s >> t;
    edge[s].insert(t);
    inDegree[t]++;
  }

  queue<int> q;
  for (int i = 0; i < V; i++) {
    if (inDegree[i] == 0)
      q.push(i);
  }

  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    cout << curr << endl;

    for (int next : edge[curr]) {
      inDegree[next]--;
      if (inDegree[next] == 0)
        q.push(next);
    }
  }

  return 0;
}