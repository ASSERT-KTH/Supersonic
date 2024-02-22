#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> dist;

void bfs(int s) {
  visited[s] = true;
  dist[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i : adj[u]) {
      if (!visited[i]) {
        dist[i] = dist[u] + 1;
        visited[i] = true;
        q.push(i);
      }
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false); // optimize I/O operations
  int n, u, v, k;
  cin >> n;
  
  adj.resize(n);
  visited.resize(n, false);
  dist.resize(n, -1);

  for (int i = 0; i < n; i++) {
    cin >> u >> k;
    for (int j = 0; j < k; j++) {
      cin >> v;
      adj[u - 1].push_back(v - 1);
    }
  }
  bfs(0);
  for (int i = 0; i < n; i++)
    cout << i + 1 << ' ' << dist[i] << '\n';
  return 0;
}