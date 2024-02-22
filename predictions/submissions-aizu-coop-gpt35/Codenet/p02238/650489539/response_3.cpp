#include <iostream>
#include <cstring>
using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2

int G[101][101];
int color[101];
int n;
int t;

void search_loop(int i) {
  int next;
  cout << i << " " << ++t << " ";
  color[i] = GRAY;
  for (next = 1; next <= n; next++) {
    if (G[i][next] > 0 && color[next] == WHITE) {
      search_loop(next);
    }
  }
  cout << ++t << endl;
  color[i] = BLACK;
}

void dfs() {
  memset(color, WHITE, sizeof(color));
  t = 0;
  for (int i = 1; i <= n; i++) {
    if (color[i] == WHITE) {
      search_loop(i);
    }
  }
}

int main() {
  cin >> n;
  memset(G, 0, sizeof(G));
  for (int i = 1; i <= n; i++) {
    int e;
    cin >> i >> e;
    for (int j = 1; j <= e; j++) {
      int k;
      cin >> k;
      G[i][k] = 1;
    }
  }
  dfs();
  return 0;
}