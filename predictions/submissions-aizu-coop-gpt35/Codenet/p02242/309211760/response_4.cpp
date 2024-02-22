#include <iostream>
#include <queue>
using namespace std;

static const int MAX = 100;
static const int INFTY = (1 << 21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;
int n, M[MAX][MAX];

void dijkstra() {
  int d[MAX], color[MAX];
  for (int i = 0; i < n; i++) {
    d[i] = INFTY;
    color[i] = WHITE;
  }
  
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
      if (color[v] != BLACK && M[u][v] != -1) {
        if (d[v] > d[u] + M[u][v]) {
          d[v] = d[u] + M[u][v];
          color[v] = GRAY;
          pq.push(make_pair(d[v], v));
        }
      }
    }
  }
  
  for (int i = 0; i < n; i++) {
    cout << i << " " << (d[i] == INFTY ? -1 : d[i]) << endl;
  }
}

int main() {
  cin >> n;
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < MAX; j++) {
      M[i][j] = -1;
    }
  }
  
  int k, c, u, v;
  
  for (int i = 0; i < n; i++) {
    cin >> u >> k;
    for (int j = 0; j < k; j++) {
      cin >> v >> c;
      M[u][v] = c;
    }
  }
  
  dijkstra();
  
  return 0;
}