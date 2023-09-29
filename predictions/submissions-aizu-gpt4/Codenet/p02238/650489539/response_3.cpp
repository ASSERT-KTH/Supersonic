#include <iostream>
#include <vector>
using namespace std;

enum Color { WHITE, GRAY, BLACK };
vector<vector<int>> G;
vector<Color> color;
vector<int> d, f;
int n, t;

void search_loop(int i) {
  d[i] = ++t;
  color[i] = GRAY;
  for (int next = 0; next < n; next++) {
    if (G[i][next] && color[next] == WHITE)
      search_loop(next);
  }
  f[i] = ++t;
  color[i] = BLACK;
}

void dfs() {
  fill(color.begin(), color.end(), WHITE);
  t = 0;
  for (int i = 0; i < n; i++) {
    if (color[i] == WHITE)
      search_loop(i);
  }
  for (int i = 0; i < n; i++)
    cout << i+1 << " " << d[i] << " " << f[i] << endl;
}

int main() {
  cin >> n;
  G.resize(n, vector<int>(n));
  color.resize(n);
  d.resize(n);
  f.resize(n);

  for (int i = 0; i < n; i++) {
    int e;
    cin >> i >> e;
    for (int j = 0; j < e; j++) {
      int k;
      cin >> k;
      G[i][k-1] = 1;
    }
  }
  dfs();
  return 0;
}