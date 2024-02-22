#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static const int MAX = 100;
static const int INFTY = (1 << 21);
static const int WHITE = 0;
static const int BLACK = 2;
int n;
vector<pair<int, int>> adj[MAX]; // adjacency list

void dijkstra() {
  int d[MAX];
  fill(d, d + n, INFTY);
  d[0] = 0;
  
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, 0});

  while (!pq.empty()) {
    int u = pq.top().second; pq.pop();
    if (d[u] == BLACK) continue; // if already processed, skip
    d[u] = BLACK;
    for (auto &p : adj[u]) {
      int v = p.first, w = p.second;
      if (d[v] > d[u] + w) {
        d[v] = d[u] + w;
        pq.push({d[v], v}); // push into the priority queue
      }
    }
  }
  
  for (int i = 0; i < n; i++) {
    cout << i << " " << (d[i] == INFTY ? -1 : d[i]) << endl;
  }
}

int main() {
  cin >> n;
  int k, c, u, v;
  for (int i = 0; i < n; i++) {
    cin >> u >> k;
    for (int j = 0; j < k; j++) {
      cin >> v >> c;
      adj[u].push_back({v, c}); // build the adjacency list
    }
  }
  dijkstra();
  return 0;
}