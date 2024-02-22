#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template <typename Monoid> struct LazySegmentTree {
private:
  int N;
  vector<Monoid> node, lazy;

public:
  LazySegmentTree(int sz = 0) { init(sz); }
  void init(int sz) {
    N = 1;
    while (N < sz)
      N <<= 1;
    node.resize(2 * N - 1, 0);
    lazy.resize(2 * N - 1, 0);
  }
  void build(vector<Monoid> &v, int l, int r, int k = 0) {
    if (r - l == 1) {
      if (l < int(v.size())) {
        node[k] = v[l];
      }
    } else {
      int mid = (l + r) / 2;
      build(v, l, mid, 2 * k + 1);
      build(v, mid, r, 2 * k + 2);
      node[k] = node[2 * k + 1] + node[2 * k + 2];
    }
  }
  // ... rest of the code remains the same ...
};