#include <iostream>
#include <vector>

using ll = long long;

template <typename Monoid>
struct LazySegmentTree {
private:
  std::size_t N;
  std::vector<Monoid> node, lazy;

public:
  LazySegmentTree(std::size_t sz = 0) { init(sz); }
  void init(std::size_t sz) {
    N = 1;
    while (N < sz)
      N <<= 1;
    node.resize(2 * N - 1, 0);
    lazy.resize(2 * N - 1, 0);
  }
  void build(const std::vector<Monoid> &v) {
    N = v.size();
    node.resize(2 * N - 1);
    lazy.resize(2 * N - 1, 0);
    for (std::size_t i = 0; i < N; ++i) {
      node[i + N - 1] = v[i];
    }
    for (std::size_t i = N - 2; i < N; --i) {
      node[i] = node[i * 2 + 1] + node[i * 2 + 2];
    }
  }
  void eval(std::size_t k) {
    if (lazy[k] != 0) {
      node[k] += lazy[k];
      if (k < N - 1) {
        lazy[2 * k + 1] += lazy[k] / 2;
        lazy[2 * k + 2] += lazy[k] / 2;
      }
      lazy[k] = 0;
    }
  }
  void add(std::size_t a, std::size_t b, const Monoid &x) {
    add(a, b, x, 0, 0, N);
  }
  void add(std::size_t a, std::size_t b, const Monoid &x, std::size_t k,
           std::size_t l, std::size_t r) {
    eval(k);
    if (b <= l || r <= a)
      return;
    if (a <= l && r <= b) {
      lazy[k] += x * (r - l);
    }
    add(a, b, x, 2 * k + 1, l, (l + r) / 2);
    add(a, b, x, 2 * k + 2, (l + r) / 2, r);
    node[k] = node[2 * k + 1] + node[2 * k + 2];
  }
  Monoid getSum(std::size_t a, std::size_t b) { return getSum(a, b, 0, 0, N); }
  Monoid getSum(std::size_t a, std::size_t b, std::size_t k, std::size_t l,
                std::size_t r) {
    if (b <= l || r <= a)
      return 0;
    eval(k);
    if (a <= l && r <= b)
      return node[k];
    Monoid vl, vr;
    vl = getSum(a, b, 2 * k + 1, l, (l + r) / 2);
    vr = getSum(a, b, 2 * k + 2, (l + r) / 2, r);
    return vl + vr;
  }
};

int main() {
  std::size_t n, q;
  std::cin >> n >> q;
  LazySegmentTree<ll> seg(n);
  for (std::size_t i = 0; i < q; ++i) {
    int c;
    std::cin >> c;
    if (c == 0) {
      ll s, t, x;
      std::cin >> s >> t >> x;
      seg.add(s - 1, t, x);
    } else {
      std::size_t s;
      std::cin >> s;
      std::cout << seg.getSum(s - 1, s) << std::endl;
    }
  }
  return 0;
}