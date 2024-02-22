#include <bits/stdc++.h>
using namespace std;
struct SegmentTree {
  vector<int> seg, add;
  int sz;
  SegmentTree(int n) {
    sz = 1;
    while (sz < n)
      sz *= 2;
    seg.assign(sz * 2 + 1, 0), add.assign(sz * 2 + 1, 0);
  }
  void Add(int a, int b, int x, int k, int l, int r) {
    if (__builtin_expect((a >= r || b <= l), 0)) {
      return;
    } else if (__builtin_expect((a <= l && r <= b), 0)) {
      add[k] += x;
    } else {
      Add(a, b, x, 2 * k + 1, l, (l + r) / 2);
      Add(a, b, x, 2 * k + 2, (l + r) / 2, r);
      seg[k] =
          seg[2 * k + 1] + add[2 * k + 1] + seg[2 * k + 2] + add[2 * k + 2];
    }
  }
  int Query(int a, int b, int k, int l, int r) {
    if (__builtin_expect((a <= l && r <= b), 1))
      return (seg[k] + add[k]);
    if (__builtin_expect((a >= r || b <= l), 0))
      return 0;
    return (Query(a, b, 2 * k + 1, l, (l + r) / 2) +
            Query(a, b, 2 * k + 2, (l + r) / 2, r) + add[k]);
  }
  void Add(int a, int b, int x) { Add(a, b, x, 0, 0, sz); }
  int Query(int a, int b) { return (Query(a, b, 0, 0, sz)); }
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
  for (int i = 0; i < N - 1; i+= 2) {
    long long used1 = segtree.Query(i, i + 1);
    long long used2 = i + 1 < N - 1 ? segtree.Query(i+1, i + 2) : 0;
    int A1, B1, C1, A2, B2, C2;
    scanf("%d %d %d", &A1, &B1, &C1);
    if (i + 1 < N - 1)
        scanf("%d %d %d", &A2, &B2, &C2);
    ret += min(used1 * A1, C1 + used1 * B1);
    if (i + 1 < N - 1)
        ret += min(used2 * A2, C2 + used2 * B2);
  }
  cout << ret << endl;
}