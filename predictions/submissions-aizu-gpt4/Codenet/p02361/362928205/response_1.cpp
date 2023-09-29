#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
constexpr int INF = 1000000000;
struct edge {
  int to, cost;
};
vector<edge> G[100000];
int v, e, r;
typedef pair<int, int> P;
priority_queue<P, vector<P>, greater<P>> q;
int main() {
  scanf("%d %d %d", &v, &e, &r);
  int d[v];
  fill(d, d + v, INF);
  d[r] = 0;
  for (int i = 0; i < e; i++) {
    int s, t, cost;
    scanf("%d %d %d", &s, &t, &cost);
    G[s].emplace_back(edge{t, cost});
    if (s == r) {
      d[t] = min(d[t], cost);
      q.emplace(P(d[t], t));
    }
  }
  while (!q.empty()) {
    P p = q.top();
    q.pop();
    int nv = p.second;
    if (p.first > d[nv])
      continue;
    for (auto& e : G[nv]) {
      if (d[nv] + e.cost < d[e.to]) {
        d[e.to] = d[nv] + e.cost;
        q.emplace(P(d[e.to], e.to));
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