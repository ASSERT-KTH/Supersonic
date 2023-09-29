#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> G;
vector<int> color;
vector<int> d, f;
int t;

void search_loop(int i) {
  d[i] = ++t;
  color[i] = 1;
  for (int next : G[i]) {
    if (color[next] == 0) {
      search_loop(next);
    }
  }
  f[i] = ++t;
  color[i] = 2;
}

void dfs() {
  color.assign(G.size(), 0);
  d.assign(G.size(), 0);
  f.assign(G.size(), 0);
  t = 0;
  for (int i = 1; i < G.size(); i++) {
    if (color[i] == 0) {
      search_loop(i);
    }
  }
  for (int i = 1; i < G.size(); i++) {
    cout << i << " " << d[i] << " " << f[i] << endl;
  }
}

int main() {
  int n, i, j, k, e;
  cin >> n;
  G.resize(n+1);
  do {
    cin >> i >> e;
    for (j = 1; j <= e; j++) {
      cin >> k;
      G[i].push_back(k);
    }
  } while (i < n);

  dfs();

  return 0;
}