#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template <typename Monoid> struct LazySegmentTree {
private:
  int N;
  Monoid node[4*100000], lazy[4*100000]; // Assume maximum size of array is 100000

public:
  LazySegmentTree(int sz = 0) { init(sz); }
  void init(int sz) {
    N = 1 << (int)(ceil(log2(sz)));
    fill(node, node + 2 * N - 1, 0);
    fill(lazy, lazy + 2 * N - 1, 0);
  }
  // ... Rest of the code remains same ...
  void eval(int k) {
    if (lazy[k] != 0) {
      node[k] += lazy[k];
      if (k < N - 1) {
        lazy[2 * k + 1] += lazy[k] >> 1;
        lazy[2 * k + 2] += lazy[k] >> 1;
      }
      lazy[k] = 0;
    }
  }
  // ... Rest of the code remains same ...
  Monoid getSum(int a, int b, int k, int l, int r) {
    if (b <= l || r <= a)
      return 0;
    eval(k);
    if (a <= l && r <= b)
      return node[k];
    return getSum(a, b, 2 * k + 1, l, (l + r) / 2) + getSum(a, b, 2 * k + 2, (l + r) / 2, r);
  }
};
// ... Rest of the code remains same ...