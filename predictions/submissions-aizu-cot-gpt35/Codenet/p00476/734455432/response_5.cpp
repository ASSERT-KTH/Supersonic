#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1 << 28;
typedef pair<int, int> Pr;

void seg_add(vector<int>& seg_a, vector<int>& seg_v, int l, int r, int x, int k = 0, int a = 0, int b = 0) {
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
  seg_add(seg_a, seg_v, l, r, x, k * 2 + 1, a, m);
  seg_add(seg_a, seg_v, l, r, x, k * 2 + 2, m, b);
}

int seg_getMax(vector<int>& seg_a, vector<int>& seg_v, int k = 0) {
  if (k >= seg_v.size())
    return -INF;
  if (k >= seg_a.size())
    return seg_v[k];
  return seg_a[k] + seg_v[k];
}

void rmq_update(vector<Pr>& rmq, int k, int x) {
  int i = k;
  k += rmq.size() / 2;
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
  cin >> N >> H;

  vector<int> d(N), h(N);
  for (int i = 1; i < N; i++) {
    cin >> d[i] >> h[i - 1];
  }

  vector<int> seg_v(N * 4), seg_a(N * 4);
  vector<Pr> rmq(N * 4);

  long long int res = 0;
  for (int i = 0; i < N; i++) {
    rmq_update(rmq, i, h[i]);
  }
  seg_add(seg_a, seg_v, 0, N, H);
  for (int fl = 1; fl < N; fl++) {
    if (seg_getMax(seg_a, seg_v, fl) > H) {
      seg_add(seg_a, seg_v, fl, N, H - seg_getMax(seg_a, seg_v, fl));
    }
    seg_add(seg_a, seg_v, fl, N, -d[fl]);
    if (seg_getMax(seg_a, seg_v, fl) > 0)
      continue;
    while (true) {
      int idx = rmq_getMaxIdx(rmq, 0, fl);
      if (h[idx] > H - seg_getMax(seg_a, seg_v, idx, fl)) {
        h[idx] = H - seg_getMax(seg_a, seg_v, idx, fl);
        rmq_update(rmq, idx, h[idx]);
        continue;
      }
      int s = (H - seg_getMax(seg_a, seg_v, idx, fl)) / h[idx];
      int hp = seg_getMax(seg_a, seg_v, fl, fl + 1);
      int need = -hp + 1;
      int t = (need / h[idx]) + !!(need % h[idx]);
      int num = min(s, t);
      seg_add(seg_a, seg_v, idx, N, h[idx] * num);
      res += num;
      if (seg_getMax(seg_a, seg_v, fl, fl + 1) > 0)
        break;
    }
  }
  cout << res << endl;
}

int main() {
  solve();
  return 0;
}