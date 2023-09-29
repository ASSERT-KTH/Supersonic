#include <iostream>
#include <vector>
using namespace std;
enum Color {WHITE, GRAY, BLACK};
vector<vector<int>> G;
vector<int> color;
int n;
vector<int> d, f;
int t;
void search_loop(int i) {
  d[i] = ++t;
  color[i] = GRAY;
  for (int next = 0; next < n; ++next) {
    if (i != next && G[i][next] > 0 && color[next] == WHITE) {
      search_loop(next);
    }
  }
  f[i] = ++t;
  color[i] = BLACK;
}
void dfs() {
  for (int i = 0; i < n; ++i)
    color[i] = WHITE;
  t = 0;
  for (int i = 0; i < n; ++i) {
    if (color[i] == WHITE)
      search_loop(i);
  }
  for (int i = 0; i < n; ++i) {
    cout << i+1 << " " << d[i] << " " << f[i] << endl;
  }
}
int main() {
  int i, j, k, e;
  cin >> n;
  G.resize(n, vector<int>(n, 0));
  color.resize(n);
  d.resize(n);
  f.resize(n);
  for (i = 0; i < n; ++i) {
    cin >> j >> e;
    for (int m = 0; m < e; ++m) {
      cin >> k;
      G[j-1][k-1] = 1;
    }
  }
  dfs();
  return 0;
}