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
    int g_size = G[nv].size();
    for (int i = 0; i < g_size; i++) {
      int g_cost = G[nv][i].cost;
      int d_val = d[nv] + g_cost;
      int g_to = G[nv][i].to;
      if (d_val < d[g_to]) {
        d[g_to] = d_val;
        q.emplace(d_val, g_to);
      }
    }
  }
  for (int i = 0; i < v; i++) {
    int d_i = d[i];
    if (d_i == INF)
      printf("INF\n");
    else
      printf("%d\n", d_i);
  }
  return 0;
}