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
      return 1e9;
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
      return -1e9;
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

  int N;
  cin >> N;

  SegTree x_seg, y_seg;
  x_seg.init(N), y_seg.init(N);

  vector<int> X(N), Y(N);
  for (int i = 0; i < N; ++i) {
    int x, y, b;
    cin >> x >> y >> b;
    X[i] = x, Y[i] = y;
    x_seg.min_update(i, x);
    x_seg.max_update(i, x);
    y_seg.min_update(i, y);
    y_seg.max_update(i, y);
  }

  long long ans = -1e9;
  for (int i = 0; i < N; ++i) {
    int b = X[i];
    int idx = upper_bound(X.begin(), X.end(), b + N) - X.begin();
    int min_x = x_seg.get_min(i, idx);
    int max_x = x_seg.get_max(i, idx);
    int min_y = y_seg.get_min(i, idx);
    int max_y = y_seg.get_max(i, idx);
    ans = max(ans, 1ll * (max_x - min_x) * (max_y - min_y));
  }

  cout << ans << endl;
}