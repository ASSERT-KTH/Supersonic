#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adjList; // adjacency list
vector<int> d; // distances
vector<bool> visited; // visited nodes

void bfs(int s) {
  visited[s] = true;
  d[s] = 0;
  queue<int> q;
  q.push(s);
  
  while(!q.empty()) {
    int u = q.front(); q.pop();
    for(int i = 0; i < adjList[u].size(); i++) {
      int v = adjList[u][i];
      if(!visited[v]) {
        d[v] = d[u] + 1;
        visited[v] = true;
        q.push(v);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); // Fast I/O
  
  int n;
  cin >> n;
  
  adjList.resize(n);
  d.resize(n, -1);
  visited.resize(n, false);
  
  for(int i = 0; i < n; i++) {
    int u, v, k;
    cin >> u >> k;
    u--; // 0-based indexing
    for(int j = 0; j < k; j++) {
      cin >> v;
      adjList[u].push_back(v - 1); // 0-based indexing
    }
  }
  
  bfs(0);
  
  for(int i = 0; i < n; i++)
    cout << i + 1 << ' ' << d[i] << '\n'; // Fast output
  
  return 0;
}