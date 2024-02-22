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
  /* ... rest of the LCNode structure ... */
  NP update() {
    assert(this != last);
    int sz_tmp = l->sz + r->sz + 1;
    int sm_v_rsm_tmp = l->sm + v + r->sm;
    int v_l_rsm_tmp = r->sm + v + l->rsm;
    sz = sz_tmp;
    sm = sm_v_rsm_tmp;
    lsm = max(l->lsm, sm_v_rsm_tmp);
    rsm = max(r->rsm, v_l_rsm_tmp);
    ma = max(l->rsm + v + r->lsm, max(l->ma, r->ma));
    mv = max(v, max(l->mv, r->mv));
    return this;
  }
  /* ... rest of the LCNode structure ... */
};
LCNode LCNode::last_d = LCNode();
LCNode::NP LCNode::last = &last_d;
const int MN = 201000;
LCNode tr[MN];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    int w;
    cin >> w;
    tr[i] = LCNode(w);
  }
  /* ... rest of the main function ... */
  for (int i = 0; i < q; i++) {
    int t, a, b, c;
    cin >> t >> a >> b >> c;
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
      cout << d << "\n";
    }
  }
}