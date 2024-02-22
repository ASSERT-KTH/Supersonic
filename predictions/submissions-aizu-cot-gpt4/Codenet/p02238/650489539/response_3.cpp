#include <iostream>
#include <vector>
using namespace std;
#define WHITE 0
#define GRAY 1
#define BLACK 2

void search_loop(int i, vector<vector<int>>& G, vector<int>& color, vector<int>& d, vector<int>& f, int& t) {
  int next;
  d[i] = ++t;
  color[i] = GRAY;
  for (next = 1; next <= G.size(); next++) {
    if (i == next && G[i][i] > 0)
      break;
    if (G[i][next] > 0 && color[next] == WHITE) {
      search_loop(next, G, color, d, f, t);
    }
  }
  f[i] = ++t;
  color[i] = BLACK;
  return;
}

void dfs(vector<vector<int>>& G, vector<int>& color, vector<int>& d, vector<int>& f, int& t) {
  for (int i = 1; i <= G.size(); i++)
    color[i] = WHITE;
  t = 0;
  for (int i = 1; i <= G.size(); i++) {
    if (color[i] == WHITE)
      search_loop(i, G, color, d, f, t);
  }
  for (int i = 1; i <= G.size(); i++) {
    cout << i << " " << d[i] << " " << f[i] << '\n';
  }
  return;
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> G(n+1, vector<int>(n+1, 0));
  vector<int> color(n+1), d(n+1), f(n+1);
  int i, j, k, e, t;
  
  do {
    cin >> i >> e;
    for (j = 1; j <= e; j++) {
      cin >> k;
      G[i][k] = 1;
    }
  } while (i < n);
  dfs(G, color, d, f, t);
  cin >> n;
  return 0;
}