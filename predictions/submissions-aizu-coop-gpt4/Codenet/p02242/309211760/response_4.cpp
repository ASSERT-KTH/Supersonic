#include <iostream>
#include <queue>
#include <vector>
using namespace std;

static const int MAX = 100;
static const int INFTY = (1<<21);
static const int WHITE = 0;
static const int BLACK = 2;
int n, M[MAX][MAX];

void dijkstra() {
  int d[MAX];
  fill(d, d + n, INFTY);
  d[0] = 0;
  
  using P = pair<int, int>; // Pair of vertex number and shortest distance
  priority_queue<P, vector<P>, greater<P>> Q; // Min-Heap
  Q.push({0, 0}); // Add the pair of the start point and the distance
  
  while (!Q.empty()) {
    P p = Q.top();
    Q.pop();
    int u = p.second, dist = p.first;
    if (d[u] != dist) continue;
    for (int v = 0; v < n; v++) {
      if (M[u][v] != INFTY && d[v] > d[u] + M[u][v]) {
        d[v] = d[u] + M[u][v];
        Q.push({d[v], v});
      }
    }
  }
  
  for (int i = 0; i < n; i++) {
    cout << i << " " << (d[i] == INFTY ? -1 : d[i]) << endl;
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    fill(M[i], M[i] + n, INFTY);
  }
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