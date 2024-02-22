#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template <typename Monoid> struct LazySegmentTree {
private:
  int N;
  vector<Monoid> node, lazy;

public:
  LazySegmentTree(int sz) {
    N = 1;
    while (N < sz)
      N <<= 1;
    node.resize(2 * N - 1, 0);
    lazy.resize(2 * N - 1, 0);
  }
  void build(vector<Monoid> &v) {
    int sz = int(v.size());
    for (int i = 0; i < sz; i++) {
      node[i + N - 1] = v[i];
    }
    for (int i = N - 2; i >= 0; i -= 2) {
      node[i] = node[i * 2 + 1] + node[i * 2 + 2];
      node[i - 1] = node[(i - 1) * 2 + 1] + node[(i - 1) * 2 + 2];
    }
  }
  void eval(int k) {
    node[k] += lazy[k];
    if (k < N - 1) {
      lazy[2 * k + 1] += lazy[k] / 2;
      lazy[2 * k + 2] += lazy[k] / 2;
    }
    lazy[k] = 0;
  }
  // rest of the code remains the same
};