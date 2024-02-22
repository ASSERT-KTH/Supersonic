#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

const int INF = 1000000000;

struct edge {
  int to, cost;
};

std::vector<edge> G[100000];
int v, e, r;

typedef std::pair<int, int> P;
std::priority_queue<P, std::vector<P>, std::greater<P>> q;

int main() {
  std::scanf("%d %d %d", &v, &e, &r);

  for (int i = 0; i < e; i++) {
    int s, t, d;
    std::scanf("%d %d %d", &s, &t, &d);
    G[s].emplace_back(t, d);
  }

  std::vector<int> d(v, INF);
  d[r] = 0;
  q.emplace(0, r);

  while (!q.empty()) {
    P p = q.top();
    q.pop();
    int nv = p.second;

    if (p.first > d[nv])
      continue;

    for (const auto& edge : G[nv]) {
      if (d[nv] + edge.cost < d[edge.to]) {
        d[edge.to] = d[nv] + edge.cost;
        q.emplace(d[edge.to], edge.to);
      }
    }
  }

  for (int i = 0; i < v; i++) {
    if (d[i] == INF)
      std::printf("INF\n");
    else
      std::printf("%d\n", d[i]);
  }

  return 0;
}