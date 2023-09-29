#include <iostream>
#include <vector>
#include <queue>
using namespace std;
static const int MAX = 100;
static const int INFTY = (1 << 21);

void dijkstra(int n, vector<vector<pair<int, int>>> &adj) {
  vector<int> d(n, INFTY);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, 0});
  d[0] = 0;

  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();
    for (auto &pr : adj[u]) {
      int v = pr.first;
      int weight = pr.second;
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
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> adj(n);
  int k, c, u, v;
  for (int i = 0; i < n; i++) {
    cin >> u >> k;
    for (int j = 0; j < k; j++) {
      cin >> v >> c;
      adj[u].push_back({v, c});
    }
  }
  dijkstra(n, adj);
  return 0;
}