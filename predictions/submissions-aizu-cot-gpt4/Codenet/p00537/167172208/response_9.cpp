#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct SegmentTree {
  vector<int> seg, add;
  int sz;

  SegmentTree(int n) {
    sz = 1;
    while (sz < n) sz *= 2;
    seg.assign(sz * 2 + 1, 0), add.assign(sz * 2 + 1, 0);
  }

  void Add(int a, int b, int x, int k, int l, int r) {
    if (a >= r || b <= l) return;
    if (a <= l && r <= b) {
      add[k] += x;
    } else {
      int mid = (l + r) / 2;
      int k1 = 2 * k + 1;
      int k2 = 2 * k + 2;
      Add(a, b, x, k1, l, mid);
      Add(a, b, x, k2, mid, r);
      seg[k] = seg[k1] + add[k1] + seg[k2] + add[k2];
    }
  }

  int Query(int a, int b, int k, int l, int r) {
    if (a >= r || b <= l) return 0;
    if (a <= l && r <= b) return seg[k] + add[k];
    int mid = (l + r) / 2;
    return Query(a, b, 2 * k + 1, l, mid) +
           Query(a, b, 2 * k + 2, mid, r) + add[k];
  }

  void Add(int a, int b, int x) { Add(a, b, x, 0, 0, sz); }
  int Query(int a, int b) { return Query(a, b, 0, 0, sz); }
};

int main() {
  int N, M, P[100000];
  scanf("%d %d", &N, &M);
  SegmentTree segtree(N);
  for (int i = 0; i < M; i++) {
    scanf("%d", &P[i]);
    --P[i];
  }
  for (int i = 1; i < M; i++) {
    int u = min(P[i - 1], P[i]), v = max(P[i - 1], P[i]);
    segtree.Add(u, v, 1);
  }
  long long ret = 0;
  for (int i = 0; i < N - 1; i++) {
    long long used = segtree.Query(i, i + 1);
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    ret += min(used * A, C + used * B);
  }
  printf("%lld\n", ret);
  return 0;
}