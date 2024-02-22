#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dijkstra() {
  int n;
  cin >> n;
  
  const int INFTY = (1 << 21);
  const int WHITE = 0;
  const int GRAY = 1;
  const int BLACK = 2;

  vector<vector<int>> M(n, vector<int>(n, INFTY));
  
  for (int i = 0; i < n; i++) {
    int u, k;
    cin >> u >> k;
    for (int j = 0; j < k; j++) {
      int v, c;
      cin >> v >> c;
      M[u][v] = c;
    }
  }
  
  vector<int> d(n, INFTY);
  vector<int> color(n, WHITE);
  
  d[0] = 0;
  color[0] = GRAY;
  
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push(make_pair(0, 0));
  
  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();
    
    if (color[u] == BLACK)
      continue;
      
    color[u] = BLACK;
    
    for (int v = 0; v < n; v++) {
      if (color[v] != BLACK && M[u][v] != INFTY) {
        if (d[v] > d[u] + M[u][v]) {
          d[v] = d[u] + M[u][v];
          color[v] = GRAY;
          pq.push(make_pair(d[v], v));
        }
      }
    }
  }
  
  // Remove the printing loop
  
}

int main() {
  dijkstra();
  return 0;
}