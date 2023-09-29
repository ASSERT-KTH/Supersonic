#include <iostream>
#include <vector>
#include <algorithm>

struct SegmentTree {
  std::vector<int> seg, add;
  int sz;
  SegmentTree(int n) : sz(1), seg(n * 4, 0), add(n * 4, 0) {
    while (sz < n) sz *= 2;
  }
  void Add(int a, int b, int x, int k, int l, int r) {
    if (a >= r || b <= l) return;
    if (a <= l && r <= b) {
      add[k] += x;
    } else {
      int mid = (l + r) / 2;
      Add(a, b, x, 2 * k + 1, l, mid);
      Add(a, b, x, 2 * k + 2, mid, r);
      seg[k] = seg[2 * k + 1] + add[2 * k + 1] * (mid - l) + seg[2 * k + 2] + add[2 * k + 2] * (r - mid);
    }
  }
  int Query(int a, int b, int k, int l, int r) {
    if (a >= r || b <= l) return 0;
    int res = (min(b, r) - max(a, l)) * add[k];
    if (a <= l && r <= b) {
      res += seg[k];
    } else {
      int mid = (l + r) / 2;
      res += Query(a, b, 2 * k + 1, l, mid) + Query(a, b, 2 * k + 2, mid, r);
    }
    return res;
  }
  void Add(int a, int b, int x) { Add(a, b, x, 0, 0, sz); }
  int Query(int a, int b) { return Query(a, b, 0, 0, sz); }
};

int main() {
  int N, M;
  std::cin >> N >> M;
  std::vector<int> P(M);
  SegmentTree segtree(N);
  for (int i = 0; i < M; i++) {
    std::cin >> P[i];
    --P[i];
  }
  for (int i = 1; i < M; i++) {
    segtree.Add(std::min(P[i - 1], P[i]), std::max(P[i - 1], P[i]), 1);
  }
  long long ret = 0;
  for (int i = 0; i < N - 1; i++) {
    long long used = segtree.Query(i, i + 1);
    int A, B, C;
    std::cin >> A >> B >> C;
    ret += std::min(used * A, C + used * B);
  }
  std::cout << ret << '\n';
  return 0;
}