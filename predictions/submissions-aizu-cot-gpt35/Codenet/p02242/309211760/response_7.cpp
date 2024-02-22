#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void dijkstra() {
  int n;
  cin >> n;

  vector<vector<int>> M(n, vector<int>(n, INT_MAX));
  
  int k, c, u, v;
  for (int i = 0; i < n; i++) {
    cin >> u >> k;
    for (int j = 0; j < k; j++) {
      cin >> v >> c;
      M[u][v] = c;
    }
  }

  vector<int> d(n, INT_MAX);
  vector<int> color(n, 0);
  d[0] = 0;
  color[0] = 1;

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, 0});

  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();

    if (color[u] == 2)
      continue;

    color[u] = 2;

    for (int v = 0; v < n; v++) {
      if (color[v] == 0 && M[u][v] != INT_MAX) {
        if (d[v] > d[u] + M[u][v]) {
          d[v] = d[u] + M[u][v];
          color[v] = 1;
          pq.push({d[v], v});
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << i << " " << (d[i] == INT_MAX ? -1 : d[i]) << endl;
  }
}

int main() {
  dijkstra();
  return 0;
}