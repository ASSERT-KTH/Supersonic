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
    fill(Min.begin(), Min.end(), INT_MAX);
    fill(Max.begin(), Max.end(), INT_MIN);
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
      return INT_MAX;
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
      return INT_MIN;
    if (a <= l && r <= b)
      return Max[k];
    int vl = get_max(a, b, k * 2 + 1, l, (l + r) / 2);
    int vr = get_max(a, b, k * 2 + 2, (l + r) / 2, r);
    return max(vl, vr);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, d;
  cin >> N >> d;
  SegTree x_seg, y_seg;
  x_seg.init(N), y_seg.init(N);
  vector<pair<int, int>> hoge;
  for (int i = 0; i < N; ++i) {
    int x, y, b;
    cin >> x >> y >> b;
    hoge.push_back(make_pair(b, i));
    x_seg.min_update(i, x);
    x_seg.max_update(i, x);
    y_seg.min_update(i, y);
    y_seg.max_update(i, y);
  }
  sort(hoge.begin(), hoge.end());
  long long ans = INT_MIN;
  for (int i = 0; i < N; ++i) {
    int b = hoge[i].first;
    int idx = hoge[i].second;
    int min_x = x_seg.get_min(i, idx);
    int max_x = x_seg.get_max(i, idx);
    int min_y = y_seg.get_min(i, idx);
    int max_y = y_seg.get_max(i, idx);
    ans = max(ans, 1ll * (max_x - min_x) * (max_y - min_y));
  }
  cout << ans << endl;

  return 0;
}