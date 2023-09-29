#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
  vector<int> seg, add;
  int sz;
  SegmentTree(int n) {
    sz = 1;
    while (sz < n) {
      sz *= 2;
    }
    seg.resize(sz * 2 + 1);
    add.resize(sz * 2 + 1);
  }
  void Add(int a, int b, int x, int k = 0, int l = 0, int r = -1) {
    if (r == -1) {
      r = sz;
    }
    if (a >= r || b <= l) {
      return;
    }
    if (a <= l && r <= b) {
      add[k] += x;
      return;
    }
    Add(a, b, x, 2 * k + 1, l, (l + r) / 2);
    Add(a, b, x, 2 * k + 2, (l + r) / 2, r);
    seg[k] =
        seg[2 * k + 1] + add[2 * k + 1] + seg[2 * k + 2] + add[2 * k + 2];
  }
  int Query(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r == -1) {
      r = sz;
    }
    if (a >= r || b <= l) {
      return 0;
    }
    if (a <= l && r <= b) {
      return seg[k] + add[k];
    }
    return Query(a, b, 2 * k + 1, l, (l + r) / 2) +
           Query(a, b, 2 * k + 2, (l + r) / 2, r) + add[k];
  }
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
  cout << ret << endl;
}
