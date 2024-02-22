#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<vector<int>> adjList(105);
bool visited[105];
int distance[105];

void bfs(int s) {
  for (int i = 0; i < 105; i++) {
    visited[i] = false;
    distance[i] = INT_MAX;
  }
  
  queue<int> q;
  visited[s] = true;
  distance[s] = 0;
  q.push(s);
  
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int neighbor : adjList[u]) {
      if (!visited[neighbor]) {
        distance[neighbor] = distance[u] + 1;
        visited[neighbor] = true;
        q.push(neighbor);
      }
    }
  }
}

int main() {
  int n;
  cin >> n;
  
  for (int i = 0; i < n; i++) {
    int u, v, k;
    cin >> u >> k;
    for (int j = 0; j < k; j++) {
      cin >> v;
      adjList[u - 1].push_back(v - 1);
    }
  }
  
  bfs(0);
  
  for (int i = 0; i < n; i++) {
    cout << i + 1 << ' ' << ((distance[i] == INT_MAX) ? -1 : distance[i]) << endl;
  }
  
  return 0;
}