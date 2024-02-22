#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

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
    fill(Max.begin(), Max.end(), -inf);
    fill(Min.begin(), Min.end(), inf);
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, d;
  cin >> N >> d;

  SegTree x_seg, y_seg;
  x_seg.init(N), y_seg.init(N);

  vector<pair<int, int>> hoge;
  hoge.reserve(N);

  for (int i = 0; i < N; ++i) {
    int x, y, b;
    cin >> x >> y >> b;
    hoge.emplace_back(b, i);
  }

  sort(hoge.begin(), hoge.end());

  for (auto it = hoge.begin(); it != hoge.end(); ++it) {
    x_seg.min_update(it->second, x_seg.Max[it->second]);
    x_seg.max_update(it->second, x_seg.Max[it->second]);
    y_seg.min_update(it->second, y_seg.Max[it->second]);
    y_seg.max_update(it->second, y_seg.Max[it->second]);
  }

  ll ans = -inf;

  for (auto it = hoge.begin(); it != hoge.end(); ++it) {
    int b = it->first;
    auto idx = upper_bound(it, hoge.end(), make_pair(b + d, inf));
    int min_x = x_seg.get_min(it->second, idx->second);
    int max_x = x_seg.get_max(it->second, idx->second);
    int min_y = y_seg.get_min(it->second, idx->second);
    int max_y = y_seg.get_max(it->second, idx->second);
    ans = max(ans, 1ll * (max_x - min_x) * (max_y - min_y));
  }

  cout << ans << endl;

  return 0;
}