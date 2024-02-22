#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

const int INF = 1000000000;

typedef std::pair<int, int> edge;
std::vector<edge> G[100000];
int v, e, r;
typedef std::pair<int, int> P;
std::priority_queue<P, std::vector<P>, std::greater<P>> q;

int main() {
  scanf("%d %d %d", &v, &e, &r);
  for (int i = 0; i < e; i++) {
    int s, t, d;
    scanf("%d %d %d", &s, &t, &d);
    G[s].push_back(std::make_pair(t, d));
  }
  int d[v];
  std::fill(d, d + v, INF);
  d[r] = 0;
  q.push(P(0, r));
  while (!q.empty()) {
    P p = q.top();
    q.pop();
    int nv = p.second;
    if (p.first > d[nv])
      continue;
    for (auto& e : G[nv]) {
      int nxt = e.first;
      int cost = e.second;
      if (d[nv] + cost < d[nxt]) {
        d[nxt] = d[nv] + cost;
        q.push(P(d[nxt], nxt));
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