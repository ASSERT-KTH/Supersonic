#include <iostream>
#include <cstring>

enum Color {
  WHITE,
  GRAY,
  BLACK
};

void search_loop(int i, int n, int G[][101], Color color[]) {
  int next;
  static int t = 0;
  color[i] = GRAY;
  for (next = 1; next <= n; next++) {
    if (i == next && G[i][i] > 0)
      break;
    if (G[i][next] > 0 && color[next] == WHITE) {
      search_loop(next, n, G, color);
    }
  }
  color[i] = BLACK;
}

void dfs(int n, int G[][101], Color color[]) {
  int i;
  for (i = 1; i <= n; i++)
    color[i] = WHITE;
  int t = 0;
  for (i = 1; i <= n; i++) {
    if (color[i] == WHITE)
      search_loop(i, n, G, color);
  }
  for (i = 1; i <= n; i++) {
    std::cout << i << " " << d[i] << " " << f[i] << std::endl;
  }
}

int main() {
  int i, j, k, e;
  int n;
  std::cin >> n;
  int G[101][101];
  Color color[101];
  memset(G, 0, sizeof(G));
  memset(color, WHITE, sizeof(color));
  do {
    std::cin >> i >> e;
    for (j = 1; j <= e; j++) {
      std::cin >> k;
      G[i][k] = 1;
    }
  } while (e < n);
  dfs(n, G, color);
  return 0;
}