#include <iostream>
using namespace std;
#define WHITE 0
#define GRAY 1
#define BLACK 2
const int MAXN = 101;
int G[MAXN][MAXN];
int color[MAXN];
int n, t;
int d[MAXN], f[MAXN];
void search_loop(int i) {
  d[i] = ++t;
  color[i] = GRAY;
  for (int next = 1; next <= n; next++) {
    if (i == next && G[i][i] > 0) break;
    if (G[i][next] > 0 && color[next] == WHITE) {
      search_loop(next);
    }
  }
  f[i] = ++t;
  color[i] = BLACK;
}
void dfs() {
  for (int i = 1; i <= n; i++) color[i] = WHITE;
  t = 0;
  for (int i = 1; i <= n; i++) {
    if (color[i] == WHITE) search_loop(i);
  }
  for (int i = 1; i <= n; i++) {
    cout << i << " " << d[i] << " " << f[i] << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int i, j, k, e;
  cin >> n;
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
  dfs();
  return 0;
}