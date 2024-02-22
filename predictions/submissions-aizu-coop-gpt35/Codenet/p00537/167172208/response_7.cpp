#include <cstdio>

struct SegmentTree {
  int* seg;
  int* add;
  int sz;

  SegmentTree(int n) {
    sz = 1;
    while (sz < n)
      sz *= 2;
    seg = new int[sz * 2 + 1];
    add = new int[sz * 2 + 1];
    for (int i = 0; i < sz * 2 + 1; i++) {
      seg[i] = 0;
      add[i] = 0;
    }
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
      seg[k] = seg[2 * k + 1] + add[2 * k + 1] + seg[2 * k + 2] + add[2 * k + 2];
    }
  }

  int Query(int a, int b, int k, int l, int r) {
    if (a >= r || b <= l)
      return 0;
    if (a <= l && r <= b)
      return seg[k] + add[k];
    int mid = (l + r) / 2;
    return Query(a, b, 2 * k + 1, l, mid) + Query(a, b, 2 * k + 2, mid, r) + add[k];
  }

  void Add(int a, int b, int x) { Add(a, b, x, 0, 0, sz); }

  int Query(int a, int b) { return Query(a, b, 0, 0, sz); }

  ~SegmentTree() {
    delete[] seg;
    delete[] add;
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
    int u = (P[i - 1] < P[i] ? P[i - 1] : P[i]);
    int v = (P[i - 1] < P[i] ? P[i] : P[i - 1]);
    segtree.Add(u, v, 1);
  }
  long long ret = 0;
  for (int i = 0; i < N - 1; i++) {
    long long used = segtree.Query(i, i + 1);
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    ret += (used * A < C + used * B ? used * A : C + used * B);
  }
  printf("%lld\n", ret);

  return 0;
}