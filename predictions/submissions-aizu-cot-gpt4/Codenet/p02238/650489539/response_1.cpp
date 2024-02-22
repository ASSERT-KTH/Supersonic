#include <iostream>
#include <vector>
using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2

void search_loop(int i, vector<vector<int>>& G, vector<int>& color, vector<int>& d, vector<int>& f, int& t, int n) {
  d[i] = ++t;
  color[i] = GRAY;
  for (int next = 0; next < n; next++) {
    if (i == next && G[i][i] > 0)
      break;
    if (G[i][next] > 0 && color[next] == WHITE) {
      search_loop(next, G, color, d, f, t, n);
    }
  }
  f[i] = ++t;
  color[i] = BLACK;
  return;
}

void dfs(int n, vector<vector<int>>& G) {
  vector<int> color(n, WHITE), d(n), f(n);
  int t = 0;
  for (int i = 0; i < n; i++) {
    if (color[i] == WHITE)
      search_loop(i, G, color, d, f, t, n);
  }
  for (int i = 0; i < n; i++) {
    printf("%d %d %d\n", i, d[i], f[i]);
  }
  return;
}

int main() {
  int n, e, k;
  scanf("%d", &n);
  vector<vector<int>> G(n, vector<int>(n, 0));
  do {
    scanf("%d %d", &n, &e);
    for (int j = 0; j < e; j++) {
      scanf("%d", &k);
      G[n][k] = 1;
    }
  } while (n < n);
  dfs(n, G);
  return 0;
}