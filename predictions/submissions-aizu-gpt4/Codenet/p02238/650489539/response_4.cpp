#include <iostream>
#include <vector>
using namespace std;
constexpr int WHITE = 0;
constexpr int GRAY = 1;
constexpr int BLACK = 2;
vector<vector<int>> G(101, vector<int>(101, 0));
vector<int> color(101);
int n;
vector<int> d(101), f(101);
int t;
void search_loop(int i) {
  d[i] = ++t;
  color[i] = GRAY;
  for (int next = 1; next <= n; ++next) {
    if (G[i][next] > 0 && color[next] == WHITE) {
      search_loop(next);
    }
  }
  f[i] = ++t;
  color[i] = BLACK;
}
void dfs() {
  fill(color.begin(), color.end(), WHITE);
  t = 0;
  for (int i = 1; i <= n; ++i) {
    if (color[i] == WHITE)
      search_loop(i);
  }
  for (int i = 1; i <= n; ++i) {
    cout << i << " " << d[i] << " " << f[i] << '\n';
  }
}
int main() {
  int i, j, k, e;
  cin >> n;
  while (cin >> i >> e) {
    for (j = 0; j < e; ++j) {
      cin >> k;
      G[i][k] = 1;
    }
  }
  dfs();
  return 0;
}