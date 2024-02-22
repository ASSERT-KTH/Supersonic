#include <iostream>
#include <cstring>
using namespace std;

enum Color { WHITE, GRAY, BLACK };

int G[101][101];
Color color[101];
int n, t;

void search_loop(int i) {
  color[i] = GRAY;
  cout << i << " " << ++t << " ";
  
  for (int next = i + 1; next <= n; next++) {
    if (G[i][next] > 0 && color[next] == WHITE) {
      search_loop(next);
    }
  }
  
  cout << ++t << endl;
  color[i] = BLACK;
}

void dfs() {
  for (int i = 1; i <= n; i++)
    color[i] = WHITE;
  
  t = 0;
  
  for (int i = 1; i <= n; i++) {
    if (color[i] == WHITE)
      search_loop(i);
  }
}

int main() {
  cin >> n;
  
  memset(G, 0, sizeof(G));
  
  for (int i = 1; i <= n; i++) {
    int j, e;
    cin >> j >> e;
    
    for (int k = 1; k <= e; k++) {
      int node;
      cin >> node;
      G[j][node] = 1;
    }
  }
  
  dfs();
  
  return 0;
}