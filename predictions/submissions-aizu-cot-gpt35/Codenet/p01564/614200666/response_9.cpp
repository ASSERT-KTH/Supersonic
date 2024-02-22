#include <algorithm>
#include <cassert>
#include <iostream>
using namespace std;

typedef long long ll;

struct LCNode {
  typedef LCNode *NP;
  typedef int D;
  static const int INF = 1LL << 25;
  static const int DF = 1LL << 25;

  NP p, l, r;
  int v, sm, lz;
  bool rev;

  LCNode(D v)
      : p(NULL), l(NULL), r(NULL), v(v), sm(v), lz(DF), rev(false) {}

  void rot() {
    NP q = p, qq = q->p;
    if (q->l == this) {
      q->l = r;
      r = q;
      q->p = this;
    } else {
      q->r = l;
      l = q;
      q->p = this;
    }
    q->update();
    update();
    p = qq;
    if (!p)
      return;
    if (qq->l == q) {
      qq->l = this;
    } else {
      qq->r = this;
    }
    qq->update();
  }

  void splay() {
    assert(this != NULL);
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
    assert(this != NULL);
    NP u = this;
    do {
      u->splay();
    } while ((u = u->p));
    u = NULL;
    do {
      u->r = this;
      u->update();
      u = u->p;
    } while (u);
    splay();
  }

  void evert() {
    expose();
    revdata();
  }

  void revdata() {
    swap(l, r);
    rev ^= true;
  }

  void lzdata(D d) {
    v = d;
    sm = d;
    lz = d;
  }

  int pos() {
    if (p) {
      if (p->l == this)
        return -1;
      if (p->r == this)
        return 1;
    }
    return 0;
  }

  void push() {
    if (rev) {
      if (l) {
        l->revdata();
      }
      if (r) {
        r->revdata();
      }
      rev = false;
    }
    if (lz != DF) {
      if (l) {
        l->lzdata(lz);
      }
      if (r) {
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

  NP update() {
    assert(this != NULL);
    sm = v + (l ? l->sm : 0) + (r ? r->sm : 0);
    return this;
  }
};

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
      if (tr[b].v < 0)
        d = tr[b].v;
      else
        d = tr[b].sm;
      printf("%d\n", d);
    }
  }
}