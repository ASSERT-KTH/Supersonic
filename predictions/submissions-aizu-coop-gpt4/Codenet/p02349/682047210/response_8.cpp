#include <vector>
#include <iostream>
using namespace std;
typedef long long ll;
template <typename Monoid>
struct LazySegmentTree {
private:
  int N;
  vector<Monoid> node, lazy;

public:
  LazySegmentTree(int sz = 0) { init(sz); }
  void init(int sz) {
    N = 1;
    while (N < sz)
      N <<= 1;
    node.reserve(2 * N - 1);
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
  void add(int a, int b, Monoid x) {
    int l = 0, r = N, k = 0;
    while (l < r) {
      eval(k);
      if (b <= l || r <= a)
        return;
      if (a <= l && r <= b) {
        lazy[k] += x * (r - l);
      } else {
        int m = (l + r) / 2;
        add(a, b, x, 2 * k + 1, l, m);
        add(a, b, x, 2 * k + 2, m, r);
        node[k] = node[2 * k + 1] + node[2 * k + 2];
        l = m;
      }
      k = 2 * k + 1;
    }
    eval(k);
  }
  Monoid getSum(int a, int b) {
    int l = 0, r = N, k = 0;
    Monoid res = 0;
    while (l < r) {
      eval(k);
      if (b <= l || r <= a)
        return 0;
      if (a <= l && r <= b)
        return node[k];
      int m = (l + r) / 2;
      if (a < m)
        res += getSum(a, b, 2 * k + 1, l, m);
      if (m < b)
        res += getSum(a, b, 2 * k + 2, m, r);
      l = m;
      k = 2 * k + 1;
    }
    eval(k);
    return res;
  }
};
int main() {
  int n, q;
  cin >> n >> q;
  LazySegmentTree<ll> seg(n);
  for (int i = 0; i < q; i++) {
    int c;
    cin >> c;
    if (c == 0) {
      ll s, t, x;
      cin >> s >> t >> x;
      seg.add(s - 1, t, x);
    } else {
      int s;
      cin >> s;
      cout << seg.getSum(s - 1, s) << endl;
    }
  }
  return 0;
}