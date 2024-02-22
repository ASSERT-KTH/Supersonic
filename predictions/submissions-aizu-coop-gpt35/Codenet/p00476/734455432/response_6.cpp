#include <iostream>
#include <vector>
#include <utility>

using namespace std;

const int INF = 1 << 28;
typedef pair<int, int> Pr;

void seg_add(vector<int>& seg_v, vector<int>& seg_a, int l, int r, int x, int k = 0, int a = 0, int b = 0) {
  if (b <= l || r <= a)
    return;
  if (l <= a && b <= r) {
    seg_a[k] += x;
    while (k) {
      k = (k - 1) / 2;
      seg_v[k] = max(seg_v[k * 2 + 1] + seg_a[k * 2 + 1], seg_v[k * 2 + 2] + seg_a[k * 2 + 2]);
    }
    return;
  }
  int m = (a + b) / 2;
  seg_add(seg_v, seg_a, l, r, x, k * 2 + 1, a, m);
  seg_add(seg_v, seg_a, l, r, x, k * 2 + 2, m, b);
}

int seg_getMax(vector<int>& seg_v, vector<int>& seg_a, int l, int r, int k = 0, int a = 0, int b = 0) {
  if (b <= l || r <= a)
    return -INF;
  if (l <= a && b <= r)
    return seg_a[k] + seg_v[k];
  int m = (a + b) / 2;
  int vl = seg_getMax(seg_v, seg_a, l, r, k * 2 + 1, a, m);
  int vr = seg_getMax(seg_v, seg_a, l, r, k * 2 + 2, m, b);
  return seg_a[k] + max(vl, vr);
}

void rmq_update(vector<Pr>& rmq, int k, int x) {
  int i = k;
  k += rmq.size() / 2 - 1;
  rmq[k] = Pr(x, i);
  while (k) {
    k = (k - 1) / 2;
    rmq[k] = max(rmq[k * 2 + 1], rmq[k * 2 + 2]);
  }
}

Pr _rmq_getMax(vector<Pr>& rmq, int l, int r, int k = 0, int a = 0, int b = 0) {
  if (b <= l || r <= a)
    return Pr(-INF, -1);
  if (l <= a && b <= r)
    return rmq[k];
  int m = (a + b) / 2;
  Pr vl = _rmq_getMax(rmq, l, r, k * 2 + 1, a, m);
  Pr vr = _rmq_getMax(rmq, l, r, k * 2 + 2, m, b);
  return max(vl, vr);
}

int rmq_getMax(vector<Pr>& rmq, int l, int r) {
  return _rmq_getMax(rmq, l, r).first;
}

int rmq_getMaxIdx(vector<Pr>& rmq, int l, int r) {
  return _rmq_getMax(rmq, l, r).second;
}

void solve() {
  int N, H;
  scanf("%d %d", &N, &H);

  vector<int> d(N), h(N);
  for (int i = 0; i < N - 1; i++) {
    scanf("%d %d", &d[i + 1], &h[i]);
  }

  vector<int> seg_v(N * 4, 0);
  vector<int> seg_a(N * 4, 0);
  vector<Pr> rmq(N * 4, Pr(-INF, -1));

  long long int res = 0;
  for (int i = 0; i < N; i++) {
    rmq_update(rmq, i, h[i]);
  }
  seg_add(seg_v, seg_a, 0, N, H);
  for (int fl = N - 1; fl >= 0; fl--) {
    int segMax = seg_getMax(seg_v, seg_a, fl, fl + 1);
    if (segMax > H) {
      seg_add(seg_v, seg_a, fl, N, H - segMax);
    }
    seg_add(seg_v, seg_a, fl, N, -d[fl]);
    if (seg_getMax(seg_v, seg_a, fl, fl + 1) > 0)
      continue;
    while (true) {
      int idx = rmq_getMaxIdx(rmq, 0, fl);
      if (h[idx] > H - seg_getMax(seg_v, seg_a, idx, fl)) {
        h[idx] = H - seg_getMax(seg_v, seg_a, idx, fl);
        rmq_update(rmq, idx, h[idx]);
        continue;
      }
      int s = (H - seg_getMax(seg_v, seg_a, idx, fl)) / h[idx];
      int hp = seg_getMax(seg_v, seg_a, fl, fl + 1);
      int need = -hp + 1;
      int t = (need / h[idx]) + !!(need % h[idx]);
      int num = min(s, t);
      seg_add(seg_v, seg_a, idx, N, h[idx] * num);
      res += num;
      if (seg_getMax(seg_v, seg_a, fl, fl + 1) > 0)
        break;
    }
  }
  printf("%lld\n", res);
}

int main() {
  solve();
  return 0;
}