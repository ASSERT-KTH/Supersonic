#include <algorithm>
#include <vector>

typedef long long ll;
typedef std::pair<int, int> P;

struct Tree {
  struct Node {
    Node(int sz = 0) : sz(sz), lzf(false), d(0), sm(0), lz(0), lsm(0), rsm(0), ma(0), mv(0) {}
    int sz;
    int d, sm, lz;
    int lsm, rsm, ma, mv;
    bool lzf;
  } n;

  Tree* l;
  Tree* r;

  Tree() : l(nullptr), r(nullptr) {}
  Tree(int sz, int hev[], int hevsm[], int data[]) : n(sz), l(nullptr), r(nullptr) {
    if (sz == 1) {
      lzdata(data[0]);
      return;
    }
    int sm = hevsm[sz] - hevsm[0];
    int md = (sm / 2 + hevsm[0] <= 200200) ? sz / 2 : lower_bound(hevsm, hevsm + sz - 1, sm / 2 + hevsm[0]) - hevsm;
    l = new Tree(md, hev, hevsm, data);
    r = new Tree(sz - md, hev + md, hevsm + md, data + md);
    n = merge(l->n, r->n);
  }

  void lzdata(int d) {
    n.d = n.mv = d;
    n.sm = n.sz * d;
    n.lsm = n.rsm = n.ma = std::max(0, n.sm);
    n.lz = d;
    n.lzf = true;
  }

  void push() {
    if (n.sz == 1)
      return;
    if (n.lzf) {
      l->lzdata(n.lz);
      r->lzdata(n.lz);
      n.lzf = false;
    }
  }

  static Node merge(const Node& l, const Node& r) {
    if (l.sz == 0)
      return r;
    if (r.sz == 0)
      return l;
    Node res(l.sz + r.sz);
    res.sm = l.sm + r.sm;
    res.lsm = std::max(l.lsm, l.sm + r.lsm);
    res.rsm = std::max(r.rsm, r.sm + l.rsm);
    res.ma = std::max(std::max(l.ma, r.ma), l.rsm + r.lsm);
    res.mv = std::max(l.mv, r.mv);
    return res;
  }

  static Node rev(Node u) {
    std::swap(u.lsm, u.rsm);
    return u;
  }

  void set(int a, int b, int x) {
    if (b <= 0 || n.sz <= a) {
      return;
    }
    push();
    if (a <= 0 && n.sz <= b) {
      lzdata(x);
      return;
    }
    l->set(a, b, x);
    r->set(a - l->n.sz, b - l->n.sz, x);
    n = merge(l->n, r->n);
  }
