#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static const int MAX = 100;
static const int INFTY = (1 << 21);
vector<pair<int, int>> graph[MAX];
int n;

void dijkstra() {
  priority_queue<pair<int, int>> PQ;
  int d[MAX];
  for (int i = 0; i < n; i++) {
    d[i] = INFTY;
  }
  d[0] = 0;
  PQ.push(make_pair(0, 0));

  while (!PQ.empty()) {
    pair<int, int> f = PQ.top(); PQ.pop();
    int u = f.second;
    if (d[u] < f.first*(-1)) continue;
    for (auto &j : graph[u]) {
      int v = j.first;
      int c = j.second;
      if (d[v] > d[u] + c) {
        d[v] = d[u] + c;
        PQ.push(make_pair(d[v] * (-1), v));
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << i << " " << (d[i] == INFTY ? -1 : d[i]) << endl;
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int u, v, c, k;
    cin >> u >> k;
    for (int j = 0; j < k; j++) {
      cin >> v >> c;
      graph[u].push_back(make_pair(v, c));
    }
  }

  dijkstra();
  return 0;
}