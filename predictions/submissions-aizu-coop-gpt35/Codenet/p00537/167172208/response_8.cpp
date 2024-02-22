#include <iostream>
#include <vector>
using namespace std;

struct SegmentTree {
  vector<int> tree;
  int sz;

  SegmentTree(int n) {
    sz = 1;
    while (sz < n)
      sz *= 2;
    tree.assign(sz * 2 + 1, 0);
  }

  void add(int a, int b, int x, int k, int l, int r) {
    if (a >= r || b <= l) {
      return;
    } else if (a <= l && r <= b) {
      tree[k] += x;
    } else {
      int mid = (l + r) / 2;
      add(a, b, x, 2 * k + 1, l, mid);
      add(a, b, x, 2 * k + 2, mid, r);
      tree[k] = tree[2 * k + 1] + tree[2 * k + 2]; // Removed unnecessary additions
    }
  }

  int query(int a, int b, int k, int l, int r) {
    if (a >= r || b <= l)
      return 0;
    if (a <= l && r <= b)
      return tree[k];
    int mid = (l + r) / 2;
    return query(a, b, 2 * k + 1, l, mid) +
           query(a, b, 2 * k + 2, mid, r); // Removed unnecessary additions
  }

  void add(int a, int b, int x) { add(a, b, x, 0, 0, sz); }

  int query(int a, int b) { return query(a, b, 0, 0, sz); }
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
    segtree.add(u, v, 1);
  }

  long long ret = 0;
  for (int i = 0; i < N - 1; i++) {
    long long used = segtree.query(i, i + 1);
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    ret += min(used * A, C + used * B);
  }
  cout << ret << endl;
}