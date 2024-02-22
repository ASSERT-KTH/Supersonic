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
    tree.assign(sz * 2, 0);
  }
  
  void propagate(int k, int l, int r) {
    if (tree[k] != 0) {
      tree[k] += (r - l) * tree[k];
      if (r - l > 1) {
        tree[2 * k + 1] += tree[k];
        tree[2 * k + 2] += tree[k];
      }
      tree[k] = 0;
    }
  }

  void add(int a, int b, int x, int k, int l, int r) {
    propagate(k, l, r);
    if (a >= r || b <= l) {
      return;
    } else if (a <= l && r <= b) {
      tree[k] += x;
      propagate(k, l, r);
    } else {
      int m = (l + r) / 2;
      add(a, b, x, 2 * k + 1, l, m);
      add(a, b, x, 2 * k + 2, m, r);
      tree[k] = tree[2 * k + 1] + tree[2 * k + 2];
    }
  }

  int query(int a, int b, int k, int l, int r) {
    propagate(k, l, r);
    if (a >= r || b <= l)
      return 0;
    if (a <= l && r <= b)
      return tree[k];
    int m = (l + r) / 2;
    return query(a, b, 2 * k + 1, l, m) +
           query(a, b, 2 * k + 2, m, r);
  }

  void add(int a, int b, int x) { add(a, b, x, 0, 0, sz); }

  int query(int a, int b) { return query(a, b, 0, 0, sz); }
};

int main() {
  int N, M, P[100000];
  cin >> N >> M;
  SegmentTree segtree(N);
  for (int i = 0; i < M; i++) {
    cin >> P[i];
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
    cin >> A >> B >> C;
    ret += min(used * A, C + used * B);
  }
  cout << ret << endl;
}