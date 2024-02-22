#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

const int inf = 1e9;
const ll linf = 3e18;
const double eps = 1e-9;

struct SegTree {
  int n;
  vector<int> Max;
  vector<int> Min;
  void init(int n_) {
    n = 1;
    while (n < n_)
      n *= 2;
    Max.resize(2 * n, -inf);
    Min.resize(2 * n, inf);
  }
  void update(int idx, int val, bool isMax) {
    idx += n - 1;
    if (isMax)
      Max[idx] = val;
    else
      Min[idx] = val;
    while (idx > 0) {
      idx = (idx - 1) / 2;
      if (isMax)
        Max[idx] = max(Max[idx * 2 + 1], Max[idx * 2 + 2]);
      else
        Min[idx] = min(Min[idx * 2 + 1], Min[idx * 2 + 2]);
    }
  }
  int get(int a, int b, bool isMax, int k = 0, int l = 0, int r = -1) {
    if (r == -1)
      r = n;
    if (r <= a || b <= l)
      return isMax ? -inf : inf;
    if (a <= l && r <= b)
      return isMax ? Max[k] : Min[k];
    int vl = get(a, b, isMax, k * 2 + 1, l, (l + r) / 2);
    int vr = get(a, b, isMax, k * 2 + 2, (l + r) / 2, r);
    return isMax ? max(vl, vr) : min(vl, vr);
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
  vpii hoge;
  for (int i = 0; i < N; ++i) {
    int x, y, b;
    cin >> x >> y >> b;
    X[i] = x, Y[i] = y;
    hoge.push_back(pii(b, i));
  }
  sort(hoge.begin(), hoge.end());
  for (int i = 0; i < N; ++i) {
    x_seg.update(i, X[hoge[i].second], false);
    x_seg.update(i, X[hoge[i].second], true);
    y_seg.update(i, Y[hoge[i].second], false);
    y_seg.update(i, Y[hoge[i].second], true);
  }
  ll ans = -inf;
  for (int i = 0; i < N; ++i) {
    int b = hoge[i].first;
    int idx = upper_bound(hoge.begin(), hoge.end(), pii(b + d, inf)) - hoge.begin();
    int min_x = x_seg.get(i, idx, false);
    int max_x = x_seg.get(i, idx, true);
    int min_y = y_seg.get(i, idx, false);
    int max_y = y_seg.get(i, idx, true);
    ans = max(ans, 1ll * (max_x - min_x) * (max_y - min_y));
  }
  cout << ans << endl;
}