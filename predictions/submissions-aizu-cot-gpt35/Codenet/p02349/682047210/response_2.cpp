#include <iostream>
#include <vector>

template <typename Monoid>
struct LazySegmentTree {
private:
  int N;
  std::vector<Monoid> node, lazy;

public:
  LazySegmentTree(int sz = 0) { init(sz); }
  void init(int sz) {
    N = 1;
    while (N < sz)
      N <<= 1;
    node.resize(2 * N - 1, 0);
    lazy.resize(2 * N - 1, 0);
  }
  void build(const std::vector<Monoid> &v) {
    int sz = int(v.size());
    init(sz);
    std::copy(v.begin(), v.end(), node.begin() + N - 1);
    for (int i = N - 2; i >= 0; --i) {
      node[i] = node[i * 2 + 1] + node[i * 2 + 2];
    }
  }
  void eval(int k) {
    if (lazy[k] != 0) {
      node[k] += lazy[k];
      if (k < N - 1) {
        lazy[2 * k + 1] += lazy[k] / 2;
        lazy[2 * k + 2] += lazy[k] / 2;
      }
      lazy[k] = 0;
    }
  }
  void add(int a, int b, Monoid x) { add(a, b, x, 0, 0, N); }
  void add(int a, int b, Monoid x, int k, int l, int r) {
    eval(k);
    if (b <= l || r <= a)
      return;
    if (a <= l && r <= b) {
      lazy[k] += x * (r - l);
    } else {
      int m = (l + r) / 2;
      add(a, b, x, 2 * k + 1, l, m);
      add(a, b, x, 2 * k + 2, m, r);
    }
  }
  Monoid getSum(int a, int b) { return getSum(a, b, 0, 0, N); }
  Monoid getSum(int a, int b, int k, int l, int r) {
    if (b <= l || r <= a)
      return 0;
    eval(k);
    if (a <= l && r <= b)
      return node[k];
    int m = (l + r) / 2;
    Monoid vl = getSum(a, b, 2 * k + 1, l, m);
    Monoid vr = getSum(a, b, 2 * k + 2, m, r);
    return vl + vr;
  }
};

int main() {
  int n, q;
  std::cin >> n >> q;
  LazySegmentTree<long long> seg(n);
  for (int i = 0; i < q; ++i) {
    int c;
    std::cin >> c;
    if (c == 0) {
      long long s, t, x;
      std::cin >> s >> t >> x;
      seg.add(s - 1, t, x);
    } else {
      int s;
      std::cin >> s;
      std::cout << seg.getSum(s - 1, s) << std::endl;
    }
  }
}