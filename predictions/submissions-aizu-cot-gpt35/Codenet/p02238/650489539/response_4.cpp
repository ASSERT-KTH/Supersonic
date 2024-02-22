#include <iostream>
using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2

void search_loop(int i, int G[101][101], int& t, int color[101], int n) {
  int next;
  int& d_i = G[i][i];
  d_i = ++t;
  color[i] = GRAY;
  for (next = 1; next < n; next++) {
    if (G[i][next] > 0 && color[next] == WHITE) {
      search_loop(next, G, t, color, n);
    }
  }
  G[i][i] = ++t;
  color[i] = BLACK;
}

void dfs(int n) {
  int i, j, k, e;
  int G[101][101];
  int color[101];
  int t = 0;
  
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      G[i][j] = 0;
    }
  }
  
  do {
    cin >> i >> e;
    for (j = 1; j <= e; j++) {
      cin >> k;
      G[i][k] = 1;
    }
  } while (i < n);
  
  for (i = 1; i < n; i++) {
    color[i] = WHITE;
  }
  
  for (i = 1; i < n; i++) {
    if (color[i] == WHITE) {
      search_loop(i, G, t, color, n);
    }
  }
  
  for (i = 1; i < n; i++) {
    cout << i << " " << G[i][i] << " " << G[i][i] << endl;
  }
}

int main() {
  int n;
  cin >> n;
  dfs(n);
  return 0;
}