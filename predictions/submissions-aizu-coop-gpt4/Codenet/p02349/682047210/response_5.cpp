#include <iostream>
#include <vector>
typedef long long ll;

struct LazySegmentTree {
private:
  int N;
  std::vector<ll> node, lazy;

public:
  LazySegmentTree(int sz = 0) { init(sz); }
  void init(int sz) {
    N = 1;
    while (N < sz)
      N <<= 1;
    node.resize(2 * N - 1, 0);
    lazy.resize(2 * N - 1, 0);
  }

  void eval(int k, int l, int r) {
    if (lazy[k] != 0) {
      node[k] += lazy[k];
      if (k < N - 1) {
        lazy[2 * k + 1] += lazy[k];
        lazy[2 * k + 2] += lazy[k];
      }
      lazy[k] = 0;
    }
  }

  void add(int a, int b, ll x) { add(a, b, x, 0, 0, N); }
  void add(int a, int b, ll x, int k, int l, int r) {
    eval(k, l, r);
    if (b <= l || r <= a)
      return;
    if (a <= l && r <= b) {
      lazy[k] += x * (r - l);
      eval(k, l, r);
    } else {
      int m = (l + r) / 2;
      add(a, b, x, 2 * k + 1, l, m);
      add(a, b, x, 2 * k + 2, m, r);
      node[k] = node[2 * k + 1] + node[2 * k + 2];
    }
  }

  ll getSum(int a, int b) { return getSum(a, b, 0, 0, N); }
  ll getSum(int a, int b, int k, int l, int r) {
    if (b <= l || r <= a)
      return 0;
    eval(k, l, r);
    if (a <= l && r <= b)
      return node[k];
    int m = (l + r) / 2;
    ll vl = getSum(a, b, 2 * k + 1, l, m);
    ll vr = getSum(a, b, 2 * k + 2, m, r);
    return vl + vr;
  }
};

int main() {
  int n, q;
  std::cin >> n >> q;
  LazySegmentTree seg(n);
  for (int i = 0; i < q; i++) {
    int c;
    std::cin >> c;
    if (c == 0) {
      ll s, t, x;
      std::cin >> s >> t >> x;
      seg.add(s - 1, t, x);
    } else {
      int s;
      std::cin >> s;
      std::cout << seg.getSum(s - 1, s) << std::endl;
    }
  }
  return 0;
}