#include <iostream>
#include <vector>

#define ll long long

template <typename Monoid>
struct LazySegmentTree {
private:
  size_t N;
  std::vector<Monoid> node, lazy;

public:
  LazySegmentTree(size_t sz = 0) { init(sz); }
  
  void init(size_t sz) {
    N = 1;
    while (N < sz)
      N *= 2;
    node.resize(2 * N - 1);
    lazy.resize(2 * N - 1);
  }
  
  void build(const std::vector<Monoid> &v) {
    size_t sz = v.size();
    init(sz);
    for (size_t i = 0; i < sz; i++) {
      node[i + N - 1] = v[i];
    }
    for (size_t i = N - 2; i >= 0; i--) {
      node[i] = node[i * 2 + 1] + node[i * 2 + 2];
    }
  }
  
  void eval(size_t k) {
    if (lazy[k] != 0) {
      node[k] += lazy[k];
      if (k < N - 1) {
        lazy[2 * k + 1] += lazy[k] / 2;
        lazy[2 * k + 2] += lazy[k] / 2;
      }
      lazy[k] = 0;
    }
  }
  
  void add(size_t a, size_t b, Monoid x) { add(a, b, x, 0, 0, N); }
  
  void add(size_t a, size_t b, Monoid x, size_t k, size_t l, size_t r) {
    eval(k);
    if (b <= l || r <= a)
      return;
    if (a <= l && r <= b) {
      lazy[k] += x * (r - l);
    } else {
      size_t mid = (l + r) / 2;
      add(a, b, x, 2 * k + 1, l, mid);
      add(a, b, x, 2 * k + 2, mid, r);
      node[k] = node[2 * k + 1] + node[2 * k + 2];
    }
  }
  
  Monoid getSum(size_t a, size_t b) { return getSum(a, b, 0, 0, N); }
  
  Monoid getSum(size_t a, size_t b, size_t k, size_t l, size_t r) {
    if (b <= l || r <= a)
      return 0;
    eval(k);
    if (a <= l && r <= b)
      return node[k];
    size_t mid = (l + r) / 2;
    Monoid vl = getSum(a, b, 2 * k + 1, l, mid);
    Monoid vr = getSum(a, b, 2 * k + 2, mid, r);
    return vl + vr;
  }
};

int main() {
  size_t n, q;
  std::cin >> n >> q;
  LazySegmentTree<ll> seg(n);
  for (size_t i = 0; i < q; i++) {
    int c;
    std::cin >> c;
    if (c == 0) {
      ll s, t, x;
      std::cin >> s >> t >> x;
      seg.add(s - 1, t, x);
    } else {
      size_t s;
      std::cin >> s;
      std::cout << seg.getSum(s - 1, s) << '\n';
    }
  }
  return 0;
}