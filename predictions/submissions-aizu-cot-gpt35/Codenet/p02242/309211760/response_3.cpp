#include <iostream>
using namespace std;

void dijkstra() {
  int n;
  cin >> n;
  
  static const int MAX = 100;
  static const int INFTY = (1 << 21);
  static const int WHITE = 0;
  static const int GRAY = 1;
  static const int BLACK = 2;
  
  int M[MAX][MAX];
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < MAX; j++) {
      M[i][j] = INFTY;
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
  
  int minv;
  int d[MAX], color[MAX];
  
  for (int i = 0; i < n; i++) {
    d[i] = INFTY;
    color[i] = WHITE;
  }
  
  d[0] = 0;
  color[0] = GRAY;
  
  while (true) {
    minv = INFTY;
    int u = -1;
    for (int i = 0; i < n; i++) {
      if (color[i] != BLACK && d[i] < minv) {
        u = i;
        minv = d[i];
      }
    }
    
    if (u == -1)
      break;
    
    color[u] = BLACK;
    
    for (int v = 0; v < n; v++) {
      if (M[u][v] != INFTY && color[v] != BLACK) {
        if (d[v] > d[u] + M[u][v]) {
          d[v] = d[u] + M[u][v];
          color[v] = GRAY;
        }
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