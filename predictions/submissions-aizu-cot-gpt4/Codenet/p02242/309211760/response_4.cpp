#include <iostream>
#include <vector>
#include <queue>
using namespace std;
static const int MAX = 100;
static const int INFTY = (1 << 21);
int n;
typedef pair<int, int> P; // pair of minimum distance and vertex number
vector<P> adj[MAX]; // adjacency list

void dijkstra() {
  priority_queue<P, vector<P>, greater<P>> PQ; // min heap
  int d[MAX];
  fill(d, d + n, INFTY);
  d[0] = 0;
  PQ.push(P(0, 0));
  
  while (!PQ.empty()) {
    P p = PQ.top(); PQ.pop();
    int u = p.second;
    if (d[u] < p.first) continue;
    for (auto &e : adj[u]) {
      if (d[e.second] > d[u] + e.first) {
        d[e.second] = d[u] + e.first;
        PQ.push(P(d[e.second], e.second));
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
      adj[u].push_back(P(c, v));
    }
  }
  dijkstra();
  return 0;
}