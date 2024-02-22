#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2
vector<vector<int>> G(101);
vector<int> color(101, WHITE);
vector<int> d(101), f(101);
int n, t;

void dfs() {
  int i;
  stack<int> S;
  t = 0;
  for (i = 1; i <= n; i++) {
    if (color[i] == WHITE) {
      S.push(i);
      d[i] = ++t;
      color[i] = GRAY;
      while (!S.empty()) {
        int u = S.top();
        if (!G[u].empty()) {
          int v = G[u].back();
          G[u].pop_back();
          if (color[v] == WHITE) {
            S.push(v);
            d[v] = ++t;
            color[v] = GRAY;
          }
        } else {
          S.pop();
          f[u] = ++t;
          color[u] = BLACK;
        }
      }
    }
  }
  for (i = 1; i <= n; i++) {
    cout << i << " " << d[i] << " " << f[i] << endl;
  }
}

int main() {
  int i, j, k, e;
  cin >> n;
  G.resize(n + 1);
  do {
    cin >> i >> e;
    G[i].resize(e);
    for (j = 0; j < e; j++) {
      cin >> k;
      G[i][j] = k;
    }
  } while (i < n);
  dfs();
  return 0;
}