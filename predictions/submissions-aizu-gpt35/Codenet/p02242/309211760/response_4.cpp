#include <iostream>
#include <queue>
#include <vector>
using namespace std;
static const int MAX = 100;
static const int INFTY = (1 << 21);
vector<pair<int,int>> adj[MAX];
int n;
void dijkstra() {
  int d[MAX];
  for (int i = 0; i < n; i++) {
    d[i] = INFTY;
  }
  d[0] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push(make_pair(0, 0));
  while (!pq.empty()) {
    pair<int, int> f = pq.top();
    pq.pop();
    int u = f.second;
    if (d[u] < f.first)
      continue;
    for (int j = 0; j < adj[u].size(); j++) {
      int v = adj[u][j].first;
      if (d[v] > d[u] + adj[u][j].second) {
        d[v] = d[u] + adj[u][j].second;
        pq.push(make_pair(d[v], v));
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << i << " " << (d[i] == INFTY ? -1 : d[i]) << endl;
  }
}
int main() {
  int M[MAX][MAX];
  cin >> n;
  int k, c, u, v;
  for (int i = 0; i < n; i++) {
    cin >> u >> k;
    for (int j = 0; j < k; j++) {
      cin >> v >> c;
      adj[u].push_back(make_pair(v, c));
    }
  }
  dijkstra();
  return 0;
}