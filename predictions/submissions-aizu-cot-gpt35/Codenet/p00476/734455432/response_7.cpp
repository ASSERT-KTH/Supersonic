#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 28;
typedef pair<int, int> Pr;
int N, H;
int d[100000], h[100000];
int seg_v[400000];
Pr rmq[400000];

void seg_add(int l, int r, int x, int k = 0, int a = 0, int b = N) {
  if (b <= l || r <= a)
    return;
  if (l <= a && b <= r) {
    seg_v[k] += x;
    while (k) {
      k = (k - 1) / 2;
      seg_v[k] = max(seg_v[k * 2 + 1], seg_v[k * 2 + 2]);
    }
    return;
  }
  int m = (a + b) / 2;
  seg_add(l, r, x, k * 2 + 1, a, m);
  seg_add(l, r, x, k * 2 + 2, m, b);
}

int seg_getMax(int l, int r, int k = 0, int a = 0, int b = N) {
  if (b <= l || r <= a)
    return -INF;
  if (l <= a && b <= r)
    return seg_v[k];
  int m = (a + b) / 2;
  int vl = seg_getMax(l, r, k * 2 + 1, a, m);
  int vr = seg_getMax(l, r, k * 2 + 2, m, b);
  return max(vl, vr);
}

void solve() {
  long long int res = 0;
  for (int i = 0; i < N; i++) {
    seg_add(i, i + 1, h[i]);
  }
  seg_add(0, N, H);
  for (int fl = 0; fl < N; fl++) {
    if (seg_getMax(fl, fl + 1) > H) {
      seg_add(fl, N, H - seg_getMax(fl, fl + 1));
    }
    seg_add(fl, N, -d[fl]);
    if (seg_getMax(fl, fl + 1) > 0)
      continue;
    while (true) {
      int idx = fl;
      int maxIdx = -1;
      int maxVal = -INF;
      while (idx >= 0) {
        if (h[idx] > H - seg_getMax(idx, fl)) {
          h[idx] = H - seg_getMax(idx, fl);
          seg_add(idx, idx + 1, h[idx]);
          continue;
        }
        int s = (H - seg_getMax(idx, fl)) / h[idx];
        int hp = seg_getMax(fl, fl + 1);
        int need = -hp + 1;
        int t = (need / h[idx]) + !!(need % h[idx]);
        int num = min(s, t);
        seg_add(idx, N, h[idx] * num);
        res += num;
        if (seg_getMax(fl, fl + 1) > 0)
          break;
        idx--;
      }
      if (idx < 0)
        break;
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