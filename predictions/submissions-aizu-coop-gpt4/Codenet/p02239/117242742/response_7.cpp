#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adjList; // adjacency list representation of the graph
int n, v[105], d[105];

void bfs(int s) {
  v[s] = true;
  d[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < adjList[u].size(); i++) { // loop over the neighbors of u
      int neighbor = adjList[u][i];
      if (!v[neighbor]) {
        d[neighbor] = d[u] + 1;
        v[neighbor] = true;
        q.push(neighbor);
      }
    }
  }
}

int main() {
  cin >> n;
  adjList.resize(n);
  for (int i = 0; i < n; i++)
    d[i] = -1;
  for (int i = 0; i < n; i++) {
    int u, v, k;
    cin >> u >> k;
    for (int j = 0; j < k; j++) {
      cin >> v;
      adjList[u - 1].push_back(v - 1); // add v to the neighbors of u
    }
  }
  bfs(0);
  for (int i = 0; i < n; i++)
    cout << i + 1 << ' ' << d[i] << endl;
  return 0;
}