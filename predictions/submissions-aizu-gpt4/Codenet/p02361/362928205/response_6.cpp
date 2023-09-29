#include <cstdio>
#include <queue>
#include <vector>
#define INF 1000000000
#define MAXN 100000
using namespace std;
struct edge {
  int to, cost;
};
vector<edge> G[MAXN];
int v, e, r;
typedef pair<int, int> P;
priority_queue<P, vector<P>, greater<P>> q;
int main() {
  scanf("%d %d %d", &v, &e, &r);
  int d[MAXN];
  for (int i = 0, s, t, d; i < e; i++) {
    scanf("%d %d %d", &s, &t, &d);
    G[s].emplace_back((edge){t, d});
  }
  fill(d, d + v, INF);
  d[r] = 0;
  q.emplace(d[r], r);
  while (!q.empty()) {
    P p = q.top(); q.pop();
    if (p.first > d[p.second]) continue;
    for (edge &e : G[p.second]) {
      if (d[p.second] + e.cost < d[e.to]) {
        d[e.to] = d[p.second] + e.cost;
        q.emplace(d[e.to], e.to);
      }
    }
  }
  for (int i = 0; i < v; i++) {
    if (d[i] == INF)
      printf("INF\n");
    else
      printf("%d\n", d[i]);
  }
  return 0;
}