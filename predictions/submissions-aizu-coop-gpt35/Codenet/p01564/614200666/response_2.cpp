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

const int MN = 201000;
struct LCNode {
  typedef int D;
  static const int INF = 1LL << 25;
  static const int DF = 1LL << 25;
  static LCNode last_d;
  static int last;
  int p, l, r;
  int sz;
  int v, sm, lz;
  int lsm, rsm, ma, mv;
  bool rev;
  LCNode(D v)
      : p(-1), l(last), r(last), sz(1), v(v), sm(v), lz(DF), rev(false),
        lsm(max(v, 0)), rsm(max(v, 0)), ma(max(v, 0)), mv(v) {}
  LCNode() : l(-1), r(-1), sz(0), v(-INF), mv(-INF) {}
  int pos() {
    if (p) {
      return (tr[p].l == last ? -1 : (tr[p].r == last ? 1 : 0));
    }
    return 0;
  }
  void rot() {
    int q = p, qq = tr[q].p;
    int qp = (tr[qq].l == q ? -1 : 1);
    int tmp = (tr[q].l == last ? tr[q].l : tr[q].r); // Store the value of q->l or q->r
    if (tr[q].l == last) {
      tr[q].l = r;
      tr[r].p = q;
      r = q;
      tr[q].p = last;
    } else {
      tr[q].r = l;
      tr[l].p = q;
      l = q;
      tr[q].p = last;
    }
    tr[q].update();
    update();
    p = qq;
    if (!qp)
      return;
    if (qp == -1) {
      tr[qq].l = tmp; // Assign the stored value to r or l
    } else {
      tr[qq].r = tmp; // Assign the stored value to r or l
    }
    tr[qq].update();
  }
  void splay() {
    assert(this != last);
    push();
    while (pos()) {
      int pps = tr[p].pos();
      if (!pps) {
        rot();
      } else if (pos() == pps) {
        tr[p].rot();
        rot();
      } else {
        rot();
        rot();
      }
    }
  }
  void expose() {
    assert(this != last);
    int u = tr[this].p;
    do {
      tr[u].splay();
    } while ((u = tr[u].p));
    u = last;
    tr[u].p = this;
    do {
      tr[u].p->r = u;
      tr[u].p->update();
      u = tr[u].p;
    } while (tr[u].p);
    splay();
  }
  void push() {
    for (int i = 0; i < 2; i++) {
      if (tr[l[i]].sz) {
        tr[l[i]].revdata();
      }
    }
    rev = false;
    for (int i = 0; i < 2; i++) {
      if (tr[r[i]].sz) {
        tr[r[i]].revdata();
      }
    }
    if (lz != DF) {
      for (int i = 0; i < 2; i++) {
        if (tr[l[i]].sz) {
          tr[l[i]].lzdata(lz);
        }
      }
      for (int i = 0; i < 2; i++) {
        if (tr[r[i]].sz) {
          tr[r[i]].lzdata(lz);
        }
      }
      lz = DF;
    }
  }
  void supush() {
    if (pos()) {
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
    assert(this != last);
    sz = 1 + tr[l].sz + tr[r].sz;
    sm = v + tr[l].sm + tr[r].sm;
    lsm = max(tr[l].lsm, tr[l].sm + v + tr[r].lsm);
    rsm = max(tr[r].rsm, tr[r].sm + v + tr[l].rsm);
    ma = max(tr[l].rsm + v + tr[r].lsm, max(tr[l].ma, tr[r].ma));
    mv = max(v, max(tr[l].mv, tr[r].mv));
  }
  void evert() {
    expose();
    revdata();
  }
};