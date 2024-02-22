#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> adj;
vector<int> visited, distance;

void bfs(int s) {
  visited[s] = true;
  distance[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i : adj[u]) {
      if (!visited[i]) {
        distance[i] = distance[u] + 1;
        visited[i] = true;
        q.push(i);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  adj.resize(n);
  visited.resize(n, false);
  distance.resize(n, -1);
  
  for (int i = 0; i < n; i++) {
    int u, v, k;
    cin >> u >> k;
    u--;  // adjust to 0-based indexing
    for (int j = 0; j < k; j++) {
      cin >> v;
      v--;  // adjust to 0-based indexing
      adj[u].push_back(v);
    }
  }

  bfs(0);

  for (int i = 0; i < n; i++)
    cout << i + 1 << ' ' << distance[i] << '\n';

  return 0;
}