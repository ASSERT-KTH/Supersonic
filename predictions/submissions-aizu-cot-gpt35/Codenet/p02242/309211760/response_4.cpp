#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static const int INFTY = (1 << 21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

void dijkstra(int n, vector<vector<int>>& M) {
  vector<int> d(n, INFTY);
  vector<int> color(n, WHITE);
  
  d[0] = 0;
  color[0] = GRAY;

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, 0});

  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();

    color[u] = BLACK;

    for (int v = 0; v < n; v++) {
      if (color[v] != BLACK && M[u][v] != INFTY) {
        if (d[v] > d[u] + M[u][v]) {
          d[v] = d[u] + M[u][v];
          color[v] = GRAY;
          pq.push({d[v], v});
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

  for (int i = 0; i < n; i++) {
    int u, k;
    cin >> u >> k;
    for (int j = 0; j < k; j++) {
      int v, c;
      cin >> v >> c;
      M[u][v] = c;
    }
  }

  dijkstra(n, M);

  return 0;
}