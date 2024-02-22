#include <iostream>
#include <vector>
using namespace std;
#define WHITE 0
#define GRAY 1
#define BLACK 2
vector<vector<int>> G;
int color[101];
int n;
int d[101], f[101], t;
void search_loop(int i) {
  int next;
  d[i] = ++t;
  color[i] = GRAY;
  for (next : G[i]) {
    if (color[next] == WHITE) {
      search_loop(next);
    }
  }
  f[i] = ++t;
  color[i] = BLACK;
  return;
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
  for (i = 1; i <= n; i++) {
    cout << i << " " << d[i] << " " << f[i] << "\n";
  }
  return;
}
int main() {
  int i, j, k, e;
  cin >> n;
  G.resize(n + 1);
  do {
    cin >> i >> e;
    for (j = 1; j <= e; j++) {
      cin >> k;
      G[i].push_back(k);
    }
  } while (i < n);
  dfs();
  cin >> n;
  return 0;
}