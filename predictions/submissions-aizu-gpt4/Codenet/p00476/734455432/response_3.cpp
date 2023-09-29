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
    k = (k - 1) / 2;
    while (k >= 0) {
      seg_v[k] = max(seg_v[k * 2 + 1] + seg_a[k * 2 + 1],
                     seg_v[k * 2 + 2] + seg_a[k * 2 + 2]);
      if (k != 0) {
        k = (k - 1) / 2;
      } else {
        break;
      }
    }
    return;
  }
  int m = (a + b) / 2;
  seg_add(l, r, x, k * 2 + 1, a, m);
  seg_add(l, r, x, k * 2 + 2, m, b);
  seg_v[k] = max(seg_v[k * 2 + 1] + seg_a[k * 2 + 1],
                 seg_v[k * 2 + 2] + seg_a[k * 2 + 2]);
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
void solve() {
  long long int res = 0;
  for (int i = 0; i < N; i++) {
    rmq_update(i, h[i]);
  }
  seg_add(0, N, H);
  for (int fl = 0; fl < N; fl++) {
    seg_add(fl, N, -d[fl]);
    if (seg_v[0] + seg_a[0] <= 0) {
      while (true) {
        int idx = _rmq_getMax(0, fl).second;
        int s = (H - seg_v[2 * idx + 1] - seg_a[2 * idx + 1]) / h[idx];
        int hp = -(seg_v[0] + seg_a[0]);
        int need = hp + 1;
        int t = (need / h[idx]) + !!(need % h[idx]);
        int num = min(s, t);
        seg_add(idx, N, h[idx] * num);
        res += num;
        if (seg_v[0] + seg_a[0] > 0)
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