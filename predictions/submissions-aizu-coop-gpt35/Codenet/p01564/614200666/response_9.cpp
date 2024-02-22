#define NDEBUG
#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
struct LCNode {
  typedef LCNode *NP;
  typedef int D;
  static const int INF = 1LL << 25;
  static const int DF = 1LL << 25;
  static LCNode last_d;
  static NP last;
  NP p, l, r;
  int sz;
  int v, sm, lz;
  int lsm, rsm, ma, mv;
  bool rev;
  LCNode(D v)
      : p(NULL), l(last), r(last), sz(1), v(v), sm(v), lz(DF), rev(false),
        lsm(max(v, 0)), rsm(max(v, 0)), ma(max(v, 0)), mv(v) {}
  LCNode() : l(NULL), r(NULL), sz(0), v(-INF), mv(-INF) {}
  int pos() {
    if (p) {
      if (p->l == this)
        return -1;
      if (p->r == this)
        return 1;
    }
    return 0;
  }
  void rot() {
    NP q = p, qq = q->p;
    int qp = q->pos();
    if (q->l == this) {
      q->l = r;
      if (r != last) r->p = q;
      r = q;
      q->p = this;
    } else {
      q->r = l;
      if (l != last) l->p = q;
      l = q;
      q->p = this;
    }
    q->update();
    update();
    p = qq;
    if (!qp)
      return;
    if (qp == -1) {
      qq->l = this;
    } else {
      qq->r = this;
    }
    qq->update();
  }
  void splay() {
    assert(this != last);
    supush();
    int ps;
    while ((ps = pos())) {
      int pps = p->pos();
      if (!pps) {
        rot();
      } else if (ps == pps) {
        p->rot();
        rot();
      } else {
        rot();
        rot();
      }
    }
  }
  void expose() {
    assert(this != last);
    NP u = this;
    do {
      u->splay();
    } while ((u = u->p));
    u = last;
    u->p = this;
    do {
      u->p->r = u;
      u->p->update();
      u = u->p;
    } while (u->p);
    splay();
  }
  void push() {
    if (rev) {
      if (l->sz) {
        l->revdata();
      }
      if (r->sz) {
        r->revdata();
      }
      rev = false;
    }
    if (lz != DF) {
      if (l->sz) {
        l->lzdata(lz);
      }
      if (r->sz) {
        r->lzdata(lz);
      }
      lz = DF;
    }
  }
  void supush() {
    if (pos()) {
      p->supush();
    }
    push();
  }
  void revdata() {
    swap(l, r);
    swap(lsm, rsm);
    rev ^= true;
  }
  void lzdata(D d) {
    v = d;
    sm = sz * d;
    lsm = rsm = ma = max(0, sm);
    mv = d;
    lz = d;
  }
  NP update() {
    assert(this != last);
    sz = 1 + l->sz + r->sz;
    sm = v + l->sm + r->sm;
    lsm = max(l->lsm, l->sm + v + r->lsm);
    rsm = max(r->rsm, r->sm + v + l->rsm);
    ma = max(l->rsm + v + r->lsm, max(l->ma, r->ma));
    mv = max(v, max(l->mv, r->mv));
    return this;
  }
  void evert() {
    expose();
    revdata();
  }
};
LCNode LCNode::last_d = LCNode();
LCNode::NP LCNode::last = &last_d;
const int MN = 201000;
LCNode tr[MN];
int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; i++) {
    int w;
    scanf("%d", &w);
    tr[i] = LCNode(w);
  }
  for (int i = 0; i < n - 1; i++) {
    int s, e;
    scanf("%d %d", &s, &e);
    s--;
    e--;
    tr[s].evert();
    tr[e].expose();
    tr[s].p = &tr[e];
  }
  for (int i = 0; i < q; i++) {
    int t, a, b, c;
    scanf("%d %d %d %d", &t, &a, &b, &c);
    a--;
    b--;
    if (t == 1) {
      tr[a].evert();
      tr[b].expose();
      tr[b].lzdata(c);
    } else {
      tr[a].evert();
      tr[b].expose();
      int d;
      if (tr[b].mv < 0)
        d = tr[b].mv;
      else
        d = tr[b].ma;
      printf("%d\n", d);
    }
  }
}