#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int MAX = 100;
const int INFTY = INT_MAX;

vector<pair<int, int>> adjList[MAX];
int dist[MAX];

void dijkstra() {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  fill(dist, dist + MAX, INFTY);
  dist[0] = 0;
  pq.push({0, 0});
  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();
    for (auto &edge : adjList[u]) {
      int v = edge.first, weight = edge.second;
      if (dist[v] > dist[u] + weight) {
        dist[v] = dist[u] + weight;
        pq.push({dist[v], v});
      }
    }
  }
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int u, k, v, c;
    cin >> u >> k;
    for (int j = 0; j < k; j++) {
      cin >> v >> c;
      adjList[u].push_back({v, c});
    }
  }
  dijkstra();
  for (int i = 0; i < n; i++) {
    cout << i << " " << (dist[i] == INFTY ? -1 : dist[i]) << endl;
  }
  return 0;
}