#include <iostream>
#include <vector>
#include <queue>
#include <list>
#define INF 1000000000
using namespace std;
typedef pair<int, int> P;

struct edge {
  int to, cost;
};

list<edge> G[100000];
int v, e, r;
priority_queue<P, vector<P>, greater<P>> q;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> v >> e >> r;
  for (int i = 0; i < e; i++) {
    int s, t, d;
    cin >> s >> t >> d;
    G[s].push_back({t, d}); // Directly add the edge to the list
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
    for (auto &e : G[nv]) {
      if (d[nv] + e.cost < d[e.to]) {
        d[e.to] = d[nv] + e.cost;
        q.push(P(d[e.to], e.to));
      }
    }
  }
  for (int i = 0; i < v; i++) {
    if (d[i] == INF)
      cout << "INF\n";
    else
      cout << d[i] << "\n";
  }
  return 0;
}