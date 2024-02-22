#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int INF = 1000000000;
struct edge {
  int to, cost;
};
vector<edge> G[100000];
int v, e, r;
typedef pair<int, int> P;
priority_queue<P, vector<P>, greater<P>> q;
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> v >> e >> r;
  for (int i = 0; i < e; i++) {
    int s, t, d;
    cin >> s >> t >> d;
    G[s].reserve(e);
    G[s].push_back({t, d});
  }
  vector<int> d(v, INF);
  d[r] = 0;
  q.push(P(0, r));
  while (!q.empty()) {
    P const& p = q.top();
    int nv = p.second;
    if (p.first > d[nv]) {
      q.pop();
      continue;
    }
    for (edge const& e : G[nv]) {
      if (d[nv] + e.cost < d[e.to]) {
        d[e.to] = d[nv] + e.cost;
        q.push(P(d[e.to], e.to));
      }
    }
    q.pop();
  }
  for (int i = 0; i < v; i++) {
    if (d[i] == INF)
      cout << "INF\n";
    else
      cout << d[i] << "\n";
  }
  return 0;
}