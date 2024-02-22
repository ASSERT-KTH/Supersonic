#include <iostream>
using namespace std;
#define WHITE 0
#define GRAY 1
#define BLACK 2
int G[101][101];
int n;
int d[101], f[101], t;

void search_loop(int i) {
  int next;
  d[i] = ++t;
  for (next = 1; next <= n; next++) {
    if (G[i][next] > 0 && d[next] == 0) {
      search_loop(next);
    }
  }
  f[i] = ++t;
}

void dfs() {
  int i;
  t = 0;
  
  for (i = 1; i <= n; i++) {
    if (d[i] == 0)
      search_loop(i);
  }
  
  for (i = 1; i <= n; i++) {
    cout << i << " " << d[i] << " " << f[i] << endl;
  }
}

int main() {
  int i, j, k;
  cin >> n;
  
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      G[i][j] = 0;
    }
  }
  
  do {
    cin >> i;
    while (cin.get() != '\n') {
      cin >> k;
      G[i][k] = 1;
    }
  } while (i < n);
  
  dfs();
  
  return 0;
}