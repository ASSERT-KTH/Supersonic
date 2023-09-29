#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
const int INF = 1000000000;
struct edge {
  int to, cost;
  edge(int t, int c) : to(t), cost(c) {}
};
vector<edge> G[100000];
int v, e, r;
typedef pair<int, int> P;
priority_queue<P, vector<P>, greater<P>> q;
int main() {
  scanf("%d %d %d", &v, &e, &r);
  for (int i = 0; i < e; i++) {
    int s, t, d;
    scanf("%d %d %d", &s, &t, &d);
    G[s].emplace_back(t, d);
  }
  int d[v];
  fill(d, d + v, INF);
  d[r] = 0;
  q.push({0, r});
  while (!q.empty()) {
    P p = q.top();
    q.pop();
    int nv = p.second;
    if (p.first > d[nv])
      continue;
    for (auto& e : G[nv]) {
      if (d[nv] + e.cost < d[e.to]) {
        d[e.to] = d[nv] + e.cost;
        q.push({d[e.to], e.to});
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