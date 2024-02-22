#include <iostream>
#include <vector>
using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2

vector<vector<int>> G;
vector<int> color;
vector<int> d, f;
int t = 0;

void search_loop(int i) {
  d[i] = ++t;
  color[i] = GRAY;
  for (auto next: G[i]) {
    if (color[next] == WHITE) {
      search_loop(next);
    }
  }
  f[i] = ++t;
  color[i] = BLACK;
}

void dfs(int n) {
  for (int i = 0; i < n; i++) {
    if (color[i] == WHITE)
      search_loop(i);
  }
  for (int i = 0; i < n; i++) {
    cout << i+1 << " " << d[i] << " " << f[i] << endl;
  }
}

int main() {
  int n, e, k;
  cin >> n;

  G.resize(n);
  color.resize(n, WHITE);
  d.resize(n);
  f.resize(n);

  for (int i = 0; i < n; i++) {
    cin >> e;
    for (int j = 0; j < e; j++) {
      cin >> k;
      G[i].push_back(k-1);
    }
  }

  dfs(n);
  return 0;
}