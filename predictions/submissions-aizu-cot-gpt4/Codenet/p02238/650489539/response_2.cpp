#include <iostream>
using namespace std;
#define WHITE 0
#define GRAY 1
#define BLACK 2
int G[101][101];
int color[101];
int n;
int d[101], f[101], t;

void search_loop(int i) {
  int next = 1;
  d[i] = ++t;
  color[i] = GRAY;
  while(G[i][next] <= 0 || color[next] != WHITE) {
    if (next == n) return;
    next++;
  }
  search_loop(next);
  f[i] = ++t;
  color[i] = BLACK;
}

void dfs() {
  t = 0;
  for (int i = 1; i <= n; i++) {
    if (color[i] == WHITE)
      search_loop(i);
  }
  for (int i = 1; i <= n; i++) {
    cout << i << " " << d[i] << " " << f[i] << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int i, j, k, e;
  cin >> n;
  for (i = 1; i <= n; i++) {
    color[i] = WHITE;
  }
  for (i = 1; i <= n; i++) {
    cin >> i >> e;
    for (j = 1; j <= e; j++) {
      cin >> k;
      G[i][k] = 1;
    }
  }
  dfs();
  cin >> n;
  return 0;
}