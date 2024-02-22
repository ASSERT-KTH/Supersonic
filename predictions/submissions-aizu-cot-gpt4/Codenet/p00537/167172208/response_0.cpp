#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct SegmentTree {
  vector<pair<int, int>> seg;
  int sz;

  SegmentTree(int n) {
    sz = 1;
    while (sz < n)
      sz *= 2;
    seg.assign(sz * 2 + 1, {0, 0});
  }

  void Add(int a, int b, int x, int k, int l, int r) {
    if (a >= r || b <= l) {
      return;
    } else if (a <= l && r <= b) {
      seg[k].second += x;
    } else {
      Add(a, b, x, 2 * k + 1, l, (l + r) >> 1);
      Add(a, b, x, 2 * k + 2, (l + r) >> 1, r);
      seg[k].first = seg[2 * k + 1].first + seg[2 * k + 1].second + seg[2 * k + 2].first + seg[2 * k + 2].second;
    }
  }

  int Query(int a, int b, int k, int l, int r) {
    if (a >= r || b <= l)
      return 0;
    if (a <= l && r <= b)
      return (seg[k].first + seg[k].second);
    return Query(a, b, 2 * k + 1, l, (l + r) >> 1) + Query(a, b, 2 * k + 2, (l + r) >> 1, r) + seg[k].second;
  }

  void Add(int a, int b, int x) { Add(a, b, x, 0, 0, sz); }
  int Query(int a, int b) { return Query(a, b, 0, 0, sz); }
};

int main() {
  int N, M;
  cin >> N >> M;
  SegmentTree segtree(N);
  vector<int> P(M);
  for (int &p : P) {
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
  cout << ret << endl;
  return 0;
}