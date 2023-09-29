#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
const int INF = 1000000000;
struct edge {
  int to, cost;
};
vector<edge> G[100000];
typedef pair<int, int> P;
priority_queue<P, vector<P>, greater<P>> q;
int main() {
  int v, e, r;
  scanf("%d %d %d", &v, &e, &r);
  vector<int> d(v, INF);
  d[r] = 0;
  for (int i = 0; i < e; i++) {
    int s, t, d;
    scanf("%d %d %d", &s, &t, &d);
    G[s].emplace_back(edge{t, d});
  }
  q.emplace(d[r], r);
  while (!q.empty()) {
    P p = q.top();
    q.pop();
    int nv = p.second;
    if (p.first > d[nv])
      continue;
    for (auto &e : G[nv]) {
      if (d[nv] + e.cost < d[e.to]) {
        d[e.to] = d[nv] + e.cost;
        q.emplace(d[e.to], e.to);
      }
    }
  }
  for (auto &dist : d) {
    if (dist == INF)
      printf("INF\n");
    else
      printf("%d\n", dist);
  }
  return 0;
}