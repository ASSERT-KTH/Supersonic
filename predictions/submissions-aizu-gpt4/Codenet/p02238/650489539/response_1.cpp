#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> G[101];
int color[101];
int n;
int d[101], f[101], t;

void search_loop(int i) {
  d[i] = ++t;
  color[i] = 1;
  for (int next: G[i]) {
    if (color[next] == 0) {
      search_loop(next);
    }
  }
  f[i] = ++t;
  color[i] = 2;
}

void dfs() {
  fill(color, color+n, 0);
  t = 0;
  for (int i = 0; i < n; i++) {
    if (color[i] == 0)
      search_loop(i);
  }
  for (int i = 0; i < n; i++) {
    cout << i+1 << " " << d[i]+1 << " " << f[i]+1 << endl;
  }
}

int main() {
  cin >> n;
  int e;
  for (int i = 0; i < n; i++) {
    cin >> e;
    G[i].resize(e);
    for (int j = 0; j < e; j++) {
      cin >> G[i][j];
      G[i][j]--;
    }
  }
  dfs();
  return 0;
}