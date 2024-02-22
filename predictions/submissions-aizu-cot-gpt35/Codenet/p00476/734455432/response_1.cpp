#include <iostream>
#include <vector>
#include <algorithm>

const int INF = 1 << 28;
using Pr = std::pair<int, int>;

void seg_add(int l, int r, int x, int k, int a, int b, std::vector<int>& seg_v, std::vector<int>& seg_a) {
  if (b <= l || r <= a)
    return;
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
  seg_add(l, r, x, k * 2 + 1, a, m, seg_v, seg_a);
  seg_add(l, r, x, k * 2 + 2, m, b, seg_v, seg_a);
}

int seg_getMax(int l, int r, int k, int a, int b, const std::vector<int>& seg_v, const std::vector<int>& seg_a) {
  if (b <= l || r <= a)
    return -INF;
  if (l <= a && b <= r)
    return seg_a[k] + seg_v[k];
  int m = (a + b) / 2;
  int vl = seg_getMax(l, r, k * 2 + 1, a, m, seg_v, seg_a);
  int vr = seg_getMax(l, r, k * 2 + 2, m, b, seg_v, seg_a);
  return seg_a[k] + std::max(vl, vr);
}

void rmq_update(int k, int x, int size, std::vector<Pr>& rmq) {
  int i = k;
  k += size - 1;
  rmq[k] = Pr(x, i);
  while (k) {
    k = (k - 1) / 2;
    rmq[k] = std::max(rmq[k * 2 + 1], rmq[k * 2 + 2]);
  }
}

Pr _rmq_getMax(int l, int r, int k, int a, int b, const std::vector<Pr>& rmq) {
  if (b <= l || r <= a)
    return Pr(-INF, -1);
  if (l <= a && b <= r)
    return rmq[k];
  int m = (a + b) / 2;
  Pr vl = _rmq_getMax(l, r, k * 2 + 1, a, m, rmq);
  Pr vr = _rmq_getMax(l, r, k * 2 + 2, m, b, rmq);
  return std::max(vl, vr);
}

int rmq_getMax(int l, int r, const std::vector<Pr>& rmq) {
  return _rmq_getMax(l, r, 0, 0, rmq.size() / 2 + 1, rmq).first;
}

int rmq_getMaxIdx(int l, int r, const std::vector<Pr>& rmq) {
  return _rmq_getMax(l, r, 0, 0, rmq.size() / 2 + 1, rmq).second;
}

void solve() {
  int N, H;
  std::cin >> N >> H;
  
  std::vector<int> d(N), h(N);
  for (int i = 0; i < N - 1; i++) {
    std::cin >> d[i + 1] >> h[i];
  }
  
  std::vector<int> seg_v(2 * N - 1), seg_a(2 * N - 1);
  std::vector<Pr> rmq(2 * N - 1);

  long long int res = 0;
  for (int i = 0; i < N; i++) {
    rmq_update(i, h[i], N, rmq);
  }
  seg_add(0, N, H, 0, 0, N, seg_v, seg_a);
  
  for (int fl = 0; fl < N; fl++) {
    if (seg_getMax(fl, fl + 1, 0, 0, N, seg_v, seg_a) > H) {
      seg_add(fl, N, H - seg_getMax(fl, fl + 1, 0, 0, N, seg_v, seg_a), 0, 0, N, seg_v, seg_a);
    }
    seg_add(fl, N, -d[fl], 0, 0, N, seg_v, seg_a);
    if (seg_getMax(fl, fl + 1, 0, 0, N, seg_v, seg_a) > 0)
      continue;
    while (true) {
      int idx = rmq_getMaxIdx(0, fl, rmq);
      if (h[idx] > H - seg_getMax(idx, fl, 0, 0, N, seg_v, seg_a)) {
        h[idx] = H - seg_getMax(idx, fl, 0, 0, N, seg_v, seg_a);
        rmq_update(idx, h[idx], N, rmq);
        continue;
      }
      int s = (H - seg_getMax(idx, fl, 0, 0, N, seg_v, seg_a)) / h[idx];
      int hp = seg_getMax(fl, fl + 1, 0, 0, N, seg_v, seg_a);
      int need = -hp + 1;
      int t = (need / h[idx]) + !!(need % h[idx]);
      int num = std::min(s, t);
      seg_add(idx, N, h[idx] * num, 0, 0, N, seg_v, seg_a);
      res += num;
      if (seg_getMax(fl, fl + 1, 0, 0, N, seg_v, seg_a) > 0)
        break;
    }
  }
  
  std::cout << res << std::endl;
}

int main() {
  solve();
  return 0;
}