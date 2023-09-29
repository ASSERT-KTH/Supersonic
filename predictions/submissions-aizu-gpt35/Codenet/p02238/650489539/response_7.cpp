#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> G;
vector<int> color, d, f;
int t;

void search_loop(int i) {
  d[i] = ++t;
  color[i] = 1;
  for (auto next : G[i]) {
    if (color[next] == 0) {
      search_loop(next);
    }
  }
  f[i] = ++t;
  color[i] = 2;
}

void dfs() {
  int n;
  cin >> n;
  G.resize(n + 1);
  color.resize(n + 1);
  d.resize(n + 1);
  f.resize(n + 1);
  int i, j, k, e;
  for (i = 1; i <= n; i++) {
    cin >> e;
    for (j = 1; j <= e; j++) {
      cin >> k;
      G[i].push_back(k);
    }
  }
  t = 0;
  for (i = 1; i <= n; i++) {
    if (color[i] == 0) {
      search_loop(i);
    }
  }
  for (i = 1; i <= n; i++) {
    cout << i << " " << d[i] << " " << f[i] << endl;
  }
}

int main() {
  dfs();
  return 0;
}