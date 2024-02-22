#include <iostream>
#include <cstring>
using namespace std;

const int INFTY = (1 << 21);
const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

void dijkstra(int n, int** M) {
  int minv;
  int* d = new int[n];
  int* color = new int[n];
  memset(d, INFTY, sizeof(int) * n);
  memset(color, WHITE, sizeof(int) * n);
  
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
      if (color[v] != BLACK && M[u][v] != INFTY && d[v] > d[u] + M[u][v]) {
        d[v] = d[u] + M[u][v];
        color[v] = GRAY;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << i << " " << (d[i] == INFTY ? -1 : d[i]) << endl;
  }

  delete[] d;
  delete[] color;
}

int main() {
  int n;
  cin >> n;

  int** M = new int*[n];
  for (int i = 0; i < n; i++) {
    M[i] = new int[n];
    memset(M[i], INFTY, sizeof(int) * n);
  }

  int k, c, u, v;
  for (int i = 0; i < n; i++) {
    cin >> u >> k;
    for (int j = 0; j < k; j++) {
      cin >> v >> c;
      M[u][v] = c;
    }
  }

  dijkstra(n, M);

  for (int i = 0; i < n; i++) {
    delete[] M[i];
  }
  delete[] M;
  
  return 0;
}