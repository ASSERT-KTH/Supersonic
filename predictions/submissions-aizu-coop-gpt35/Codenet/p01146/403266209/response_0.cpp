#include <bits/stdc++.h>
#define r(i, n) for (int i = 0; i < n; i++)
#define INF 1e9
using namespace std;

int main() {
  #pragma GCC optimize("O3")

  int n, m, l, k, a, h, t1, t2, t3;
  while (cin >> n >> m >> l >> k >> a >> h, n) {
    vector<vector<int>> b(n, vector<int>(n, INF));
    vector<vector<int>> x(n, vector<int>(n, INF));

    r(i, l) {
      int re;
      cin >> re;
      b[re][re] = 0;
      x[re][re] = 0;
    }

    r(i, k) {
      cin >> t1 >> t2 >> t3;
      b[t1][t2] = b[t2][t1] = t3;
      x[t1][t2] = x[t2][t1] = t3;
    }

    for (int o = 0; o < n; o++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          b[i][j] = min(b[i][j], b[i][o] + b[o][j]);
        }
      }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n, INF);
    dist[a] = 0;
    pq.push({0, a});
    while (!pq.empty()) {
      int u = pq.top().second;
      pq.pop();
      for (int v = 0; v < n; v++) {
        if (x[u][v] <= m && dist[u] + x[u][v] < dist[v]) {
          dist[v] = dist[u] + x[u][v];
          pq.push({dist[v], v});
        }
      }
    }

    if (dist[h] >= INF)
      cout << "Help!" << endl;
    else if (dist[h] < m)
      cout << dist[h] << endl;
    else
      cout << dist[h] * 2 - m << endl;
  }
}