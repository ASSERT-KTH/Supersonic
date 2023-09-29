#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <valarray>
#include <vector>
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
  Tree() {}
  Tree(int sz, int hev[], int hevsm[], int data[]) : n(sz) {
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
    if (n.sz == 1)
      return;
    if (n.lzf) {
      l->lzdata(n.lz);
      r->lzdata(n.lz);
      n.lzf = false;
    }
  }
  static Node merge(const Node &l, const Node &r) {
    if (l.sz == 0)
      return r;
    if (r.sz == 0)
      return l;
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
    if (b <= 0 || n.sz <= a)
      return;
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
    if (b <= 0 || n.sz <= a)
      return Node();
    push();
    if (a <= 0 && n.sz <= b)
      return n;
    return merge(l->get(a, b), r->get(a - l->n.sz, b - l->n.sz));
  }
};
template <int N> struct HLComp_Y {
  vector<int> g[N];
  void add(int a, int b) {
    g[a].push_back(b);
    g[b].push_back(a);
  }
  P n2l[N];
  int lc, nc;
  Tree *li[N];
  P l2p[N];
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
      dfs_sz(d, p);
      sz[p] += sz[d];
    }
  }
  void dfs(int p, int b) {
    if (g[p].size() == (b == -1 ? 0 : 1)) {
      buf[nc] = 1;
      bufdata[nc] = data[p];
      bufsm[nc + 1] = bufsm[nc] + buf[nc];
      li[lc] = new Tree(nc + 1, buf, bufsm, bufdata);
      return;
    }
    int ma = -1, md = -1;
    for (int d : g[p]) {
      if (d == b)
        continue;
      if (ma < sz[d]) {
        ma = sz[d];
        md = d;
      }
    }
    n2l[md] = P(lc, nc + 1);
    buf[nc] = sz[p] - sz[md];
    bufdata[nc] = data[p];
    bufsm[nc + 1] = bufsm[nc] + buf[nc];
    nc++;
    dfs(md, p);
    for (int d : g[p]) {
      if (d == b)
        continue;
      if (d == md)
        continue;
      lc++;
      nc = 0;
      n2l[d] = P(lc, 0);
      l2p[lc] = n2l[p];
      ldps[lc] = ldps[n2l[p].first] + 1;
      dfs(d, p);
    }
  }
  void init() {
    n2l[0] = P(0, 0);
    l2p[0] = P(-1, 0);
    ldps[0] = 0;
    bufsm[0] = 0;
    lc = nc = 0;
    dfs_sz(0, -1);
    dfs(0, -1);
  }
  int lca_line(int u, int v) {
    int xl = n2l[u].first;
    int yl = n2l[v].first;
    if (ldps[xl] < ldps[yl])
      swap(xl, yl);
    while (ldps[xl] > ldps[yl]) {
      xl = l2p[xl].first;
    }
    while (xl != yl) {
      xl = l2p[x