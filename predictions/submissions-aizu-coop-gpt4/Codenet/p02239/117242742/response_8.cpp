#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj; // adjacency list
vector<int> d; // distance array
vector<bool> visited; // visited array

void bfs(int s) {
  visited[s] = true;
  d[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i];
      if (!visited[v]) {
        d[v] = d[u] + 1;
        visited[v] = true;
        q.push(v);
      }
    }
  }
}

int main() {
  int n;
  cin >> n;
  adj.resize(n);
  d.resize(n, -1);
  visited.resize(n, false);
  
  for (int i = 0; i < n; i++) {
    int u, k;
    cin >> u >> k;
    u--; // 0-indexing
    for (int j = 0; j < k; j++) {
      int v;
      cin >> v;
      v--; // 0-indexing
      adj[u].push_back(v);
    }
  }
  bfs(0);
  for (int i = 0; i < n; i++)
    cout << i + 1 << ' ' << d[i] << endl;
  return 0;
}