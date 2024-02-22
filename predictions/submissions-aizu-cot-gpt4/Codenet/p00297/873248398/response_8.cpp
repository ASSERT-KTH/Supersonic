#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

const int inf = 1e9;

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

  void min_update(int idx, int val) {
    for (Min[idx += n] = val; idx > 1; idx >>= 1)
      Min[idx>>1] = min(Min[idx], Min[idx^1]);
  }

  void max_update(int idx, int val) {
    for (Max[idx += n] = val; idx > 1; idx >>= 1)
      Max[idx>>1] = max(Max[idx], Max[idx^1]);
  }

  int get_min(int a, int b) {
    int res = inf;
    for (a += n, b += n; a < b; a >>= 1, b >>= 1) {
      if (a & 1) res = min(res, Min[a++]);
      if (b & 1) res = min(res, Min[--b]);
    }
    return res;
  }

  int get_max(int a, int b) {
    int res = -inf;
    for (a += n, b += n; a < b; a >>= 1, b >>= 1) {
      if (a & 1) res = max(res, Max[a++]);
      if (b & 1) res = max(res, Max[--b]);
    }
    return res;
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
  vpii hoge;
  for (int i = 0; i < N; ++i) {
    int x, y, b;
    cin >> x >> y >> b;
    X[i] = x, Y[i] = y;
    hoge.push_back(pii(b, i));
  }
  sort(hoge.begin(), hoge.end());
  for (int i = 0; i < N; ++i) {
    x_seg.min_update(i, X[hoge[i].second]);
    x_seg.max_update(i, X[hoge[i].second]);
    y_seg.min_update(i, Y[hoge[i].second]);
    y_seg.max_update(i, Y[hoge[i].second]);
  }
  ll ans = -inf;
  for (int i = 0; i < N; ++i) {
    int b = hoge[i].first;
    int idx = i;
    while (idx < N && hoge[idx].first - b <= d)
      ++idx;
    int min_x = x_seg.get_min(i, idx);
    int max_x = x_seg.get_max(i, idx);
    int min_y = y_seg.get_min(i, idx);
    int max_y = y_seg.get_max(i, idx);
    ans = max(ans, 1ll * (max_x - min_x) * (max_y - min_y));
  }
  cout << ans << endl;
  return 0;
}