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
  typedef LCNode* NP;
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

  LCNode(D v) : p(NULL), l(last), r(last), sz(1), v(v), sm(v), lz(DF), rev(false),
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

  void zig() {
    NP q = p;
    NP r = q->p;
    if (r) {
      if (r->l == q)
        r->l = this;
      else
        r->r = this;
    }
    p = r;
    q->p = this;
    q->l = r = r == NULL ? NULL : r->l == q ? r->l = this : r->r = this;
    if (l != NULL) {
      l->p = q;
      q->r = l;
    } else {
      q->r = NULL;
    }
    l = q;
    if (r != NULL) {
      r->p = this;
    }
    update();
    q->update();
  }

  void zag() {
    NP q = p;
    NP r = q->p;
    if (r) {
      if (r->l == q)
        r->l = this;
      else
        r->r = this;
    }
    p = r;
    q->p = this;
    q->r = r = r == NULL ? NULL : r->r == q ? r->r = this : r->l = this;
    if (r != NULL) {
      r->p = q;
      q->l = r;
    } else {
      q->l = NULL;
    }
    r = q;
    if (l != NULL) {
      l->p = this;
    }
    l = q;
    update();
    q->update();
  }

  void splay() {
    assert(this != last);
    supush();
    int ps;
    while ((ps = pos())) {
      int pps = p->pos();
      if (!pps) {
        if (ps == -1)
          zig();
        else
          zag();
      } else if (ps == pps) {
        p->splay();
        if (ps == -1)
          zig(), zig();
        else
          zag(), zag();
      } else {
        if (ps == -1)
          zig(), zag();
        else
          zag(), zig();
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
    int lsmv = l->sm + v;
    int rsmv = r->sm + v;
    lsm = max(l->lsm, lsmv);
    rsm = max(r->rsm, rsmv);
    ma = max(max(l->rsm + v + r->lsm, l->ma), r->ma);
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
vector<LCNode*> tr;

int main() {
  int n, q;
  cin >> n >> q;
  tr.resize(n);
  for (int i = 0; i < n; i++) {
    int w;
    cin >> w;
    tr[i] = new LCNode(w);
  }
  for (int i = 0; i < n - 1; i++) {
    int s, e;
    cin >> s >> e;
    s--;
    e--;
    tr[s]->evert();
    tr[e]->expose();
    tr[s]->p = tr[e];
  }
  for (int i = 0; i < q; i++) {
    int t, a, b, c;
    cin >> t >> a >> b >> c;
    a--;
    b--;
    if (t == 1) {
      tr[a]->evert();
      tr[b]->expose();
      tr[b]->lzdata(c);
    } else {
      tr[a]->evert();
      tr[b]->expose();
      int d;
      if (tr[b]->mv < 0)
        d = tr[b]->mv;
      else
        d = tr[b]->ma;
      cout << d << "\n";
    }
  }

  // Clean up dynamically allocated memory
  for (LCNode* node : tr) {
    delete node;
  }

  return 0;
}