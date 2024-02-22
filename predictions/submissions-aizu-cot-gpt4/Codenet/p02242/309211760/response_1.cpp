#include <iostream>
#include <vector>
using namespace std;
static const int INFTY = (1 << 21);

enum Color {
  WHITE,
  GRAY,
  BLACK
};

void dijkstra(const int n, const vector<vector<int>>& M) {
  int minv;
  vector<int> d(n, INFTY);
  vector<Color> color(n, WHITE);
  d[0] = 0;
  color[0] = GRAY;
  while (1) {
    minv = INFTY;
    int u = -1;
    for (int i = 0; i < n; i++) {
      if (minv > d[i] && color[i] != BLACK) {
        u = i;
        minv = d[i];
      }
    }
    if (u == -1)
      break;
    color[u] = BLACK;
    for (int v = 0; v < n; v++) {
      if (color[v] != BLACK && M[u][v] != INFTY) {
        if (d[v] > d[u] + M[u][v]) {
          d[v] = d[u] + M[u][v];
          color[v] = GRAY;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << i << " " << (d[i] == INFTY ? -1 : d[i]) << endl;
  }
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> M(n, vector<int>(n, INFTY));
  int k, c, u, v;
  for (int i = 0; i < n; i++) {
    cin >> u >> k;
    for (int j = 0; j < k; j++) {
      cin >> v >> c;
      M[u][v] = c;
    }
  }
  dijkstra(n, M);
  return 0;
}