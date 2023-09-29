#include <vector>
#include <algorithm>
#include <cstdio>

struct SegmentTree {
  std::vector<int> seg, add;
  int sz;
  SegmentTree(int n) {
    sz = 1;
    while (sz < n)
      sz *= 2;
    seg.assign(2 * sz, 0), add.assign(2 * sz, 0);
  }
  void Add(int a, int b, int x, int k, int l, int r) {
    if (a >= r || b <= l) {
      return;
    } else if (a <= l && r <= b) {
      add[k] += x;
    } else {
      int mid = (l + r) / 2;
      Add(a, b, x, 2 * k + 1, l, mid);
      Add(a, b, x, 2 * k + 2, mid, r);
      seg[k] = seg[2 * k + 1] + add[2 * k + 1] * (mid - l) + seg[2 * k + 2] + add[2 * k + 2] * (r - mid);
    }
  }
  int Query(int a, int b, int k, int l, int r) {
    if (a >= r || b <= l)
      return 0;
    int res = add[k] * (std::min(r, b) - std::max(l, a));
    if (a <= l && r <= b)
      res += seg[k];
    else {
      int mid = (l + r) / 2;
      res += Query(a, b, 2 * k + 1, l, mid) + Query(a, b, 2 * k + 2, mid, r);
    }
    return res;
  }
  void Add(int a, int b, int x) { Add(a, b, x, 0, 0, sz); }
  int Query(int a, int b) { return Query(a, b, 0, 0, sz); }
};

int main() {
  int N, M, P[100000];
  std::scanf("%d %d", &N, &M);
  SegmentTree segtree(N);
  for (int i = 0; i < M; i++) {
    std::scanf("%d", &P[i]);
    --P[i];
  }
  for (int i = 1; i < M; i++) {
    int u = std::min(P[i - 1], P[i]), v = std::max(P[i - 1], P[i]);
    segtree.Add(u, v, 1);
  }
  long long ret = 0;
  for (int i = 0; i < N - 1; i++) {
    long long used = segtree.Query(i, i + 1);
    int A, B, C;
    std::scanf("%d %d %d", &A, &B, &C);
    ret += std::min(used * A, C + used * B);
  }
  std::printf("%lld\n", ret);
  return 0;
}