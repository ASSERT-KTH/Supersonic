#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF INT_MAX
typedef pair<int, int> P;

int n;
vector<P> G[100];

void dijkstra() {
  priority_queue<P, vector<P>, greater<P>> Q;
  int d[100];
  fill(d, d + n, INF);
  d[0] = 0;
  Q.push(P(0, 0));

  while (!Q.empty()) {
    P f = Q.top(); Q.pop();
    int u = f.second;
    if (d[u] < f.first) continue;
    for (int j = 0; j < G[u].size(); j++) {
      int v = G[u][j].first;
      if (d[v] > d[u] + G[u][j].second) {
        d[v] = d[u] + G[u][j].second;
        Q.push(P(d[v], v));
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << i << " " << (d[i] == INF ? -1 : d[i]) << endl;
  }
}

int main() {
  cin >> n;
  int k, c, u, v;
  for (int i = 0; i < n; i++) {
    cin >> u >> k;
    for (int j = 0; j < k; j++) {
      cin >> v >> c;
      G[u].push_back(P(v, c));
    }
  }
  dijkstra();
  return 0;
}