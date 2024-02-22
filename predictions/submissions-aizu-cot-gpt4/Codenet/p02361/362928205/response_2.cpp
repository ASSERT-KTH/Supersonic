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
    G[s].emplace_back((edge){t, d});
  }
  int d[v];
  fill(d, d + v, INF);
  d[r] = 0;
  q.push(P(0, r));
  while (!q.empty()) {
    auto p = q.top();
    q.pop();
    int nv = p.second;
    if (p.first > d[nv])
      continue;
    int G_nv_size = G[nv].size();
    for (int i = 0; i < G_nv_size; i++) {
      int G_nv_i_to = G[nv][i].to;
      int G_nv_i_cost = G[nv][i].cost;
      if (d[nv] + G_nv_i_cost < d[G_nv_i_to]) {
        d[G_nv_i_to] = d[nv] + G_nv_i_cost;
        q.push(P(d[G_nv_i_to], G_nv_i_to));
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