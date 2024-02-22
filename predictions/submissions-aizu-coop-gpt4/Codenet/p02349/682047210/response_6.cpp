#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node {
    ll node, lazy;
    Node() : node(0), lazy(0) {}
};

template <typename Monoid> struct LazySegmentTree {
private:
  int N;
  vector<Node> tree;

public:
  LazySegmentTree(int sz = 0) { init(sz); }
  void init(int sz) {
    N = 1;
    while (N < sz)
      N <<= 1;
    tree.resize(2 * N - 1);
  }
  void build(vector<Monoid> &v) {
    int sz = int(v.size());
    init(sz);
    for (int i = 0; i < sz; i++) {
      tree[i + N - 1].node = v[i];
    }
    for (int i = N - 2; i >= 0; i--) {
      tree[i].node = tree[2 * i + 1].node + tree[2 * i + 2].node;
    }
  }
  void eval(int k) {
    if (tree[k].lazy != 0) {
      tree[k].node += tree[k].lazy;
      if (k < N - 1) {
        tree[2 * k + 1].lazy += tree[k].lazy / 2;
        tree[2 * k + 2].lazy += tree[k].lazy / 2;
      }
      tree[k].lazy = 0;
    }
  }
  void add(int a, int b, Monoid x) { add(a, b, x, 0, 0, N); }
  void add(int a, int b, Monoid x, int k, int l, int r) {
    eval(k);
    if (b <= l || r <= a)
      return;
    if (a <= l && r <= b) {
      tree[k].lazy += x * (r - l);
    } else {
      int mid = (l + r) / 2;
      int kk = 2 * k;
      add(a, b, x, kk + 1, l, mid);
      add(a, b, x, kk + 2, mid, r);
      tree[k].node = tree[kk + 1].node + tree[kk + 2].node;
    }
  }
  Monoid getSum(int a, int b) { return getSum(a, b, 0, 0, N); }
  Monoid getSum(int a, int b, int k, int l, int r) {
    if (b <= l || r <= a)
      return 0;
    eval(k);
    if (a <= l && r <= b)
      return tree[k].node;
    int mid = (l + r) / 2;
    int kk = 2 * k;
    Monoid vl = getSum(a, b, kk + 1, l, mid);
    Monoid vr = getSum(a, b, kk + 2, mid, r);
    return vl + vr;
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