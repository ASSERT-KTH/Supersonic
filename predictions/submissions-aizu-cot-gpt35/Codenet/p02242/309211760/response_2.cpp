#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Vertex {
  int distance;
  int color;
};

void dijkstra(int n, const vector<vector<int>>& M) {
  static const int INFTY = (1 << 21);
  static const int WHITE = 0;
  static const int GRAY = 1;
  static const int BLACK = 2;

  vector<Vertex> vertices(n);
  for (int i = 0; i < n; i++) {
    vertices[i].distance = INFTY;
    vertices[i].color = WHITE;
  }

  vertices[0].distance = 0;
  vertices[0].color = GRAY;

  auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
  };
  priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
  pq.push({0, 0});

  while (!pq.empty()) {
    int u = pq.top().first;
    pq.pop();

    if (vertices[u].color == BLACK)
      continue;

    vertices[u].color = BLACK;

    for (int v = 0; v < n; v++) {
      if (vertices[v].color != BLACK && M[u][v] != INFTY) {
        if (vertices[v].distance > vertices[u].distance + M[u][v]) {
          vertices[v].distance = vertices[u].distance + M[u][v];
          vertices[v].color = GRAY;
          pq.push({v, vertices[v].distance});
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << i << " " << (vertices[i].distance == INFTY ? -1 : vertices[i].distance) << endl;
  }
}

int main() {
  int n;
  cin >> n;

  vector<vector<int>> M(n, vector<int>(n, (1 << 21)));

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