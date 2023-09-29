#include <bits/stdc++.h>
using namespace std;
struct SegmentTree {
  vector<int> seg, add;
  int sz;
  SegmentTree(int n) {
    sz = 1;
    while (sz < n)
      sz *= 2;
    seg.assign(sz * 2 + 1, 0), add.assign(sz * 2 + 1, 0);
  }
  void Add(int a, int b, int x, int k, int l, int r) {
    if (a >= r || b <= l) {
      return;
    } else if (a <= l && r <= b) {
      add[k] += x;
    } else {
      Add(a, b, x, 2 * k + 1, l, (l + r) / 2);
      Add(a, b, x, 2 * k + 2, (l + r) / 2, r);
      seg[k] =
          seg[2 * k + 1] + add[2 * k + 1] + seg[2 * k + 2] + add[2 * k + 2];
    }
  }
  int Query(int a, int b, int k, int l, int r) {
    if (a >= r || b <= l)
      return (0);
    if (a <= l && r <= b)
      return (seg[k] + add[k]);
    else
      return (Query(a, b, 2 * k + 1, l, (l + r) / 2) +
            Query(a, b, 2 * k + 2, (l + r) / 2, r) + add[k]);
  }
  void Add(int a, int b, int x) { Add(a, b, x, 0, 0,