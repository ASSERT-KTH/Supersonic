#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 28;
typedef pair<int, int> Pr;
int N, H;
int d[100000], h[100000];
const int size = 1 << 20;
int seg_v[size * 2 - 1];
int seg_a[size * 2 - 1];
Pr rmq[size * 2 - 1];
void seg_add(int l, int r, int x, int k = 0, int a = 0, int b = size) {
  if (b <= l || r <= a)
    return;
  if (l <= a && b <= r) {
    seg_a[k] += x;
    while (k) {
      k = (k - 1) / 2;
      seg_v[k] = max(seg_v[k * 2 + 1] + seg_a[k * 2 + 1],
                     seg_v[k * 2 + 2] + seg_a[k * 2 + 2]);
    }
    return;
  }
  int m = (a + b) / 2;
  seg_add(l, r, x, k * 2 + 1, a, m);
  seg_add(l, r, x, k * 2 + 2, m, b);
}
int seg_getMax(int l, int r, int k = 0, int a = 0, int b = size) {
  if (b <= l || r <= a)
    return -INF;
  if (l <= a && b <= r)
    return seg_a[k] + seg_v[k];
  int m = (a + b) / 2;
  int vl = seg_getMax(l, r, k * 2 + 1, a, m);
  int vr = seg_getMax(l, r, k * 2 + 2, m, b);
  return seg_a[k] + max(vl, vr);
}
void rmq_update(int k, int x) {
  int i = k;
  k += size - 1;
  rmq[k] = Pr(x, i);
  while (k) {
    k = (k - 1) / 2;
    rmq[k] = max(rmq[k * 2 + 1], rmq[k * 2 + 2]);
  }
}
Pr _rmq_getMax(int l, int r, int k = 0, int a = 0, int b = size) {
  if (b <= l || r <= a)
    return Pr(-INF, -1);
  if (l <= a && b <= r)
    return rmq[k];
  int m = (a + b) / 2;
  Pr vl = _rmq_getMax(l, r, k * 2 + 1, a, m);
  Pr vr = _rmq_getMax(l, r, k * 2 + 2, m, b);
  return max(vl, vr);
}
int rmq_getMax(int l, int r) { return _rmq_getMax(l, r).first; }
int rmq_getMaxIdx(int l, int r) { return _rmq_getMax(l, r).second; }
void solve() {
  long long int res = 0;
  for (int i = 0; i < N; i++) {
    rmq_update(i, h[i]);
  }
  seg_add(0, N, H);
  for (int fl = 0; fl < N; fl++) {
    int maxSeg = seg_getMax(fl, fl + 1);
    if (maxSeg > H) {
      seg_add(fl, N, H - maxSeg);
    }
    seg_add(fl, N, -d[fl]);
    if (seg_getMax(fl, fl + 1) > 0) {
      continue;
    }
    while (true) {
      int idx = rmq_getMaxIdx(0, fl);
      int maxSegIdxToFl = seg_getMax(idx, fl);
      if (h[idx] > H - maxSegIdxToFl) {
        h[idx] = H - maxSegIdxToFl;
        rmq_update(idx, h[idx]);
        continue;
      }
      int s = (H - maxSegIdxToFl) / h[idx];
      int hp = seg_getMax(fl, fl + 1);
      int need = -hp + 1;
      int t = (need / h[idx]) + !!(need % h[idx]);
      int num = min(s, t);
      seg_add(idx, N, h[idx] * num);
      res += num;
      if (seg_getMax(fl, fl + 1) > 0) {
        break;
      }
    }
  }
  printf("%lld\n", res);
}
int main() {
  scanf("%d %d", &N, &H);
  for (int i = 0; i < N - 1; i++) {
    scanf("%d %d", d + i + 1, h + i);
  }
  solve();
}