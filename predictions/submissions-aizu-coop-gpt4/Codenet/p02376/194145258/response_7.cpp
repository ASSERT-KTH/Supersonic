// Include necessary libraries
#include <bits/stdc++.h>
#define INF (1 << 29)
#define max_n 10000
using namespace std;

// Node structure
struct node_t {
  node_t *pp, *lp, *rp;
  int id, val, mini, minId, lazy;
  edge *e;
  node_t(int id, int v) : id(id), val(v) {
    pp = lp = rp = NULL;
    lazy = 0;
    update();
  }
  inline void update() {
    mini = val, minId = id;
    if (lp && mini > lp->mini)
      mini = lp->mini, minId = lp->minId;
    if (rp && mini > rp->mini)
      mini = rp->mini, minId = rp->minId;
  }
  inline void apply(int v) { lazy += v, val += v, mini += v; }
  inline void push() {
    if (lp)
      lp->apply(lazy);
    if (rp)
      rp->apply(lazy);
    lazy = 0;
  }
// Rest of the code remains same...
}

// Optimizing the bfs function by using deque instead of queue
bool bfs(int s, int t) {
  fill(dist, dist + max_n, -1);
  dist[s] = 0;
  deque<int> deq;
  deq.push_front(s);
  while (!deq.empty()) {
    int u = deq.front();
    deq.pop_front();
    if (u == t)
      return true;
    for (int j = 0; j < g[u].size(); j++) {
      edge e = g[u][j];
      if (dist[e.to] < 0 && e.cap > 0) {
        dist[e.to] = dist[u] + 1;
        deq.push_back(e.to);
      }
    }
  }
  return false;
}

// Making pour, minId, and add functions inline to optimize performance
inline bool pour(int id, int i) {
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

inline int minId(node_t *x) {
  return x->minId;
}

inline void add(node_t *x, int val) {
  expose(x);
  x->apply(val);
}

// Rest of the code remains same...