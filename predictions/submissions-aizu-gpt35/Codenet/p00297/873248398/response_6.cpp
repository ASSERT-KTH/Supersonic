#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define all(a) a.begin(), a.end()
template <typename T> T &chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return a;
  }
  return a;
}
const int inf = 1e9;
struct SegTree {
  int n;
  vector<int> Max;
  vector<int> Min;
  void init(int n_) {
    n = 1;
    while (n < n_)
      n *= 2;
    Max.resize(2 * n);
    Min.resize(2 * n);
    fill(all(Min), inf);
  }
  void min_update(int idx, int val) {
    idx += n - 1;
    Min[idx] = val;
    while (idx > 0) {
      idx = (idx - 1) / 2;
      Min[idx] = min(Min[idx * 2 + 1], Min[idx * 2 + 2]);
    }
  }
  void max_update(int idx, int val) {
    idx += n - 1;
    Max[idx] = val;
    while (idx > 0) {
      idx = (idx - 1) / 2;
      Max[idx] = max(Max[idx * 2 + 1], Max[idx * 2 + 2]);
    }
  }
  int get_min(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r == -1)
      r = n;
    if (r <= a || b <= l)
      return inf;
    if (a <= l && r <= b)
      return Min[k];
    int vl = get_min(a, b, k * 2 + 1, l, (l + r) / 2);
    int vr = get_min(a, b, k * 2 + 2, (l + r) / 2, r);
    return min(vl, vr);
  }
  int get_max(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r == -1)
      r = n;
    if (r <= a || b <= l)
      return -inf;
    if (a <= l && r <= b)
      return Max[k];
    int vl = get_max(a, b, k * 2 + 1, l, (l + r) / 2);
    int vr = get_max(a, b, k * 2 + 2, (l + r) / 2, r);
    return max(vl, vr);
  }
};
int X[200020], Y[200020];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, d;
  cin >> N >> d;
  SegTree x_seg, y_seg;
  x_seg.init(N), y_seg.init(N);
  vector<pair<int,int>> hoge;
  for (int i = 0; i < N; i++) {
    int x, y, b;
    cin >> x >> y >> b;
    X[i] = x, Y[i] = y;
    hoge.PB({b, i});
  }
  sort(all(hoge));
  for (int i = 0; i < N; i++) {
    x_seg.min_update(i, X[hoge[i].second]);
    x_seg.max_update(i, X[hoge[i].second]);
    y_seg.min_update(i, Y[hoge[i].second]);
    y_seg.max_update(i, Y[hoge[i].second]);
  }
  ll ans = -inf;
  for (int i = 0; i < N; i++) {
    int b = hoge[i].first;
    int idx = upper_bound(all(hoge), make_pair(b + d, inf)) - hoge.begin();
    int min_x = x_seg.get_min(i, idx);
    int max_x = x_seg.get_max(i, idx);
    int min_y = y_seg.get_min(i, idx);
    int max_y = y_seg.get_max(i, idx);
    chmax(ans, 1ll * (max_x - min_x) * (max_y - min_y));
  }
  cout << ans << endl;
}