#include <iostream>
#include <cstring>
#include <queue>
#define INF (1 << 29)
#define max_n 10000
using namespace std;

struct edge {
  int to, cap, rev;
};

struct node_t {
  int id, val, mini, minId, lazy;
  edge *e;
  node_t* pp;
  node_t* lp;
  node_t* rp;
  node_t(int id, int v) : id(id), val(v) {
    pp = lp = rp = nullptr;
    lazy = 0;
    update();
  }
  void update() {
    mini = val, minId = id;
    if (lp && mini > lp->mini)
      mini = lp->mini, minId = lp->minId;
    if (rp && mini > rp->mini)
      mini = rp->mini, minId = rp->minId;
  }
  void apply(int v) { lazy += v, val += v, mini += v; }
  void push() {
    if (lp)
      lp->apply(lazy);
    if (rp)
      rp->apply(lazy);
    lazy = 0;
  }
  bool is_root() { return !pp || (pp->lp != this && pp->rp != this); }
};

node_t nodes[max_n];
int node_index = 0;

struct AVLTree {
  node_t* root;
  AVLTree() {
    root = nullptr;
  }

  node_t* left_rotate(node_t* x) {
    node_t* y = x->rp;
    x->rp = y->lp;
    if (y->lp)
      y->lp->pp = x;
    y->pp = x->pp;
    if (!x->pp)
      root = y;
    else if (x->pp->lp == x)
      x->pp->lp = y;
    else
      x->pp->rp = y;
    y->lp = x;
    x->pp = y;
    x->update();
    y->update();
    return y;
  }

  node_t* right_rotate(node_t* x) {
    node_t* y = x->lp;
    x->lp = y->rp;
    if (y->rp)
      y->rp->pp = x;
    y->pp = x->pp;
    if (!x->pp)
      root = y;
    else if (x->pp->lp == x)
      x->pp->lp = y;
    else
      x->pp->rp = y;
    y->rp = x;
    x->pp = y;
    x->update();
    y->update();
    return y;
  }

  node_t* splay(node_t* x) {
    while (!x->is_root()) {
      node_t* p = x->pp;
      if (p->is_root()) {
        if (p->lp == x)
          right_rotate(p);
        else
          left_rotate(p);
      } else {
        node_t* g = p->pp;
        if (g->lp == p) {
          if (p->lp == x) {
            right_rotate(g);
            right_rotate(p);
          } else {
            left_rotate(p);
            right_rotate(g);
          }
        } else {
          if (p->rp == x) {
            left_rotate(g);
            left_rotate(p);
          } else {
            right_rotate(p);
            left_rotate(g);
          }
        }
      }
    }
    x->push();
    x->update();
    return x;
  }

  node_t* expose(node_t* x) {
    node_t* rp = nullptr;
    for (node_t* p = x; p; p = p->pp) {
      p = splay(p);
      p->rp = rp;
      p->update();
      rp = p;
    }
    x = splay(x);
    return rp;
  }

  node_t* find_root(node_t* x) {
    expose(x);
    while (x->lp)
      x = x->lp;
    return x;
  }

  void cut(node_t* c) {
    expose(c);
    node_t* p = c->lp;
    c->lp = nullptr;
    p->pp = nullptr;
    c->val = INF;
  }

  void link(node_t* c, node_t* p, int val, edge* e) {
    expose(c), expose(p);
    c->pp = p, p->rp = c;
    c->val = val;
    c->update();
    c->e = e;
  }

  int minId(node_t* x) {
    expose(x);
    return x->minId;
  }

  void add(node_t* x, int val) {
    expose(x);
    x->apply(val);
  }
};

AVLTree avl_tree;

edge g[max_n][max_n];
int dist[max_n];
int n, ptr[max_n];
vector<int> lists[max_n];
int queue_buffer[max_n];
int queue_front = 0;
int queue_back = 0;

bool bfs(int s, int t) {
  memset(dist, -1, sizeof(dist));
  dist[s] = 0;
  queue_buffer[queue_back++] = s;
  while (queue_front < queue_back) {
    int u = queue_buffer[queue_front++];
    if (u == t)
      return true;
    for (int j = 0; j < n; j++) {
      edge e = g[u][j];
      if (dist[e.to] < 0 && e.cap > 0) {
        dist[e.to] = dist[u] + 1;
        queue_buffer[queue_back++] = e.to;
      }
    }
  }
  return false;
}

int max_flow(int S, int T) {
  int flow = 0;
  while (bfs(S, T)) {
    memset(ptr, 0, sizeof(ptr));
    for (int i = 0; i < n; i++) {
      avl_tree.root = nullptr;