#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
  vector<int> seg, add;
  int sz;

  SegmentTree(int n) {
    sz = 1;
    while (sz < n) sz <<= 1;
    seg.assign(sz << 1, 0);
    add.assign(sz << 1, 0);
  }

  void Add(int a, int b, int x, int k, int l, int r) {
    if (a >= r || b <= l) {
      return;
    } 
    if (a <= l && r <= b) {
      add[k] += x;
    } else {
      int mid = (l + r) >> 1;
      Add(a, b, x, k << 1, l, mid);
      Add(a, b, x, (k << 1) | 1, mid, r);
      seg[k] = seg[k << 1] + add[k << 1] + seg[(k << 1) | 1] + add[(k << 1) | 1];
    }
  }

  int Query(int a, int b, int k, int l, int r) {
    if (a >= r || b <= l) return 0;
    if (a <= l && r <= b) return seg[k] + add[k];
    int mid = (l + r) >> 1;
    return Query(a, b, k << 1, l, mid) + Query(a, b, (k << 1) | 1, mid, r) + add[k];
  }

  void Add(int a, int b, int x) { Add(a, b, x, 1, 0, sz); }
  int Query(int a, int b) { return Query(a, b, 1, 0, sz); }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  cin >> N >> M;

  vector<int> P(M);
  SegmentTree segtree(N);
  for (int& p : P) {
    cin >> p;
    --p;
  }

  for (int i = 1; i < M; i++) {
    int u = min(P[i - 1], P[i]), v = max(P[i - 1], P[i]);
    segtree.Add(u, v, 1);
  }

  long long ret = 0;
  for (int i = 0; i < N - 1; i++) {
    long long used = segtree.Query(i, i + 1);
    int A, B, C;
    cin >> A >> B >> C;
    ret += min(used * A, C + used * B);
  }

  cout << ret << '\n';
}