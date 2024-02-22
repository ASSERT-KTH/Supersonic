#include <iostream>
#include <cstring>
using namespace std;

const int MAX_N = 101;
int G[MAX_N][MAX_N];
int color[MAX_N];
int n;
int d[MAX_N], f[MAX_N], t;

void search_loop(int i) {
  int next;
  d[i] = ++t;
  color[i] = 1; // GRAY
  for (next = 1; next <= n; next++) {
    if (i == next && G[i][i] > 0)
      break;
    if (G[i][next] > 0 && color[next] == 0) { // WHITE
      search_loop(next);
    }
  }
  f[i] = ++t;
  color[i] = 2; // BLACK
}

void dfs() {
  memset(color, 0, sizeof(color));
  t = 0;
  for (int i = 1; i <= n; i++) {
    if (color[i] == 0) { // WHITE
      search_loop(i);
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << i << " " << d[i] << " " << f[i] << endl;
  }
}

int main() {
  cin >> n;
  memset(G, 0, sizeof(G));
  for (int i = 1; i <= n; i++) {
    int e;
    cin >> e;
    for (int j = 1; j <= e; j++) {
      int k;
      cin >> k;
      G[i][k] = 1;
    }
  }
  dfs();
  return 0;
}