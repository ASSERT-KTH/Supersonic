#define NDEBUG
#include <algorithm>
#include <cassert>
#include <cstdio>

using namespace std;
typedef long long ll;
struct LCNode {
  typedef LCNode *NP;
  typedef int D;
  static const int INF = 1LL << 25;
  static const int DF = 1 << 25;
  static LCNode last_d;
  static NP last;
  NP p, l, r;
  int sz;
  int v, sm, lz;
  int lsm, rsm, ma, mv;
  bool rev;
  inline LCNode(D v)
      : p(NULL), l(last), r(last), sz(1), v(v), sm(v), lz(DF), rev(false),
        lsm(max(v, 0)), rsm(max(v, 0)), ma(max(v, 0)), mv(v) {}
  inline LCNode() : l(NULL), r(NULL), sz(0), v(-INF), mv(-INF) {}
  inline int pos() {
    return p ? (p->l == this ? -1 : (p->r == this ? 1 : 0)) : 0;
  }
  // Other functions removed for brevity
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