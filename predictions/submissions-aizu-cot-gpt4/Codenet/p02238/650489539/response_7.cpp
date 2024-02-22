#include <iostream>
#include <vector>
using namespace std;
#define WHITE 0
#define GRAY 1
#define BLACK 2

vector<vector<int>> G;
vector<int> color;
int n;
vector<int> d, f;
int t;

void search_loop(int i) {
  d[i] = ++t;
  color[i] = GRAY;
  for (int next = 1; next <= n; next++) {
    if (G[i][next] > 0 && color[next] == WHITE) {
      search_loop(next);
    }
  }
  f[i] = ++t;
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
  for (int i = 1; i <= n; i++) {
    cout << i << " " << d[i] << " " << f[i] << endl;
  }
}

int main() {
  int i, j, k, e;
  cin >> n;
  G = vector<vector<int>>(n+1, vector<int>(n+1, 0));
  color = vector<int>(n+1, WHITE);
  d = f = vector<int>(n+1, 0);

  do {
    cin >> i >> e;
    for (j = 1; j <= e; j++) {
      cin >> k;
      G[i][k] = 1;
    }
  } while (i < n);
  dfs();
  cin >> n;
  return 0;
}