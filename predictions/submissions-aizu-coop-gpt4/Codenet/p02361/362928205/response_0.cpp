#include <algorithm>
#include <cstdio>
#include <queue>
#include <array>
using namespace std;

const int INF = 1000000000;

struct edge {
  int to, cost;
};

array<edge, 100000> G;
int v, e, r;

typedef pair<int, int> P;
priority_queue<P, vector<P>, greater<P>> q;

int main() {
  scanf("%d %d %d", &v, &e, &r);
  for (int i = 0; i < e; i++) {
    int s, t, d;
    scanf("%d %d %d", &s, &t, &d);
    G[s].push_back({t, d});
  }
  int d[v];
  fill(d, d + v, INF);
  d[r] = 0;
  q.push(P(0, r));
  while (!q.empty()) {
    P p = q.top();
    q.pop();
    int nv = p.second;
    for (auto it = G[nv].begin(); it != G[nv].end(); ++it) {
      if (d[nv] + it->cost < d[it->to]) {
        d[it->to] = d[nv] + it->cost;
        q.push(P(d[it->to], it->to));
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