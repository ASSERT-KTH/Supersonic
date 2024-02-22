#include <iostream>
#include <vector>
#include <queue>

#pragma GCC optimize("O3")

using namespace std;

void bfs(int s, vector<vector<int>>& adjList, vector<int>& dist) {
  dist[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < adjList[u].size(); i++) {
      int v = adjList[u][i];
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
}

int main() {
  int numVertices;
  cin >> numVertices;

  // Initialize adjacency list and distance array
  vector<vector<int>> adjList(numVertices);
  vector<int> dist(numVertices, -1);

  for (int i = 0; i < numVertices; i++) {
    int u, numAdj;
    cin >> u >> numAdj;
    for (int j = 0; j < numAdj; j++) {
      int v;
      cin >> v;
      adjList[u - 1].push_back(v - 1);
    }
  }

  bfs(0, adjList, dist);

  for (int i = 0; i < numVertices; i++) {
    cout << i + 1 << ' ' << dist[i] << endl;
  }

  return 0;
}