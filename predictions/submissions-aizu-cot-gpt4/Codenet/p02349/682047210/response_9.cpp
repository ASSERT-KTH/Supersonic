#include <cstdio>
#include <vector>

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
    node.reserve(2 * N - 1);
    lazy.reserve(2 * N - 1);
  }
  void build(vector<Monoid> &v) {
    int sz = int(v.size());
    init(sz);
    for (int i = 0; i < sz; i++) {
      node[i + N - 1] = v[i];
    }
    for (int i = N - 2; i >= 0; i--) {
      node[i] = node[(i << 1) + 1] + node[(i << 1) + 2];
    }
  }
  void eval(int k) {
    if (lazy[k] != 0) {
      node[k] += lazy[k];
      if (k < N - 1) {
        lazy[(k << 1) + 1] += lazy[k] >> 1;
        lazy[(k << 1) + 2] += lazy[k] >> 1;
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
      add(a, b, x, (k << 1) + 1, l, (l + r) >> 1);
      add(a, b, x, (k << 1) + 2, (l + r) >> 1, r);
      node[k] = node[(k << 1) + 1] + node[(k << 1) + 2];
    }
  }
  Monoid getSum(int a, int b) { return getSum(a, b, 0, 0, N); }
  Monoid getSum(int a, int b, int k, int l, int r) {
    if (b <= l || r <= a)
      return 0;
    eval(k);
    if (a <= l && r <= b)
      return node[k];
    Monoid vl, vr;
    vl = getSum(a, b, (k << 1) + 1, l, (l + r) >> 1);
    vr = getSum(a, b, (k << 1) + 2, (l + r) >> 1, r);
    return vl + vr;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, q;
  scanf("%d %d", &n, &q);
  
  LazySegmentTree<ll> seg(n);
  
  for (int i = 0; i < q; i++) {
    int c;
    scanf("%d", &c);
    if (c == 0) {
      ll s, t, x;
      scanf("%lld %lld %lld", &s, &t, &x);
      seg.add(s - 1, t, x);
    } else {
      int s;
      scanf("%d", &s);
      printf("%lld\n", seg.getSum(s - 1, s));
    }
  }
  return 0;
}