#include <iostream>
#include <vector>
using namespace std;
#define WHITE 0
#define GRAY 1
#define BLACK 2

vector<vector<int>> G(101);
int color[101];
int d[101], f[101], t;
int n;

inline void search_loop(int i) {
  d[i] = ++t;
  color[i] = GRAY;
  
  for (auto next : G[i]) {
    if (color[next] == WHITE) {
      search_loop(next);
    }
  }
  
  f[i] = ++t;
  color[i] = BLACK;
}

void dfs() {
  t = 0;
  
  for (int i = 1; i <= n; i++) {
    if (color[i] == WHITE)
      search_loop(i);
  }
  
  for (int i = 1; i <= n; i++) {
    cout << i << " " << d[i] << " " << f[i] << endl;
  }
}

int main() {
  int i, j, k, e;
  
  cin >> n;
  
  for (i = 1; i <= n; i++) {
    cin >> i >> e;
    color[i] = WHITE;
    
    for (j = 1; j <= e; j++) {
      cin >> k;
      G[i].push_back(k);
    }
  }

  dfs();
  
  return 0;
}