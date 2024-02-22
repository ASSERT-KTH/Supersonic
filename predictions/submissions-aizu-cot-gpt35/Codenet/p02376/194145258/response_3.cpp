#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define max_n 10000

struct edge {
  int to, cap, rev;
};

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
  bool is_root() { return !pp || (pp->lp != this && pp->rp != this); }
  void rotr() {
    node_t *q = pp, *r = q->pp;
    q->push(), push();
    if ((q->lp = rp))
      rp->pp = q;
    rp = q;
    q->pp = this;
    if ((pp = r)) {
      if (r->lp == q)
        r->lp = this;
      if (r->rp == q)
        r->rp = this;
    }
    q->update();
  }
  void rotl() {
    node_t *q = pp, *r = q->pp;
    q->push(), push();
    if ((q->rp = lp))
      lp->pp = q;
    lp = q;
    q->pp = this;
    if ((pp = r)) {
      if (r->lp == q)
        r->lp = this;
      if (r->rp == q)
        r->rp = this;
    }
    q->update();
  }
  void splay() {
    while (!is_root()) {
      node_t *q = pp;
      if (q->is_root()) {
        if (q->lp == this)
          rotr();
        else
          rotl();
      } else {
        node_t *r = q->pp;
        if (r->lp == q) {
          if (q->lp == this) {
            q->rotr();
            rotr();
          } else {
            rotl();
            rotr();
          }
        } else {
          if (q->rp == this) {
            q->rotl();
            rotl();
          } else {
            rotr();
            rotl();
          }
        }
      }
    }
    push();
    update();
  }
};

node_t nodes[max_n];
vector<edge> g[max_n];
int dist[max_n];
int n, ptr[max_n];
vector<int> lists[max_n];

bool bfs(int s, int t) {
  std::fill(dist, dist + max_n, -1);
  dist[s] = 0;
  std::queue<int> que;
  que.push(s);
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    if (u == t)
      return true;
    for (const edge& e : g[u]) {
      if (dist[e.to] < 0 && e.cap > 0) {
        dist[e.to] = dist[u] + 1;
        que.push(e.to);
      }
    }
  }
  return false;
}

int max_flow(int S, int T) {
  int flow = 0;
  while (bfs(S, T)) {
    std::fill(ptr, ptr + max_n, 0);
    for (int i = 0; i < n; i++)
      nodes[i] = node_t(i, INF);
    node_t *s = &nodes[S], *t = &nodes[T];
    for (int i = 0; i < n; i++)
      lists[i].clear();
    while (true) {
      node_t *v = s->find_root();
      if (v == t) {
        v->expose();
        flow += v->mini;
        s->add(-v->mini);
        while (true) {
          v = s->find_root();
          if (v->val > 0)
            break;
          g[v->e->to][v->e->rev].cap += v->e->cap;
          v->e->cap = 0;
          v->cut();
        }
        continue;
      }
      if (ptr[v->id] < g[v->id].size()) {
        edge& e = g[v->id][ptr[v->id]++];
        if (dist[e.to] == dist[v->id] + 1 && e.cap > 0) {
          v->link(&nodes[e.to], e.cap, &e);
          lists[e.to].push_back(v->id);
        }
      } else {
        if (v == s) {
          for (int i = 0; i < n; i++) {
            for (int j = 0; j < lists[i].size(); j++)
              pour(i, j);
            lists[i].clear();
          }
          break;
        }
        for (int i = 0; i < lists[v->id].size(); i++) {
          if (!pour(v->id, i))
            nodes[lists[v->id][i]].cut();
        }
        lists[v->id].clear();
      }
    }
  }
  return flow;
}

int main(void) {
  std::ios::sync_with_stdio(false);
  int e, a, b, c;
  std::cin >> n >> e;
  for (int i = 0; i < e; i++) {
    std::cin >> a >> b >> c;
    add_edge(a, b, c);
  }
  std::cout << max_flow(0, n - 1) << "\n";
  return 0;
}