#include <vector>
#include <iostream>

struct SegmentTree {
  std::vector<int> seg, add;
  int sz;
  
  SegmentTree(int n) {
    sz = 1;
    while (sz < n)
      sz *= 2;
    seg.reserve(sz * 2 + 1);
    add.resize(sz * 2 + 1);
  }
  
  void Add(int a, int b, int x, int k = 0, int l = 0, int r = -1) {
    if (r == -1) r = sz;
    if (a >= r || b <= l) {
      return;
    } else if (a <= l && r <= b) {
      add[k] += x;
    } else {
      int mid = (l + r) / 2;
      Add(a, b, x, 2 * k + 1, l, mid);
      Add(a, b, x, 2 * k + 2, mid, r);
      seg[k] = seg[2 * k + 1] + add[2 * k + 1] + seg[2 * k + 2] + add[2 * k + 2];
    }
  }
  
  int Query(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r == -1) r = sz;
    if (a >= r || b <= l)
      return 0;
    if (a <= l && r <= b)
      return seg[k] + add[k];
    int mid = (l + r) / 2;
    return Query(a, b, 2 * k + 1, l, mid) +
           Query(a, b, 2 * k + 2, mid, r) + add[k];
  }
  
  void Add(int a, int b, int x) { Add(a, b, x, 0, 0, sz); }
  
  int Query(int a, int b) { return Query(a, b, 0, 0, sz); }
};

int main() {
  int N, M;
  std::cin >> N >> M;
  
  SegmentTree segtree(N);
  
  std::vector<int> P(M);
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
  for (int i = 0; i < N - 1; i++) {
    long long used = segtree.Query(i, i + 1);
    int A, B, C;
    std::cin >> A >> B >> C;
    ret += used * std::min(A, B) + std::max(0LL, (used - 1) * B) + C;
  }
  
  std::cout << ret << std::endl;
}