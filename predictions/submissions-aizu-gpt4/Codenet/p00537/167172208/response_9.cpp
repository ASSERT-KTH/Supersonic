#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
struct SegmentTree {
  vector<int> seg, add;
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
    if (a >= r || b <= l) return 0;
    int res = add[k] * (min(b, r) - max(a, l));
    if (a <= l && r <= b) res += seg[k];
    else {
      int mid = (l + r) / 2;
      res += Query(a, b, 2 * k + 1, l, mid) + Query(a, b, 2 * k + 2, mid, r);
    }
    return res;
  }
  SegmentTree(int n) {
    int sz = 1;
    while (sz < n) sz *= 2;
    seg.resize(sz * 2 - 1);
    add.assign(sz * 2 - 1, 0);
  }
  void Add(int a, int b, int x) { Add(a, b, x, 0, 0, seg.size() / 2 + 1); }
  int Query(int a, int b) { return Query(a, b, 0, 0, seg.size() / 2 + 1); }
};
int main() {
  int N, M;
  scanf("%d %d", &N, &M);
  vector<int> P(M);
  SegmentTree segtree(N);
  for (int i = 0; i < M; ++i) {
    scanf("%d", &P[i]);
    --P[i];
    if (i > 0) segtree.Add(min(P[i - 1], P[i]), max(P[i - 1], P[i]), 1);
  }
  long long ret = 0;
  for (int i = 0; i < N - 1; ++i) {
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    long long used = segtree.Query(i, i + 1);
    ret += min(used * A, C + used * B);
  }
  printf("%lld\n", ret);
  return 0;
}