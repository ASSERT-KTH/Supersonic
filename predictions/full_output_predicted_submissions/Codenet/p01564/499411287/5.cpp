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
    l = new Node(md, hev, hevsm, data);
    r = new Tree(sz - md, hev + md, hevsm + md, data + md);
    n = merge(l->n, r->n);
  }
  void lzdata(int d) {
    n.d = n.mv = d;
    n.sm = n.sz * d;
    n.lsm