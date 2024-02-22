#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct SegTree {
  int n;
  vector<int> values;
  
  void init(int n_) {
    n = 1;
    while (n < n_)
      n *= 2;
    values.resize(2 * n);
    fill(values.begin(), values.end(), 0);
  }
  
  void update(int idx, int val) {
    idx += n - 1;
    values[idx] = val;
    while (idx > 0) {
      idx = (idx - 1) / 2;
      values[idx] = max(values[idx * 2 + 1], values[idx * 2 + 2]);
    }
  }
  
  int query(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r == -1)
      r = n;
    if (r <= a || b <= l)
      return 0;
    if (a <= l && r <= b)
      return values[k];
    int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return max(vl, vr);
  }
};

int X[200020], Y[200020];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int N, d;
  cin >> N >> d;
  
  SegTree x_seg, y_seg;
  x_seg.init(N), y_seg.init(N);
  
  vector<pair<int, int>> hoge(N);
  for (int i = 0; i < N; i++) {
    int x, y, b;
    cin >> x >> y >> b;
    X[i] = x, Y[i] = y;
    hoge[i] = make_pair(b, i);
  }
  
  partial_sort(hoge.begin(), hoge.begin() + d, hoge.end(), greater<pair<int, int>>());
  
  for (int i = 0; i < d; i++) {
    x_seg.update(i, X[hoge[i].second]);
    y_seg.update(i, Y[hoge[i].second]);
  }
  
  long long ans = 0;
  for (int i = 0; i < N - d + 1; i++) {
    int b = hoge[i].first;
    int max_x = x_seg.query(i, i + d);
    int min_x = max_x - d;
    int max_y = y_seg.query(i, i + d);
    int min_y = max_y - d;
    ans = max(ans, 1LL * (max_x - min_x) * (max_y - min_y));
  }
  
  cout << ans << endl;
}