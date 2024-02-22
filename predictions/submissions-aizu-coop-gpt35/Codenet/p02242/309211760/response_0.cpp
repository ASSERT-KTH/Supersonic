#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static const int INFTY = (1 << 21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

void dijkstra() {
  int n;
  cin >> n;

  vector<vector<pair<int, int>>> adjList(n);
  for (int i = 0; i < n; i++) {
    int u, k;
    cin >> u >> k;
    for (int j = 0; j < k; j++) {
      int v, c;
      cin >> v >> c;
      adjList[u].push_back({v, c});
    }
  }

  vector<int> d(n, INFTY);
  vector<int> color(n, WHITE);
  d[0] = 0;

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, 0});

  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();

    if (color[u] == BLACK)
      continue;

    color[u] = BLACK;

    for (const auto& edge : adjList[u]) {
      int v = edge.first;
      int weight = edge.second;

      if (d[v] > d[u] + weight) {
        d[v] = d[u] + weight;
        pq.push({d[v], v});
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << i << " " << (d[i] == INFTY ? -1 : d[i]) << endl;
  }
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  dijkstra();

  return 0;
}