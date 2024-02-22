#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
constexpr int INF = 1000000000;

struct edge {
  int to, cost;
};

vector<vector<edge>> G(100000);
int v, e, r;
typedef pair<int, int> P;
priority_queue<P, vector<P>, greater<P>> q;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> v >> e >> r;
  G.reserve(v);
  for (int i = 0; i < e; i++) {
    int s, t, d;
    cin >> s >> t >> d;
    G[s].push_back({t,d});
  }
  vector<int> d(v, INF);
  d[r] = 0;
  q.push(P(0, r));
  while (!q.empty()) {
    P p = q.top();
    q.pop();
    int nv = p.second;
    if (p.first > d[nv])
      continue;
    for (auto& edge : G[nv]) {
      if (d[nv] + edge.cost < d[edge.to]) {
        d[edge.to] = d[nv] + edge.cost;
        q.push(P(d[edge.to], edge.to));
      }
    }
  }
  for (auto dist : d) {
    if (dist == INF)
      cout << "INF\n";
    else
      cout << dist << "\n";
  }
  return 0;
}