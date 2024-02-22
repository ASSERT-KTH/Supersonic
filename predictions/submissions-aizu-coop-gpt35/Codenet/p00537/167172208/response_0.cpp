#include <iostream>
#include <vector>

struct SegmentTree {
  std::vector<int> tree;
  int sz;
  SegmentTree(int n) {
    sz = 1;
    while (sz < n)
      sz *= 2;
    tree.assign(sz * 2 + 1, 0);
  }

  void update(int a, int b, int x, int k, int l, int r) {
    if (a >= r || b <= l) {
      return;
    } else if (a <= l && r <= b) {
      tree[k] += x;
    } else {
      int mid = (l + r) / 2;
      update(a, b, x, 2 * k + 1, l, mid);
      update(a, b, x, 2 * k + 2, mid, r);
      tree[k] = tree[2 * k + 1] + tree[2 * k + 2];
    }
  }

  int query(int a, int b, int k, int l, int r, int add) {
    if (a >= r || b <= l)
      return 0;
    if (a <= l && r <= b)
      return tree[k] + add * (r - l);
    int mid = (l + r) / 2;
    return query(a, b, 2 * k + 1, l, mid, add + tree[k]) +
           query(a, b, 2 * k + 2, mid, r, add + tree[k]);
  }

  void update(int a, int b, int x) { update(a, b, x, 0, 0, sz); }

  int query(int a, int b) { return query(a, b, 0, 0, sz, 0); }
};

int main() {
  int N, M, P[100000];
  std::cin >> N >> M;
  SegmentTree segtree(N);
  for (int i = 0; i < M; i++) {
    std::cin >> P[i];
    --P[i];
  }
  for (int i = 1; i < M; i++) {
    int u = std::min(P[i - 1], P[i]), v = std::max(P[i - 1], P[i]);
    segtree.update(u, v, 1);
  }
  long long ret = 0;
  int used = segtree.query(0, 1);
  for (int i = 0; i < N - 1; i++) {
    int A, B, C;
    std::cin >> A >> B >> C;
    ret += std::min(1LL * used * A, 1LL * C + used * B);
  }
  std::cout << ret << std::endl;
}