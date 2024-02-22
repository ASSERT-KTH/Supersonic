#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> Pr;
const int INF = 1 << 28;
const int size = 1 << 20;
int seg_v[size * 2 - 1], seg_a[size * 2 - 1];
Pr rmq[size * 2 - 1];

inline void seg_add(int l, int r, int x, int k = 0, int a = 0, int b = size) {
  if (b <= l || r <= a)
    return;
  if (l <= a && b <= r) {
    seg_a[k] += x;
    while (k) {
      k = (k - 1) >> 1;
      seg_v[k] = max(seg_v[k << 1 | 1] + seg_a[k << 1 | 1],
                     seg_v[k << 1 | 2] + seg_a[k << 1 | 2]);
    }
    return;
  }
  seg_add(l, r, x, k << 1 | 1, a, (a + b) >> 1);
  seg_add(l, r, x, k << 1 | 2, (a + b) >> 1, b);
}

inline int seg_getMax(int l, int r, int k = 0, int a = 0, int b = size) {
  if (b <= l || r <= a)
    return -INF;
  if (l <= a && b <= r)
    return seg_a[k] + seg_v[k];
  return seg_a[k] + max(seg_getMax(l, r, k << 1 | 1, a, (a + b) >> 1),
                         seg_getMax(l, r, k << 1 | 2, (a + b) >> 1, b));
}

inline void rmq_update(int k, int x) {
  k += size - 1;
  rmq[k] = Pr(x, k);
  while (k) {
    k = (k - 1) >> 1;
    rmq[k] = max(rmq[k << 1 | 1], rmq[k << 1 | 2]);
  }
}

Pr _rmq_getMax(int l, int r, int k = 0, int a = 0, int b = size) {
  if (b <= l || r <= a)
    return Pr(-INF, -1);
  if (l <= a && b <= r)
    return rmq[k];
  return max(_rmq_getMax(l, r, k << 1 | 1, a, (a + b) >> 1),
             _rmq_getMax(l, r, k << 1 | 2, (a + b) >> 1, b));
}

inline int rmq_getMax(int l, int r) { return _rmq_getMax(l, r).first; }

inline int rmq_getMaxIdx(int l, int r) { return _rmq_getMax(l, r).second; }

void solve() {
  int N, H;
  scanf("%d %d", &N, &H);
  vector<int> d(N), h(N);
  for (int i = 0; i < N - 1; i++) {
    scanf("%d %d", &d[i + 1], &h[i]);
  }

  long long int res = 0;
  for (int i = 0; i < N; i++) {
    rmq_update(i, h[i]);
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
      int idx = rmq_getMaxIdx(0, fl);
      if (h[idx] > H - seg_getMax(idx, fl)) {
        h[idx] = H - seg_getMax(idx, fl);
        rmq_update(idx, h[idx]);
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
    }
  }
  printf("%lld\n", res);
}

int main() {
  solve();
  return 0;
}