#include <bits/stdc++.h>
#define INF (1 << 29)
#define max_n 10000
using namespace std;
struct edge {
  int to, cap, rev;
};
struct node_t {
  node_t *pp, *lp, *rp;
  int id, val, minId, lazy;
  edge *e;
  node_t(int id, int v = 0) : id(id), val(v), minId(id), pp(NULL), lp(NULL), rp(NULL), lazy(0), e(NULL) {}
  inline void update() {
    val = min(val, lp ? lp->val : INF);
    val = min(val, rp ? rp->val : INF);
  }
  inline void apply(int v) { lazy += v, val += v; }
  inline void push() {
    if (lp) lp->apply(lazy);
    if (rp) rp->apply(lazy);
    lazy = 0;
  }
  bool is_root() { return !pp || (pp->lp != this && pp->rp != this); }
  void rotr() {
    node_t *q = pp, *r = q->pp;
    q->push(), push();
    if ((q->lp = rp)) rp->pp = q;
    rp = q, q->pp = this;
    replace_parent(r, q, this);
    q->update();
  }
  void rotl() {
    node_t *q = pp, *r = q->pp;
    q->push(), push();
    if ((q->rp = lp)) lp->pp = q;
    lp = q, q->pp = this;
    replace_parent(r, q, this);
    q->update();
  }
  void replace_parent(node_t* r, node_t* q, node_t* p) {
    if ((pp = r)) {
      if (r->lp == q) r->lp = p;
      if (r->rp == q) r->rp = p;
    }
  }
  void splay() {
    while (!is_root()) {
      node_t *q = pp;
      if (q->is_root()) {
        if (q->lp == this) rotr();
        else rotl();
      } else {
        node_t *r = q->pp;
        if (r->lp == q) {
          if (q->lp == this) q->rotr(), rotr();
          else rotl(), rotr();
        } else {
          if (q->rp == this) q->rotl(), rotl();
          else rotr(), rotl();
        }
      }
    }
    push();
    update();
  }
};
node_t *expose(node_t *x) {
  node_t *rp = NULL;
  for (node_t *p = x; p; p = p->pp) {
    p->splay();
    p->rp = rp;
    p->update();
    rp = p;
  }
  x->splay();
  return rp;
}
inline node_t *find_root(node_t *x) {
  expose(x);
  while (x->lp) x = x->lp;
  return x;
}
inline void cut(node_t *c) {
  expose(c);
  node_t *p = c->lp;
  c->lp = NULL;
  p->pp = NULL;
  c->val = INF;
}
inline void link(node_t *c, node_t *p, int val, edge *e) {
  expose(c), expose(p);
  c->pp = p, p->rp = c;
  c->val = val;
  c->update();
  c->e = e;
}
inline int minId(node_t *x) {
  expose(x);
  return x->minId;
}
inline void add(node_t *x, int val) {
  expose(x);
  x->apply(val);
}
vector<edge> g[max_n];
void add_edge(int from, int to, int cap) {
  g[from].push_back((edge){to, cap, g[to].size()});
  g[to].push_back((edge){from, 0, g[from].size() - 1});
}
int dist[max_n];
bool bfs(int s, int t) {
  fill(dist, dist + max_n, -1);
  dist[s] = 0;
  queue<int> que;
  que.push(s);
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    if (u == t) return true;
    for (edge e : g[u]) {
      if (dist[e.to] < 0 && e.cap > 0) {
        dist[e.to] = dist[u] + 1;
        que.push(e.to);
      }
    }
  }
  return false;
}
int n, ptr[max_n];
node_t *nodes[max_n];
bool pour(int u) {
  if (find_root(nodes[u]) == nodes[u]) return true;
  edge *e = nodes[u]->e;
  expose(nodes[u]);
  int df = e->cap - nodes[u]->val;
  e->cap -= df;
  g[e->to][e->rev].cap += df;
  return false;
}
int max_flow(int S, int T) {
  int flow = 0;
  while (bfs(S, T)) {
    fill(ptr, ptr + max_n, 0);
    fill(nodes, nodes + n, nullptr);
    node_t *s = new node_t(S, INF);
    node_t *t = new node_t(T, INF);
    nodes[S] = s;
    nodes[T] = t;
    while (true) {
      node_t *v = find_root(s);
      if (v == t) {
        expose(nodes[minId(s)]);
        flow += nodes[minId(s)]->val;
        add(s, -nodes[minId(s)]->val);
        while (true) {
          expose(nodes[minId(s)]);
          if (nodes[minId(s)]->val > 0) break;
          g[nodes[minId(s)]->e->to][nodes[minId(s)]->e->rev].cap += nodes[minId(s)]->e->cap;
          nodes[minId(s)]->e->cap = 0;
          cut(nodes[minId(s)]);
        }
        continue;
      }
      if (ptr[v->id] < g[v->id].size()) {
        edge &e = g[v->id][ptr[v->id]++];
        if (dist[e.to] == dist[v->id] + 1 && e.cap > 0) {
          if (!nodes[e.to]) nodes[e.to] = new node_t(e.to, INF);
          link(v, nodes[e.to], e.cap, &e);
        }
      } else {
        if (v == s) {
          for (int i = 0; i < n; i++) {
            if (nodes[i] && !pour(i)) cut(nodes[i]);
          }
          break;
        }
        if (!pour(v->id)) cut(v);
      }
    }
    for (int i = 0; i < n; i++) delete nodes[i];
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