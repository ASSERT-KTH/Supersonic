#include <iostream>
using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2

void search_loop(int i, int** G, int* color, int n, int& t) {
  int next;
  color[i] = GRAY;
  for (next = 1; next <= n; next++) {
    if (G[i][next] > 0 && color[next] == WHITE) {
      search_loop(next, G, color, n, t);
    }
  }
  color[i] = BLACK;
  return;
}

void dfs(int** G, int* color, int n) {
  int i;
  for (i = 1; i <= n; i++)
    color[i] = WHITE;
  
  int t = 0;
  for (i = 1; i <= n; i++) {
    if (color[i] == WHITE)
      search_loop(i, G, color, n, t);
  }
  
  for (i = 1; i <= n; i++) {
    cout << i << " " << t << " " << t << endl;
  }
  return;
}

int main() {
  int n;
  cin >> n;
  
  int** G = new int*[n+1];
  for (int i = 1; i <= n; i++) {
    G[i] = new int[n+1];
    for (int j = 1; j <= n; j++) {
      G[i][j] = 0;
    }
  }
  
  int i, j, k, e;
  for (i = 1; i <= n; i++) {
    cin >> i >> e;
    for (j = 1; j <= e; j++) {
      cin >> k;
      G[i][k] = 1;
    }
  }
  
  int* color = new int[n+1];
  dfs(G, color, n);
  
  for (int i = 1; i <= n; i++) {
    delete[] G[i];
  }
  delete[] G;
  delete[] color;
  
  return 0;
}