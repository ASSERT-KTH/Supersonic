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
inline void seg_add(int l, int r, int x, int k = 0, int a = 0, int b = size) {
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
  int vr = seg_getMax(l, r, k * 2 + 2, m, b