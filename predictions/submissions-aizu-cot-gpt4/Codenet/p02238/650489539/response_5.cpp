#include <iostream>
#include <vector>
using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2

vector<vector<int>> G;
vector<int> color, d, f;
int n, t;

void search_loop(int i) {
  int next;
  d[i] = ++t;
  color[i] = GRAY;
  for (next = 1; next <= n; next++) {
    if (G[i][next] > 0 && color[next] == WHITE) {
      search_loop(next);
    }
  }
  f[i] = ++t;
  color[i] = BLACK;
  return;
}

void dfs() {
  fill(color.begin(), color.end(), WHITE);
  t = 0;
  for (int i = 1; i <= n; i++) {
    if (color[i] == WHITE)
      search_loop(i);
  }
  for (int i = 1; i <= n; i++) {
    cout << i << " " << d[i] << " " << f[i] << endl;
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false); 
  int i, j, k, e;
  cin >> n;
  G.resize(n+1, vector<int>(n+1, 0));
  color.resize(n+1);
  d.resize(n+1);
  f.resize(n+1);
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