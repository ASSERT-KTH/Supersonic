#include <cstdio>
#include <algorithm>

struct LCNode {
  typedef LCNode *NP;
  typedef int D;
  static const int INF = 1LL << 25;
  static const int DF = 1LL << 25;
  NP p, l, r;
  int sz;
  int v, sm, lz;
  int lsm, rsm, ma, mv;
  bool rev;
  LCNode(D v)
      : p(NULL), l(NULL), r(NULL), sz(1), v(v), sm(v), lz(DF), rev(false),
        lsm(std::max(v, 0)), rsm(std::max(v, 0)), ma(std::max(v, 0)), mv(v) {}
  int pos() {
    return p ? (p->l == this ? -1 : (p->r == this ? 1 : 0)) : 0;
  }
  void rot() {
    NP q = p, qq = q->p;
    int qp = q->pos();
    if (q->l == this) {
      q->l = r;
      r->p = q;
      r = q;
      q->p = this;
    } else {
      q->r = l;
      l->p = q;
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
    NP u = this;
    do {
      u->splay();
    } while ((u = u->p));
    u = this;
    u->p = NULL;
    do {
      u->p = u->r;
      u->r = NULL;
      u->update();
      u = u->p;
    } while (u);
    splay();
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
  void revdata() {
    std::swap(l, r);
    std::swap(lsm, rsm);
    rev ^= true;
  }
  void lzdata(D d) {
    v = d;
    sm = sz * d;
    lsm = rsm = ma = std::max(0, sm);
    mv = d;
    lz = d;
  }
  NP update() {
    sz = 1 + (l ? l->sz : 0) + (r ? r->sz : 0);
    sm = v + (l ? l->sm : 0) + (r ? r->sm : 0);
    lsm = std::max((l ? l->lsm : 0), (l ? l->sm : 0) + v + (r ? r->lsm : 0));
    rsm = std::max((r ? r->rsm : 0), (r ? r->sm : 0) + v + (l ? l->rsm : 0));
    ma = std::max((l ? l->rsm : 0) + v + (r ? r->lsm : 0), std::max((l ? l->ma : 0), (r ? r->ma : 0)));
    mv = std::max(v, std::max((l ? l->mv : 0), (r ? r->mv : 0)));
    return this;
  }
  void evert() {
    expose();
    revdata();
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
      int d = (tr[b].mv < 0) ? tr[b].mv : tr[b].ma;
      printf("%d\n", d);
    }
  }
}