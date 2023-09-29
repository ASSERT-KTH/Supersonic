#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> Pr;
int N, H;
int d[100000], h[100000];

const int size = 1 << 20;
int seg_v[size * 2 - 1], seg_a[size * 2 - 1];
Pr rmq[size * 2 - 1];

void seg_add(int l, int r, int x, int k = 0, int a = 0, int b = size) {
  if (b <= l || r <= a) return;
  if (l <= a && b <= r) {
    seg_a[k] += x;
    for (;k > 0; k = (k - 1) / 2) seg_v[k] = max(seg_v[k * 2 + 1] + seg_a[k * 2 + 1], seg_v[k * 2 + 2] + seg_a[k * 2 + 2]);
    return;
  }
  seg_add(l, r, x, k * 2 + 1, a, (a + b) / 2);
  seg_add(l, r, x, k * 2 + 2, (a + b) / 2, b);
}

int seg_getMax(int l, int r, int k = 0, int a = 0, int b = size) {
  if (b <= l || r <= a) return 0;
  if (l <= a && b <= r) return seg_v[k] + seg_a[k];
  return seg_a[k] + max(seg_getMax(l, r, k * 2 + 1, a, (a + b) / 2), seg_getMax(l, r, k * 2 + 2, (a + b) / 2, b));
}

void rmq_update(int k, int x) {
  k += size - 1;
  rmq[k] = Pr(x, k - size + 1);
  while (k > 0) {
    k = (k - 1) / 2;
    rmq[k] = max(rmq[k * 2 + 1], rmq[k * 2 + 2]);
  }
}

Pr _rmq_getMax(int l, int r, int k = 0, int a = 0, int b = size) {
  if (b <= l || r <= a) return Pr(0, 0);
  if (l <= a && b <= r) return rmq[k];
  return max(_rmq_getMax(l, r, k * 2 + 1, a, (a + b) / 2), _rmq_getMax(l, r, k * 2 + 2, (a + b) / 2, b));
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
    int currMax = seg_getMax(fl, fl + 1);
    if (currMax > H) {
      seg_add(fl, N, H - currMax);
    }
    seg_add(fl, N, -d[fl]);
    if (seg_getMax(fl, fl + 1) > 0) continue;
    while (seg_getMax(fl, fl + 1) <= 0) {
      int idx = rmq_getMaxIdx(0, fl);
      int newMax = H - seg_getMax(idx, fl);
      if (h[idx] > newMax) {
        h[idx] = newMax;
        rmq_update(idx, h[idx]);
        continue;
      }
      int s = newMax / h[idx];
      int need = -seg_getMax(fl, fl + 1) + 1;
      int num = min(s, (need - 1) / h[idx] + 1);
      seg_add(idx, N, h[idx] * num);
      res += num;
    }
  }
  printf("%lld\n", res);
}

int main() {
  scanf("%d %d", &N, &H);
  for (int i = 0; i < N-1; i++) {
    scanf("%d %d", d + i + 1, h + i);
  }
  solve();
}