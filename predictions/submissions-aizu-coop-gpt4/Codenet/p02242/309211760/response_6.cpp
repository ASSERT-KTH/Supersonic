#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static const int MAX = 100;
static const int INFTY = (1 << 21);

vector<pair<int, int>> adj[MAX]; // adjacency list

void dijkstra() {
  vector<int> d(MAX, INFTY); // distance array
  d[0] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min-priority queue
  pq.push({0, 0});

  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();

    for (auto &edge : adj[u]) {
      int v = edge.first, w = edge.second;
      if (d[v] > d[u] + w) {
        d[v] = d[u] + w;
        pq.push({d[v], v});
      }
    }
  }

  for (int i = 0; i < MAX; i++) {
    cout << i << " " << (d[i] == INFTY ? -1 : d[i]) << endl;
  }
}

int main() {
  int n;
  cin >> n;

  int k, c, u, v;
  for (int i = 0; i < n; i++) {
    cin >> u >> k;
    for (int j = 0; j < k; j++) {
      cin >> v >> c;
      adj[u].push_back({v, c});
    }
  }

  dijkstra();
  return 0;
}