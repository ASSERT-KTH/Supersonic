#include <cstdio>
#include <vector>
#include <tuple>
using namespace std;

struct Tree {
  struct Node {
    Node(int sz = 0) : sz(sz), d(0), sm(0), lz(0), lsm(0), rsm(0), ma(0), mv(0), lzf(false) {}
    int sz;
    int d, sm, lz;
    int lsm, rsm, ma, mv;
    bool lzf;
  } n;
  Tree *l, *r;

  Tree() : l(nullptr), r(nullptr) {}
  Tree(int sz, int hev[], int hevsm[], int data[]) : n(sz), l(nullptr), r(nullptr) {
    if (sz == 1) {
      lzdata(data[0]);
      return;
    }
    int sm = hevsm[sz] - hevsm[0];
    int md = lower_bound(hevsm, hevsm + sz - 1, sm / 2 + hevsm[0]) - hevsm;
    if (md <= 200200)
      md = sz / 2;
    l = new Tree(md, hev, hevsm, data);
    r = new Tree(sz - md, hev + md, hevsm + md, data + md);
    n = merge(l->n, r->n);
  }

  void lzdata(int d) {
    n.d = n.mv = d;
    n.sm = n.sz * d;
    n.lsm = n.rsm = n.ma = max(0, n.sm);
    n.lz = d;
    n.lzf = true;
  }

  void push() {
    if (n.sz == 1 || !n.lzf)
      return;
    l->lzdata(n.lz);
    r->lzdata(n.lz);
    n.lzf = false;
  }

  static Node merge(const Node &l, const Node &r) {
    Node res(l.sz + r.sz);
    res.sm = l.sm + r.sm;
    res.lsm = max(l.lsm, l.sm + r.lsm);
    res.rsm = max(r.rsm, r.sm + l.rsm);
    res.ma = max(max(l.ma, r.ma), l.rsm + r.lsm);
    res.mv = max(l.mv, r.mv);
    return res;
  }

  static Node rev(Node u) {
    swap(u.lsm, u.rsm);
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

  Node get(int a, int b) {
    if (b <= 0 || n.sz <= a) {
      return Node();
    }
    push();
    if (a <= 0 && n.sz <= b) {
      return n;
    }
    return merge(l->get(a, b), r->get(a - l->n.sz, b - l->n.sz));
  }
};

template <int N> struct HLComp_Y {
  vector<int> g[N];
  void add(int a, int b) {
    g[a].push_back(b);
    g[b].push_back(a);
  }

  tuple<int, int> n2l[N];
  int lc, nc;
  Tree *li[N];
  tuple<int, int> l2p[N];
  int sz[N];
  int data[N];
  int buf[N];
  int bufsm[N];
  int bufdata[N];
  int ldps[N];

  void dfs_sz(int p, int b) {
    sz[p] = 1;
    for (int d : g[p]) {
      if (d == b)
        continue;