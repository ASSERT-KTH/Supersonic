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
    if (k) {
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

void solve() {
  long long int res = 0;
  memset(h, 0, sizeof(h));
  memset(d, 0, sizeof(d));

  for (int i = 0; i < N; i++) {
    rmq_update(i, h[i]);
  }
  seg_add(0, N, H);
  for (int fl = 0; fl < N; fl++) {
    int maxVal=seg_getMax(fl, fl + 1);
    if (maxVal > H) {
      seg_add(fl, N, H - maxVal);
    }
    seg_add(fl, N, -d[fl]);
    if (maxVal > 0)
      continue;
    while (true) {
      int idx = rmq_getMaxIdx(0, fl);
      if (h[idx] > H - maxVal) {
        h[idx] = H - maxVal;
        rmq_update(idx, h[idx]);
        continue;
      }
      int s = (H - maxVal) / h[idx];
      int hp = maxVal;
      int need = -hp + 1;
      int t = (need / h[idx]) + !!(need % h[idx]);
      int num = min(s, t);
      seg_add(idx, N, h[idx] * num);
      res += num;
      if (maxVal > 0)
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