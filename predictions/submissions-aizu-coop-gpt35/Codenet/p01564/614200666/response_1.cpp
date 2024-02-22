#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;

const int MN = 201000;

struct LCNode {
  typedef int D;
  static const int INF = 1LL << 25;
  static const int DF = 1LL << 25;
  int p, l, r;
  int sz;
  int v, sm, lz;
  int lsm, rsm, ma, mv;
  bool rev;

  LCNode(D v)
      : p(-1), l(-1), r(-1), sz(1), v(v), sm(v), lz(DF), rev(false),
        lsm(max(v, 0)), rsm(max(v, 0)), ma(max(v, 0)), mv(v) {}

  LCNode() : l(-1), r(-1), sz(0), v(-INF), mv(-INF) {}

  int pos() {
    if (p != -1) {
      if (tr[p].l == this)
        return -1;
      if (tr[p].r == this)
        return 1;
    }
    return 0;
  }

  void rot() {
    int q = p, qq = tr[q].p;
    int qp = tr[q].pos();
    if (tr[q].l == this) {
      tr[q].l = r;
      tr[r].p = q;
      r = q;
      tr[q].p = this;
    } else {
      tr[q].r = l;
      tr[l].p = q;
      l = q;
      tr[q].p = this;
    }
    tr[q].update();
    update();
    p = qq;
    if (!qp)
      return;
    if (qp == -1) {
      tr[qq].l = this;
    } else {
      tr[qq].r = this;
    }
    tr[qq].update();
  }

  void splay() {
    supush();
    int ps;
    while ((ps = pos())) {
      int pps = tr[p].pos();
      if (!pps) {
        rot();
      } else if (ps == pps) {
        tr[p].rot();
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
    } while ((u = &tr[u->p]));
    u = &tr[last];
    u->p = this;
    do {
      tr[u->p].r = u;
      tr[u->p].update();
      u = &tr[u->p];
    } while (u->p != -1);
    splay();
  }

  void push() {
    if (rev) {
      if (l != -1) {
        tr[l].revdata();
      }
      if (r != -1) {
        tr[r].revdata();
      }
      rev = false;
    }
    if (lz != DF) {
      if (l != -1) {
        tr[l].lzdata(lz);
      }
      if (r != -1) {
        tr[r].lzdata(lz);
      }
      lz = DF;
    }
  }

  void supush() {
    if (pos() != 0) {
      tr[p].supush();
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

  void update() {
    sz = 1 + (l != -1 ? tr[l].sz : 0) + (r != -1 ? tr[r].sz : 0);
    sm = v + (l != -1 ? tr[l].sm : 0) + (r != -1 ? tr[r].sm : 0);
    lsm = max((l != -1 ? tr[l].lsm : 0), (l != -1 ? tr[l].sm : 0) + v + (r != -1 ? tr[r].lsm : 0));
    rsm = max((r != -1 ? tr[r].rsm : 0), (r != -1 ? tr[r].sm : 0) + v + (l != -1 ? tr[l].rsm : 0));
    ma = max((l != -1 ? tr[l].rsm : 0) + v + (r != -1 ? tr[r].lsm : 0), max((l != -1 ? tr[l].ma : 0), (r != -1 ? tr[r].ma : 0)));
    mv = max(v, max((l != -1 ? tr[l].mv : 0), (r != -1 ? tr[r].mv : 0)));
  }

  void evert() {
    expose();
    revdata();
  }
};

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
    tr[s].p = e;
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