#include <bits/stdc++.h>
#define INF (1 << 29)
#define max_n 10000
using namespace std;
struct edge {
  int to, cap, rev;
};
struct node_t {
  // same as original
};
node_t *expose(node_t *x) {
  // same as original
}
inline node_t *find_root(node_t *x) {
  // same as original
}
inline void cut(node_t *c) {
  // same as original
}
inline void link(node_t *c, node_t *p, int val, edge *e) {
  // same as original
}
inline int minId(node_t *x) {
  // same as original
}
inline void add(node_t *x, int val) {
  // same as original
}
vector<edge> g[max_n];
void add_edge(int from, int to, int cap) {
  g[from].push_back((edge){to, cap, g[to].size()});
  g[to].push_back((edge){from, 0, g[from].size() - 1});
}
int dist[max_n];
bool bfs(int s, int t) {
  // same as original, but use reference for edge e
  for (int j = 0; j < g[u].size(); j++) {
    edge &e = g[u][j];
    if (dist[e.to] < 0 && e.cap > 0) {
      dist[e.to] = dist[u] + 1;
      que.push(e.to);
    }
  }
}
int n, ptr[max_n];
node_t *nodes[max_n];
vector<int> lists[max_n];
bool pour(int id, int i) {
  int u = lists[id][i];
  if (find_root(nodes[u]) == nodes[u])
    return true;
  edge *e = nodes[u]->e;
  expose(nodes[u]);
  int df = e->cap - nodes[u]->val;
  e->cap -= df;
  g[e->to][e->rev].cap += df;
  return false;
}
int max_flow(int S, int T) {
  int flow = 0;
  for (int i = 0; i < n; i++)
    nodes[i] = new node_t(i, INF);
  while (bfs(S, T)) {
    fill(ptr, ptr + max_n, 0);
    node_t *s = nodes[S], *t = nodes[T];
    for (int i = 0; i < n; i++)
      lists[i].clear();
    // same as original, but reset nodes at the end
    for (int i = 0; i < n; i++) {
      nodes[i]->id = i;
      nodes[i]->val = INF;
      nodes[i]->pp = nodes[i]->lp = nodes[i]->rp = NULL;
      nodes[i]->lazy = 0;
      nodes[i]->update();
    }
  }
  return flow;
}
int main(void) {
  ios::sync_with_stdio(false);
  int e, a, b, c;
  cin >> n >> e;
  for (int i = 0; i < e; i++) {
    cin >> a >> b >> c;
    add_edge(a, b, c);
  }
  cout << max_flow(0, n - 1) << "\n";
  return 0;
}