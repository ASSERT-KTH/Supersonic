#include <iostream>
#include <vector>
using namespace std;

struct SegmentTree {
  vector<long long> seg, add;
  int sz;

  SegmentTree(int n) {
    sz = 1;
    while (sz < n)
      sz *= 2;
    seg.assign(sz * 2 + 1, 0);
    add.assign(sz * 2 + 1, 0);
  }

  void Add(int a, int b, int x, int k, int l, int r) {
    if (a >= r || b <= l) {
      return;
    }
    if (a <= l && r <= b) {
      add[k] += x;
      return;
    }
    int m = (l + r) / 2;
    Add(a, b, x, 2 * k + 1, l, m);
    Add(a, b, x, 2 * k + 2, m, r);
    seg[k] = seg[2 * k + 1] + add[2 * k + 1] + seg[2 * k + 2] + add[2 * k + 2];
  }

  int Query(int a, int b, int k, int l, int r) {
    if (a >= r || b <= l) {
      return 0;
    }
    if (a <= l && r <= b) {
      return seg[k] + add[k];
    }
    int m = (l + r) / 2;
    return Query(a, b, 2 * k + 1, l, m) +
           Query(a, b, 2 * k + 2, m, r) + add[k];
  }

  void Add(int a, int b, int x) {
    Add(a, b, x, 0, 0, sz);
  }

  int Query(int a, int b) {
    return Query(a, b, 0, 0, sz);
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
  int ret = 0;
  for (int i = 0; i < N - 1; i++) {
    int used = segtree.Query(i, i + 1);
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    ret += min(used * A, C + used * B);
  }
  cout << ret << endl;
}