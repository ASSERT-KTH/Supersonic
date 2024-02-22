#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static const int INFTY = (1 << 21);

struct Edge {
  int v, c;
  Edge(int v, int c) : v(v), c(c) {}
};

void dijkstra() {
  int n;
  cin >> n;

  vector<vector<Edge>> graph(n);
  for (int i = 0; i < n; i++) {
    int u, k;
    cin >> u >> k;
    graph[u].reserve(k);
    for (int j = 0; j < k; j++) {
      int v, c;
      cin >> v >> c;
      graph[u].emplace_back(v, c);
    }
  }

  vector<int> d(n, INFTY);
  d[0] = 0;

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.emplace(0, 0);

  while (!pq.empty()) {
    int dist = pq.top().first;
    int u = pq.top().second;
    pq.pop();

    if (dist > d[u])
      continue;

    for (const Edge& edge : graph[u]) {
      int v = edge.v;
      int c = edge.c;
      if (d[v] > d[u] + c) {
        d[v] = d[u] + c;
        pq.emplace(d[v], v);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << i << " " << (d[i] == INFTY ? -1 : d[i]) << endl;
  }
}

int main() {
  dijkstra();
  return 0;
}