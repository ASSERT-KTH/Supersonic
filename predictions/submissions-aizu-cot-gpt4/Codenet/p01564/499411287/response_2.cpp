#include <vector>
#include <cstdio>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

struct Tree {
  typedef Tree *NP;
  NP l, r;
  struct Node {
    Node(int sz = 0) : sz(sz), lzf(false) {}
    int sz;
    int d, sm, lz;
    int lsm, rsm, ma, mv;
    bool lzf;
  } n;

  static Node merge(const Node &l, const Node &r) {
    int res_sm = l.sm + r.sm;
    int res_lsm = max(l.lsm, l.sm + r.lsm);
    int res_rsm = max(r.rsm, r.sm + l.rsm);
    int res_ma = max(max(l.ma, r.ma), l.rsm + r.lsm);
    int res_mv = max(l.mv, r.mv);

    Node res(l.sz + r.sz);
    res.sm = res_sm;
    res.lsm = res_lsm;
    res.rsm = res_rsm;
    res.ma = res_ma;
    res.mv = res_mv;
    return res;
  }
};

template <int N> struct HLComp_Y {
  vector<int> g[N];

  void path_set(int u, int v, int d) {
    auto [xl, xp] = n2l[u];
    auto [yl, yp] = n2l[v];
    int lc = lca_line(u, v);
    while (xl != lc) {
      li[xl]->set(0, xp + 1, d);
      tie(xl, xp) = l2p[xl];
    }
    while (yl != lc) {
      li[yl]->set(0, yp + 1, d);
      tie(yl, yp) = l2p[yl];
    }
    if (xp > yp) {
      li[xl]->set(yp, xp + 1, d);
    } else {
      li[yl]->set(xp, yp + 1, d);
    }
  }
};

int main2() {
  int n = getint();
  int q = getint();

  for (int i = 0; i < n; i++) {
    int w = getint();
    hl.data[i] = w;
  }

  for (int i = 0; i < n - 1; i++) {
    int s = getint();
    int e = getint();
    s--;
    e--;
    hl.add(s, e);
  }

  hl.init();

  for (int i = 0; i < q; i++) {
    int t = getint();
    int a = getint();
    int b = getint();
    int c = getint();
    a--;
    b--;
    if (t == 1) {
      hl.path_set(a, b, c);
    } else {
      auto n = hl.path_get(a, b);
      putint((n.mv < 0) ? n.mv : n.ma);
      putchar_unlocked('\n');
    }
  }
  return 0;
}

int main() {
#ifndef __APPLE__
  static ll eord, enew;
  const int sz = 32 * 1024 * 1024;
  static void *p = malloc(sz);
  enew = (long long)p + sz - 1;
  __asm__ volatile("mov %%rsp, %0" : "=r"(eord));
  __asm__ volatile("mov %0, %%rsp" : : "r"(enew));
#endif
  main2();
#ifndef __APPLE__
  __asm__ volatile("mov %0, %%rsp" : : "r"(eord));
#endif
  return 0;
}