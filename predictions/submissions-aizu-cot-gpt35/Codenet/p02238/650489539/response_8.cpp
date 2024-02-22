#include <iostream>
#include <cstring>
using namespace std;

enum Color { WHITE, GRAY, BLACK };

int G[101][101];
Color color[101];
int n;
int d[101], f[101], t;

void search_loop(int i) {
  int next;
  d[i] = ++t;
  color[i] = GRAY;
  cout << i << " " << d[i] << " ";
  for (next = 1; next <= n; next++) {
    if (i == next && G[i][i] > 0)
      break;
    if (G[i][next] > 0 && color[next] == WHITE) {
      search_loop(next);
    }
  }
  f[i] = ++t;
  color[i] = BLACK;
  cout << f[i] << endl;
}

void dfs() {
  int i;
  for (i = 1; i <= n; i++)
    color[i] = WHITE;
  t = 0;
  for (i = 1; i <= n; i++) {
    if (color[i] == WHITE)
      search_loop(i);
  }
}

int main() {
  int i, j, k;
  cin >> n;
  memset(G, 0, sizeof(G));
  do {
    cin >> i;
    for (j = 1; j <= i; j++) {
      cin >> k;
      G[i][k] = 1;
    }
  } while (i < n);
  dfs();
  return 0;
}