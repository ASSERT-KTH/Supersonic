#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static const int INFTY = (1 << 21);
static const int MAX_NODES = 100;

struct Edge {
  int to;
  int cost;
};

void dijkstra() {
  int n;
  cin >> n;
  
  vector<vector<Edge>> graph(n);
  
  for (int i = 0; i < n; i++) {
    int u, k;
    cin >> u >> k;
    for (int j = 0; j < k; j++) {
      int v, c;
      cin >> v >> c;
      graph[u].push_back({v, c});
    }
  }
  
  vector<int> d(n, INFTY);
  vector<bool> visited(n, false);
  d[0] = 0;
  
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, 0});
  
  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();
    
    if (visited[u]) {
      continue;
    }
    
    visited[u] = true;
    
    for (const auto& edge : graph[u]) {
      int v = edge.to;
      int cost = edge.cost;
      
      if (d[v] > d[u] + cost) {
        d[v] = d[u] + cost;
        pq.push({d[v], v});
      }
    }
  }
  
  for (int i = 0; i < n; i++) {
    cout << i << " " << (d[i] == INFTY ? -1 : d[i]) << endl;
  }
}

int main() {
  dijkstra();
  return 0;
}