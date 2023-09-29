#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template <typename Monoid> struct LazySegmentTree {
private:
  int N;
  vector<Monoid> node, lazy;
  inline void eval(int k, int l, int r) {
    node[k] += lazy[k] * (r - l);
    if (r - l > 1) {
      lazy[2 * k + 1] += lazy[k] / 2;
      lazy[2 * k + 2] += lazy[k] / 2;
    }
    lazy[k] = 0;
  }
  void add(int a, int b, Monoid x, int k, int l, int r) {
    eval(k, l, r);
    if (b <= l || r <= a)
      return;
    if (a <= l && r <= b) {
      lazy[k] += x;
      eval(k, l, r);
    } else {
      add(a, b, x, 2 * k + 1, l, (l + r) / 2);
      add(a, b, x, 2 * k + 2, (l + r) / 2, r);
      node[k] = node[2 * k + 1] + node[2 * k + 2];
    }
  }
  Monoid getSum(int a, int b, int k, int l, int r) {
    eval(k, l, r);
    if (b <= l || r <= a)
      return 0;
    if (a <= l && r <= b)
      return node[k];
    Monoid vl, vr;
    vl = getSum(a, b, 2 * k + 1, l, (l + r) / 2);
    vr = getSum(a, b, 2 * k + 2, (l + r) / 2, r);
    return vl + vr;
  }

public:
  LazySegmentTree(int sz = 0) { init(sz); }
  void init(int sz) {
    N = 1;
    while (N < sz)
      N <<= 1;
    node.resize(2 * N - 1, 0);
    lazy.resize(2 * N - 1, 0);
  }
  void build(vector<Monoid> &v) {
    int sz = int(v.size());
    init(sz);
    for (int i = 0; i < sz; i++) {
      node[i + N - 1] = v[i];
    }
    for (int i = N - 2; i >= 0; i--) {
      node[i] = node[i * 2 + 1] + node[i * 2 + 2];
    }
  }
  void add(int a, int b, Monoid x) { add(a, b, x, 0, 0, N); }
  Monoid getSum(int a, int b) { return getSum(a, b, 0, 0, N); }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  LazySegmentTree<ll> seg(n);
  while (q--) {
    int c;
    cin >> c;
    if (c == 0) {
      ll s, t, x;
      cin >> s >> t >> x;
      seg.add(s - 1, t, x);
    } else {
      int s;
      cin >> s;
      cout << seg.getSum(s - 1, s) << "\n";
    }
  }
  return 0;
}