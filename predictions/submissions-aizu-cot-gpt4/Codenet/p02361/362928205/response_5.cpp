#include <algorithm>
#include <cstdio>
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
  scanf("%d %d %d", &v, &e, &r);
  for (int i = 0; i < e; i++) {
    int s, t, d;
    scanf("%d %d %d", &s, &t, &d);
    edge tmp;
    tmp.to = t;
    tmp.cost = d;
    G[s].push_back(tmp);
  }
  int d[v];
  fill(d, d + v, INF);
  d[r] = 0;
  q.push(P(0, r));
  while (!q.empty()) {
    P p = q.top();
    q.pop();
    int nv = p.second;
    if (p.first > d[nv])
      continue;
    for (int i = 0; i < G[nv].size(); i++) {
      int edge_cost = G[nv][i].cost;
      int to_vertex = G[nv][i].to;
      if (d[nv] + edge_cost < d[to_vertex]) {
        d[to_vertex] = d[nv] + edge_cost;
        q.push(P(d[to_vertex], to_vertex));
      }
    }
  }
  for (int i = 0; i < v; i++) {
    if (d[i] == INF)
      puts("INF");
    else
      printf("%d\n", d[i]);
  }
  return 0;
}