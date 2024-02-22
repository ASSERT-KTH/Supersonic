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

  void update(int idx, int val, bool isMin) {
    idx += n - 1;
    if (isMin) {
      Min[idx] = val;
    } else {
      Max[idx] = val;
    }
    while (idx > 0) {
      idx = (idx - 1) / 2;
      if (isMin) {
        Min[idx] = min(Min[idx * 2 + 1], Min[idx * 2 + 2]);
      } else {
        Max[idx] = max(Max[idx * 2 + 1], Max[idx * 2 + 2]);
      }
    }
  }

  int get(int a, int b, vector<int>& arr, bool isMin, int k = 0, int l = 0, int r = -1) {
    if (r == -1)
      r = n;
    if (r <= a || b <= l)
      return isMin ? 1e9 : -1e9;
    if (a <= l && r <= b)
      return arr[k];
    int vl = get(a, b, arr, isMin, k * 2 + 1, l, (l + r) / 2);
    int vr = get(a, b, arr, isMin, k * 2 + 2, (l + r) / 2, r);
    return isMin ? min(vl, vr) : max(vl, vr);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, d;
  cin >> N >> d;

  SegTree x_seg, y_seg;
  x_seg.init(N), y_seg.init(N);

  vector<pair<int, int>> hoge(N);
  for (int i = 0; i < N; ++i) {
    int x, y, b;
    cin >> x >> y >> b;
    hoge[i] = make_pair(b, i);
    x_seg.update(i, x, true);
    x_seg.update(i, x, false);
    y_seg.update(i, y, true);
    y_seg.update(i, y, false);
  }

  sort(hoge.begin(), hoge.end());

  long long ans = -1e9;
  for (int i = 0; i < N; ++i) {
    int b = hoge[i].first;
    int idx = upper_bound(hoge.begin(), hoge.end(), make_pair(b + d, INT_MAX)) - hoge.begin();
    int min_x = x_seg.get(i, idx, x_seg.Min, true);
    int max_x = x_seg.get(i, idx, x_seg.Max, false);
    int min_y = y_seg.get(i, idx, y_seg.Min, true);
    int max_y = y_seg.get(i, idx, y_seg.Max, false);
    ans = max(ans, 1LL * (max_x - min_x) * (max_y - min_y));
  }

  cout << ans << endl;

  return 0;
}