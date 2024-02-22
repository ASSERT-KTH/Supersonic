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
  
  // ... (omitted unchanged parts)

  void expose() {
    assert(this != last);
    NP u = this;
    do {
      u->splay();
    } while ((u = u->p));
    u = last;
    u->p = this;
    do {
      if (u->p != last) {
        u->p->r = u;
        u->p->update();
      }
      u = u->p;
    } while (u->p);
    splay();
  }

  void supush() {
    if (pos()) {
      p->supush();
    }
    if (rev || lz != DF) {
      push();
    }
  }

  // ... (omitted unchanged parts)
};