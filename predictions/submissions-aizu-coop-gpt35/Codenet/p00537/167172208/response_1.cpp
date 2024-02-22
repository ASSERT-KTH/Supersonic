#include <iostream>
#include <array>

struct SegmentTree {
  std::array<int, MAX_SIZE> seg, add;
  int sz;
  
  SegmentTree(int n) {
    sz = 1;
    while (sz < n)
      sz *= 2;
    seg.fill(0);
    add.fill(0);
  }
  
  void Add(int a, int b, int x, int k, int l, int r) {
    if (a <= l && r <= b) {
      add[k] += x;
      return;
    }
    int mid = (l + r) / 2;
    if (a < mid) {
      Add(a, b, x, 2 * k + 1, l, mid);
    }
    if (b > mid) {
      Add(a, b, x, 2 * k + 2, mid, r);
    }
    seg[k] = seg[2 * k + 1] + add[2 * k + 1] + seg[2 * k + 2] + add[2 * k + 2];
  }
  
  int Query(int a, int b, int k, int l, int r) {
    if (a >= r || b <= l)
      return 0;
    if (a <= l && r <= b)
      return seg[k] + add[k];
    int mid = (l + r) / 2;
    return Query(a, b, 2 * k + 1, l, mid) +
           Query(a, b, 2 * k + 2, mid, r) +
           add[k];
  }
  
  void Add(int a, int b, int x) {
    Add(a, b, x, 0, 0, sz);
  }
  
  int Query(int a, int b) {
    return Query(a, b, 0, 0, sz);
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int N, M, P[MAX_SIZE];
  std::cin >> N >> M;
  
  SegmentTree segtree(N);
  
  for (int i = 0; i < M; i++) {
    std::cin >> P[i];
    --P[i];
  }
  
  for (int i = 1; i < M; i++) {
    int u = std::min(P[i - 1], P[i]);
    int v = std::max(P[i - 1], P[i]);
    segtree.Add(u, v, 1);
  }
  
  long long ret = 0;
  int used = 0;
  
  for (int i = 0; i < N - 1; i++) {
    used = segtree.Query(i, i + 1);
    int A, B, C;
    std::cin >> A >> B >> C;
    ret += std::min(static_cast<long long>(used) * A, C + static_cast<long long>(used) * B);
  }
  
  std::cout << ret << std::endl;
  
  return 0;
}