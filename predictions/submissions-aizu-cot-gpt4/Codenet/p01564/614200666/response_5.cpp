#define NDEBUG
#include <cassert>
#include <cstdio>
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
        lsm(std::max(v, 0)), rsm(std::max(v, 0)), ma(std::max(v, 0)), mv(v) {}
  LCNode() : l(NULL), r(NULL), sz(0), v(-INF), mv(-INF) {}
  //... rest of the code remains the same
const int MN = 201000;
LCNode tr[MN];
int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; ++i) {
    int w;
    scanf("%d", &w);
    tr[i] = LCNode(w);
  }
  for (int i = 0; i < n - 1; ++i) {
    int s, e;
    scanf("%d %d", &s, &e);
    s--;
    e--;
    tr[s].evert();
    tr[e].expose();
    tr[s].p = &tr[e];
  }
  for (int i = 0; i < q; ++i) {
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