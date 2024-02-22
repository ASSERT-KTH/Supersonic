#include <iostream>
#include <vector>
using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2

vector<vector<int>> G;
vector<int> color;
vector<int> d, f;
int t;

void search_loop(int i) {
  d[i] = ++t;
  color[i] = GRAY;
  
  for (int next : G[i]) {
    if (color[next] == WHITE) {
      search_loop(next);
    }
  }
  
  f[i] = ++t;
  color[i] = BLACK;
}

void dfs(int n) {
  color.reserve(n + 1);
  d.reserve(n + 1);
  f.reserve(n + 1);
  
  for (int i = 1; i <= n; ++i)
    color[i] = WHITE;
    
  t = 0;
  
  for (int i = 1; i <= n; ++i) {
    if (color[i] == WHITE)
      search_loop(i);
  }
  
  for (int i = 1; i <= n; ++i) {
    cout << i << " " << d[i] << " " << f[i] << endl;
  }
}

int main() {
  int n, i, e, k;
  
  cin >> n;
  
  G.resize(n + 1);
  
  for (i = 1; i <= n; ++i) {
    cin >> i >> e;
    for (int j = 1; j <= e; ++j) {
      cin >> k;
      G[i].push_back(k);
    }
  }
  
  dfs(n);
  
  return 0;
}