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
  // ...
  NP update() {
    assert(this != last);
    sz = 1 + l->sz + r->sz;
    sm = v + l->sm + r->sm;
    int lsm_v = l->sm + v;
    lsm = max(l->lsm, lsm_v + r->lsm);
    rsm = max(r->rsm, r->sm + v + l->rsm);
    ma = max(l->rsm + v + r->lsm, max(l->ma, r->ma));
    mv = max(v, max(l->mv, r->mv));
    return this;
  }
  // ...
};
LCNode LCNode::last_d = LCNode();
LCNode::NP LCNode::last = &last_d;
const int MN = 201000;
LCNode tr[MN];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, q, w, s, e, t, a, b, c, d, i;

  scanf("%d %d", &n, &q);
  for (i = 0; i < n; i++) {
    scanf("%d", &w);
    tr[i] = LCNode(w);
  }
  for (i = 0; i < n - 1; i++) {
    scanf("%d %d", &s, &e);
    s--;
    e--;
    tr[s].evert();
    tr[e].expose();
    tr[s].p = &tr[e];
  }
  for (i = 0; i < q; i++) {
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
      if (tr[b].mv < 0)
        d = tr[b].mv;
      else
        d = tr[b].ma;
      printf("%d\n", d);
    }
  }
}