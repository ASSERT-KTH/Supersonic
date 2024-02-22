#include <iostream>
#include <utility>

constexpr int INF = 1 << 28;
typedef std::pair<int, int> Pr;

const int N_MAX = 100000;
int N, H;
int d[N_MAX], h[N_MAX];
const int size = 1 << 18;
int seg_v[size * 2 - 1];
int seg_a[size * 2 - 1];
Pr rmq[size * 2 - 1];

void seg_add(int l, int r, int x, int k = 0, int a = 0, int b = size) {
  if (l <= a && b <= r) {
    seg_a[k] += x;
    while (k) {
      k = (k - 1) / 2;
      seg_v[k] = std::max(seg_v[k * 2 + 1] + seg_a[k * 2 + 1],
                          seg_v[k * 2 + 2] + seg_a[k * 2 + 2]);
    }
    return;
  }
  int m = (a + b) / 2;
  if (l < m)
    seg_add(l, r, x, k * 2 + 1, a, m);
  if (r > m)
    seg_add(l, r, x, k * 2 + 2, m, b);
}

int seg_getMax(int l, int r, int k = 0, int a = 0, int b = size) {
  if (l <= a && b <= r)
    return seg_a[k] + seg_v[k];
  int m = (a + b) / 2;
  int vl = (l < m) ? seg_getMax(l, r, k * 2 + 1, a, m) : -INF;
  int vr = (r > m) ? seg_getMax(l, r, k * 2 + 2, m, b) : -INF;
  return seg_a[k] + std::max(vl, vr);
}

void rmq_update(int k, int x) {
  int i = k;
  k += size - 1;
  rmq[k] = Pr(x, i);
  while (k) {
    k = (k - 1) / 2;
    rmq[k] = std::max(rmq[k * 2 + 1], rmq[k * 2 + 2]);
  }
}

Pr _rmq_getMax(int l, int r, int k = 0, int a = 0, int b = size) {
  if (l <= a && b <= r)
    return rmq[k];
  int m = (a + b) / 2;
  Pr vl = (l < m) ? _rmq_getMax(l, r, k * 2 + 1, a, m) : Pr(-INF, -1);
  Pr vr = (r > m) ? _rmq_getMax(l, r, k * 2 + 2, m, b) : Pr(-INF, -1);
  return std::max(vl, vr);
}

int rmq_getMax(int l, int r) { return _rmq_getMax(l, r).first; }

int rmq_getMaxIdx(int l, int r) { return _rmq_getMax(l, r).second; }

void solve() {
  long long int res = 0;
  for (int i = 0; i < N; ++i) {
    rmq_update(i, h[i]);
  }
  seg_add(0, N, H);
  for (int fl = 0; fl < N; ++fl) {
    if (seg_getMax(fl, fl + 1) > H) {
      seg_add(fl, N, H - seg_getMax(fl, fl + 1));
    }
    seg_add(fl, N, -d[fl]);
    if (seg_getMax(fl, fl + 1) > 0)
      continue;
    do {
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
      int num = std::min(s, t);
      seg_add(idx, N, h[idx] * num);
      res += num;
    } while (seg_getMax(fl, fl + 1) <= 0);
  }
  std::cout << res << "\n";
}

int main() {
  std::cin >> N >> H;
  for (int i = 0; i < N - 1; ++i) {
    std::cin >> d[i + 1] >> h[i];
  }
  solve();
}