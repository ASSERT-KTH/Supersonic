#include <bits/stdc++.h>
#define INF (1 << 30)
#define max_n 10000
using namespace std;
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
  