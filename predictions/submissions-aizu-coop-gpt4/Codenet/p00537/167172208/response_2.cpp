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
    if (a >= r || b <= l) {
      return;
    } else if (a <= l && r <= b) {
      add[k] += x;
    } else {
      Add(a, b, x, 2 * k + 1, l, (l + r) / 2);
      Add(a, b, x, 2 * k + 2, (l + r) / 2, r);
      int left = seg[2 * k + 1] + add[2 * k + 1];  // Compute once, reuse
      int right = seg[2 * k + 2] + add[2 * k + 2]; // Compute once, reuse
      seg[k] = left + right;
    }
  }
  int Query(int a, int b, int k, int l, int r) {
    if (a >= r || b <= l)
      return (0);
    if (a <= l && r <= b)
      return (seg[k] + add[k]);
    return (Query(a, b, 2 * k + 1, l, (l + r) / 2) +
            Query(a, b, 2 * k + 2, (l + r) / 2, r) + add[k]);
  }
  void Add(int a, int b, int x) { Add(a, b, x, 0, 0, sz); }
  int Query(int a, int b) { return (Query(a, b, 0, 0, sz)); }
};
int main() {
  ios_base::sync_with_stdio(false); // Make cin and cout faster
  cin.tie(NULL);
  int N, M, P[100000];
  cin >> N >> M;
  SegmentTree segtree(N);
  for (int i = 0; i < M; i++) {
    cin >> P[i];
    --P[i];
  }
  for (int i = 1; i < M; i++) {
    int u = min(P[i - 1], P[i]), v = max(P[i - 1], P[i]);
    segtree.Add(u, v, 1);
  }
  int ret = 0; // Replace long long with int
  for (int i = 0; i < N - 1; i++) {
    int used = segtree.Query(i, i + 1);
    int A, B, C;
    cin >> A >> B >> C;
    ret += min(used * A, C + used * B);
  }
  cout << ret << endl;
}