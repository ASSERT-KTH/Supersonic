#include <cstdio>
#include <vector>
#include <tuple>
#include <stack>
using namespace std;

struct Tree {
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
    if (b <= 0 || n.sz <= a) {
      return;
    }
    
    stack<pair<Tree*, int>> stk;
    stk.push(make_pair(this, 0));
    
    while (!stk.empty()) {
      auto [curr, idx] = stk.top();
      stk.pop();
      
      curr->push();
      
      if (a <= idx && idx + curr->n.sz <= b) {
        curr->lzdata(x);
      } else if (idx < b && a < idx + curr->n.sz) {