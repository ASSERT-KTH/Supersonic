#include <cstdio>
#define MAX 100
#define INFTY (1 << 21)
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n, **M;

void dijkstra() {
  int minv;
  int d[MAX], color[MAX];
  for (int i = 0; i < n; i++) {
    d[i] = INFTY;
    color[i] = WHITE;
  }
  d[0] = 0;
  color[0] = GRAY;
  while (1) {
    minv = INFTY;
    int u = -1;
    for (int i = 0; i < n; i++) {
      if (minv > d[i] && color[i] != BLACK) {
        u = i;
        minv = d[i];
      }
    }
    if (u == -1)
      break;
    color[u] = BLACK;
    for (int v = 0; v < n; v++) {
      if (color[v] != BLACK && M[u][v] != INFTY) {
        if (d[v] > d[u] + M[u][v]) {
          d[v] = d[u] + M[u][v];
          color[v] = GRAY;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d %d\n", i, (d[i] == INFTY ? -1 : d[i]));
  }
}

int main() {
  scanf("%d", &n);
  M = new int*[n];
  for(int i = 0; i < n; i++) {
    M[i] = new int[n];
    for(int j = 0; j < n; j++) {
      M[i][j] = INFTY;
    }
  }
  for (int i = 0; i < n; i++) {
    int u, k;
    scanf("%d %d", &u, &k);
    for (int j = 0; j < k; j++) {
      int v, c;
      scanf("%d %d", &v, &c);
      M[u][v] = c;
    }
  }
  dijkstra();
  for(int i = 0; i < n; i++) {
    delete [] M[i];
  }
  delete [] M;
  return 0;
}