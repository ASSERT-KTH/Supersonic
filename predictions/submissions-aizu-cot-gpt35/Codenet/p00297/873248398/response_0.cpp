#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

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
    fill(Max.begin(), Max.end(), -1e9);
    fill(Min.begin(), Min.end(), 1e9);
  }

  void update(int idx, int val, vector<int>& seg) {
    idx += n - 1;
    seg[idx] = val;
    while (idx > 0) {
      idx = (idx - 1) / 2;
      seg[idx] = min(seg[idx * 2 + 1], seg[idx * 2 + 2]);
    }
  }

  int query(int a, int b, int k, int l, int r, vector<int>& seg) {
    if (r <= a || b <= l)
      return 1e9;
    if (a <= l && r <= b)
      return seg[k];
    int vl = query(a, b, k * 2 + 1, l, (l + r) / 2, seg);
    int vr = query(a, b, k * 2 + 2, (l + r) / 2, r, seg);
    return min(vl, vr);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, d;
  cin >> N >> d;

  SegTree x_seg, y_seg;
  x_seg.init(N), y_seg.init(N);

  vector<pair<int, int>> points(N);

  for (int i = 0; i < N; ++i) {
    cin >> points[i].first >> points[i].second >> ignore;
  }

  sort(points.begin(), points.end());

  for (int i = 0; i < N; ++i) {
    x_seg.update(i, points[i].first, x_seg.Min);
    x_seg.update(i, points[i].first, x_seg.Max);
    y_seg.update(i, points[i].second, y_seg.Min);
    y_seg.update(i, points[i].second, y_seg.Max);
  }

  long long ans = -1e9;

  for (int i = 0; i < N; ++i) {
    int b = points[i].first;
    int idx = lower_bound(points.begin(), points.end(), make_pair(b + d, -1)) - points.begin();
    int min_x = x_seg.query(i, idx, 0, 0, x_seg.n, x_seg.Min);
    int max_x = x_seg.query(i, idx, 0, 0, x_seg.n, x_seg.Max);
    int min_y = y_seg.query(i, idx, 0, 0, y_seg.n, y_seg.Min);
    int max_y = y_seg.query(i, idx, 0, 0, y_seg.n, y_seg.Max);
    ans = max(ans, 1LL * (max_x - min_x) * (max_y - min_y));
  }

  cout << ans << endl;

  return 0;
}