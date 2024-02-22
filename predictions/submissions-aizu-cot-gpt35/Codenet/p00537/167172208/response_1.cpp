#include <iostream>
#include <vector>
using namespace std;

struct SegmentTree {
  vector<int> seg, add;
  int sz;
  SegmentTree(int n) {
    sz = 1;
    while (sz < n)
      sz *= 2;
    seg.assign(sz * 2 + 1, 0);
    add.assign(sz * 2 + 1, 0);
  }
  void Add(int a, int b, int x, int k, int l, int r) {
    seg[k] += (b - a) * x;
    if (a + 1 != b) {
      add[2 * k + 1] += x;
      add[2 * k + 2] += x;
    }
    else if (a < r) {
      seg[k] += add[k];
      add[k] = 0;
    }
    if (a >= r || b <= l) {
      return;
    }
    else if (a <= l && r <= b) {
      add[k] += x;
      return;
    }
    int m = (l + r) / 2;
    Add(a, b, x, 2 * k + 1, l, m);
    Add(a, b, x, 2 * k + 2, m, r);
  }
  int Query(int a, int b, int k, int l, int r) {
    if (a >= r || b <= l)
      return (0);
    seg[k] += (r - l) * add[k];
    if (a <= l && r <= b) {
      return (seg[k]);
    }
    int m = (l + r) / 2;
    int res = Query(a, b, 2 * k + 1, l, m) + Query(a, b, 2 * k + 2, m, r);
    seg[k] = seg[2 * k + 1] + seg[2 * k + 2] + (r - l) * add[k];
    return res;
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
  int used = segtree.Query(0, 1);
  for (int i = 1; i < N - 1; i++) {
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    ret += min((long long)used * A, C + (long long)used * B);
    used += segtree.Query(i, i + 1);
  }
  cout << ret << endl;
}