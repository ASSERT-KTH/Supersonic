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
  void build(std::vector<Monoid> v) {
    int sz = int(v.size());
    init(sz);
    std::copy(v.begin(), v.end(), node.begin() + N - 1);
    for (int i = N - 2; i >= 0; i--) {
      node[i] = node[i * 2 + 1] + node[i * 2 + 2];
    }
  }
  void add(int a, int b, Monoid x) { add(a, b, x, 0, 0, N); }
  void add(int a, int b, Monoid x, int k, int l, int r) {
    if (b <= l || r <= a)
      return;
    if (a <= l && r <= b) {
      lazy[k] += x * (r - l);
    } else {
      add(a, b, x, 2 * k + 1, l, (l + r) / 2);
      add(a, b, x, 2 * k + 2, (l + r) / 2, r);
      node[k] = node[2 * k + 1] + node[2 * k + 2];
    }
  }
  Monoid getSum(int a, int b) { return getSum(a, b, 0, 0, N); }
  Monoid getSum(int a, int b, int k, int l, int r) {
    if (b <= l || r <= a)
      return 0;
    if (a <= l && r <= b) {
      return node[k];
    }
    int mid = (l + r) / 2;
    return getSum(a, b, 2 * k + 1, l, mid) + getSum(a, b, 2 * k + 2, mid, r);
  }
};

int main() {
  int n, q;
  std::cin >> n >> q;
  LazySegmentTree<long long> seg(n);
  for (int i = 0; i < q; i++) {
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
  return 0;
}