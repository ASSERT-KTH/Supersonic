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

const int INF = 1LL << 25;
const int DF = 1LL << 25;
const int MN = 201000;

struct LCNode {
  int p, l, r;
  int sz;
  int v, sm, lz;
  int lsm, rsm, ma, mv;
  bool rev;
};

LCNode tr[MN];
int last = 0;

void rot(int x) {
  int y = tr[x].p;
  int z = tr[y].p;
  int yp = (tr[y].l == x) ? -1 : 1;
  
  if (tr[y].l == x) {
    tr[y].l = tr[x].r;
    tr[tr[x].r].p = y;
    tr[x].r = y;
    tr[y].p = x;
  } else {
    tr[y].r = tr[x].l;
    tr[tr[x].l].p = y;
    tr[x].l = y;
    tr[y].p = x;
  }
  
  tr[y].sz = 1 + tr[tr[y].l].sz + tr[tr[y].r].sz;
  tr[y].sm = tr[y].v + tr[tr[y].l].sm + tr[tr[y].r].sm;
  tr[y].lsm = max(tr[tr[y].l].lsm, tr[tr[y].l].sm + tr[y].v + tr[tr[y].r].lsm);
  tr[y].rsm = max(tr[tr[y].r].rsm, tr[tr[y].r].sm + tr[y].v + tr[tr[y].l].rsm);
  tr[y].ma = max(tr[tr[y].l].rsm + tr[y].v + tr[tr[y].r].lsm, max(tr[tr[y].l].ma, tr[tr[y].r].ma));
  tr[y].mv = max(tr[y].v, max(tr[tr[y].l].mv, tr[tr[y].r].mv));
  
  tr[x].sz = 1 + tr[y].sz + tr[tr[x].r].sz;
  tr[x].sm = tr[x].v + tr[y].sm + tr[tr[x].r].sm;
  tr[x].lsm = max(tr[y].lsm, tr[y].sm + tr[x].v + tr[tr[x].r].lsm);
  tr[x].rsm = max(tr[tr[x].r].rsm, tr[tr[x].r].sm + tr[x].v + tr[y].rsm);
  tr[x].ma = max(tr[y].rsm + tr[x].v + tr[tr[x].r].lsm, max(tr[y].ma, tr[tr[x].r].ma));
  tr[x].mv = max(tr[x].v, max(tr[y].mv, tr[tr[x].r].mv));
  
  tr[x].p = z;
  if (yp == -1)
    tr[z].l = x;
  else if (yp == 1)
    tr[z].r = x;
}

void splay(int x) {
  int ps;
  while ((ps = tr[x].p)) {
    int pps = tr[ps].p;
    
    if (!pps) {
      rot(x);
    } else if (ps * tr[pps].l == x * tr[ps].l) {
      rot(ps);
      rot(x);
    } else {
      rot(x);
      rot(x);
    }
  }
}

void push(int x) {
  if (tr[x].rev) {
    if (tr[x].l) {
      swap(tr[tr[x].l].l, tr[tr[x].l].r);
      swap(tr[tr[x].l].lsm, tr[tr[x].l].rsm);
      tr[tr[x].l].rev ^= true;
    }
    if (tr[x].r) {
      swap(tr[tr[x].r].l, tr[tr[x].r].r);
      swap(tr[tr[x].r].lsm, tr[tr[x].r].rsm);
      tr[tr[x].r].rev ^= true;
    }
    tr[x].rev = false;
  }
  if (tr[x].lz != DF) {
    if (tr[x].l) {
      tr[tr[x].l].v = tr[x].lz;
      tr[tr[x].l].sm = tr[tr[x].l].sz * tr[x].lz;
      tr[tr[x].l].lsm = tr[tr[x].l].rsm = tr[tr[x].l].ma = max(0, tr[tr[x].l].sm);
      tr[tr[x].l].mv = tr[x].lz;
      tr[tr[x].l].lz = tr[x].lz;
    }
    if (tr[x].r) {
      tr[tr[x].r].v = tr[x].lz;
      tr[tr[x].r].sm = tr[tr[x].r].sz * tr[x].lz;
      tr[tr[x].r].lsm = tr[tr[x].r].rsm = tr[tr[x].r].ma = max(0, tr[tr[x].r].sm);
      tr[tr[x].r].mv = tr[x].lz;
      tr[tr[x].r].lz = tr[x].lz;
    }
    tr[x].lz = DF;
  }
}

void expose(int x) {
  int u = x;
  int v = 0;
  while (u) {
    splay(u);
    tr[u].r = v;
    tr[u].update();
    v = u;
    u = tr[u].p;
  }
  splay(x);
}

void evert(int x) {
  expose(x);
  tr[x].rev ^= true;
}

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  
  for (int i = 1; i <= n; i++) {
    int w;
    scanf("%d", &w);
    tr[i].p = tr[i].l = tr[i].r = 0;
    tr[i].sz = 1;
    tr[i].v = tr[i].sm = w;
    tr[i].lz = DF;
    tr[i].lsm = tr[i].rsm = tr[i].ma = max(w, 0);
    tr[i].mv = w;
    tr[i].rev = false;
  }
  
  for (int i = 1; i < n; i++) {
    int s, e;
    scanf("%d %d", &s, &e);
    tr[s].p = e;
    evert(s);
  }
  
  for (int i = 0; i < q; i++) {
    int t, a, b, c;
    scanf("%d %d %d %d", &t, &a, &b, &c);
    if (t == 1) {
      evert(a);
      expose(b);
      tr[b].lzdata(c);
    } else {
      evert(a);
      expose(b);
      int d;
      if (tr[b].mv < 0)
        d = tr[b].mv;
      else
        d = tr[b].ma;
      printf("%d\n", d);
    }
  }
}