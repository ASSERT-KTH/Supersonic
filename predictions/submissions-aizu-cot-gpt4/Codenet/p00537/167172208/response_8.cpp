#include <bits/stdc++.h>
using namespace std;
struct SegmentTree {
  vector<int> seg, add;
  int sz;
  SegmentTree(int n) {
    sz = 1;
    while (sz < n)
      sz <<= 1;
    seg.assign(sz * 2 + 1, 0), add.assign(sz * 2 + 1, 0);
  }
  void Add(int a, int b, int x, int k, int l, int r) {
    if (a >= r || b <= l) {
      return;
    } else if (a <= l && r <= b) {
      add[k] += x;
    } else {
      int mid = (l + r) >> 1;
      int k1 = k << 1;
      Add(a, b, x, k1 + 1, l, mid);
      Add(a, b, x, k1 + 2, mid, r);
      seg[k] = seg[k1 + 1] + add[k1 + 1] + seg[k1 + 2] + add[k1 + 2];
    }
  }
  int Query(int a, int b, int k, int l, int r) {
    if (a >= r || b <= l)
      return (0);
    if (a <= l && r <= b)
      return (seg[k] + add[k]);
    int mid = (l + r) >> 1;
    int k1 = k << 1;
    return (Query(a, b, k1 + 1, l, mid) +
            Query(a, b, k1 + 2, mid, r) + add[k]);
  }
  void Add(int a, int b, int x) { Add(a, b, x, 0, 0, sz); }
  int Query(int a, int b) { return (Query(a, b, 0, 0, sz)); }
};

int scan() {
  int n = 0, ch = getchar_unlocked();
  while (ch < '0' || ch > '9') ch = getchar_unlocked();
  while (ch >= '0' && ch <= '9') {
    n = (n << 3) + (n << 1) + ch - '0';
    ch = getchar_unlocked();
  }
  return n;
}

int main() {
  int N = scan(), M = scan(), P[100000];
  SegmentTree segtree(N);
  for (int i = 0; i < M; i++) {
    P[i] = scan();
    --P[i];
  }
  for (int i = 1; i < M; i++) {
    int u = min(P[i - 1], P[i]), v = max(P[i - 1], P[i]);
    segtree.Add(u, v, 1);
  }
  long long ret = 0;
  for (int i = 0; i < N - 1; i++) {
    long long used = segtree.Query(i, i + 1);
    int A = scan(), B = scan(), C = scan();
    ret += min(used * A, C + used * B);
  }
  cout << ret << endl;
}