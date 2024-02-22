#include <iostream>
#include <vector>
using namespace std;
static const int MAX = 100;
static const int INFTY = (1 << 21);
static const int WHITE = 0;
static const int BLACK = 2;
int n, M[MAX][MAX] = {INFTY};
void dijkstra() {
  int minv;
  int d[MAX], color[MAX];
  for (int i = 0; i < n; i++) {
    d[i] = INFTY;
    color[i] = WHITE;
  }
  d[0] = 0;
  color[0] = BLACK;
  for(int _ = 0; _ < n; _++) {
    minv = INFTY;
    int u = 0;
    for (int i = 0; i < n; i++) {
      if (minv > d[i] && color[i] != BLACK) {
        u = i;
        minv = d[i];
      }
    }
    color[u] = BLACK;
    for (int v = 0; v < n; v++) {
      if (M[u][v] != INFTY && d[v] > d[u] + M[u][v]) {
        d[v] = d[u] + M[u][v];
        color[v] = BLACK;
      }
    }
  }
  vector<string> out(n);
  for (int i = 0; i < n; i++) {
    out[i] = to_string(i) + " " + (d[i] == INFTY ? "-1" : to_string(d[i]));
  }
  for (const auto &s : out) cout << s << "\n";
}
int main() {
  cin >> n;
  int k, c, u, v;
  for (int i = 0; i < n; i++) {
    cin >> u >> k;
    for (int j = 0; j < k; j++) {
      cin >> v >> c;
      M[u][v] = c;
    }
  }
  dijkstra();
  return 0;
}