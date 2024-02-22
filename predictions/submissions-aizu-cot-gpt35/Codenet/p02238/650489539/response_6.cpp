#include <iostream>
#include <cstring>
using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2

void search_loop(int i, int n, int G[][101], int color[], int d[], int f[], int& t) {
  int next;
  d[i] = ++t;
  color[i] = GRAY;
  for (next = 1; next <= n; next++) {
    if (i == next && G[i][i] > 0)
      break;
    if (G[i][next] > 0 && color[next] == WHITE) {
      search_loop(next, n, G, color, d, f, t);
    }
  }
  f[i] = ++t;
  color[i] = BLACK;
}

void dfs(int n, int G[][101]) {
  int color[101];
  int d[101], f[101], t = 0;
  for (int i = 1; i <= n; i++)
    color[i] = WHITE;
  for (int i = 1; i <= n; i++) {
    if (color[i] == WHITE)
      search_loop(i, n, G, color, d, f, t);
  }
  for (int i = 1; i <= n; i++) {
    cout << i << " " << d[i] << " " << f[i] << endl;
  }
}

int main() {
  int n;
  cin >> n;
  int G[101][101];
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
  dfs(n, G);
  return 0;
}