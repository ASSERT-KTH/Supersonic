#include <iostream>
#include <queue>
using namespace std;
static const int MAX = 100;
static const int INFTY = (1 << 21);
static const int WHITE = 0;
static const int BLACK = 2;
int n, M[MAX][MAX];
void dijkstra() {
  int minv;
  int d[MAX], color[MAX] = {WHITE};

  fill(d, d + n, INFTY);

  d[0] = 0;

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push(make_pair(0, 0));

  while (!pq.empty()) {
    pair<int, int> f = pq.top(); pq.pop();
    int u = f.second;
    color[u] = BLACK;

    if (d[u] < f.first) continue;

    for (int v = 0; v < n; v++) {
      if (color[v] != BLACK && M[u][v] != 0) {
        if (d[v] > d[u] + M[u][v]) {
          d[v] = d[u] + M[u][v];
          pq.push(make_pair(d[v], v));
        }
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
      M[u][v] = c;
    }
  }
  dijkstra();
  return 0;
}