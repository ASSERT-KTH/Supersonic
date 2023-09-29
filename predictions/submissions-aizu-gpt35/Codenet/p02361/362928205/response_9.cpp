#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
const int INF = 1000000000;
struct edge {
  int to, cost;
};
vector<edge> G[100000];
int v, e, r;
typedef pair<int, int> P;
int main() {
  scanf("%d %d %d", &v, &e, &r);
  for (int i = 0; i < e; i++) {
    int s, t, d;
    scanf("%d %d %d", &s, &t, &d);
    G[s].push_back((edge){t, d});
  }
  int d[v];
  fill(d, d + v, INF);
  d[r] = 0;
  priority_queue<P, vector<P>, greater<P>> q;
  q.push(P(0, r));
  while (!q.empty()) {
    P p = q.top();
    q.pop();
    int nv = p.second;
    if (p.first > d[nv])
      continue;
    for (const auto& g : G[nv]) {
      if (d[nv] + g.cost < d[g.to]) {
        d[g.to] = d[nv] + g.cost;
        q.push(P(d[g.to], g.to));
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