#include <iostream>
#include <vector>
using namespace std;

#define omajinai                                                               \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0)
#define rep(i, x) for (int i = 0; i < (int)(x); ++i)
#define all(a) a.begin(), a.end()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

const int inf = 1e9;

struct SegTree {
  int n;
  vector<int> MinMax;

  void init(int n_) {
    n = 1;
    while (n < n_)
      n *= 2;
    MinMax.resize(2 * n, inf);
  }

  void update(int idx, int val) {
    idx += n - 1;
    MinMax[idx] = val;
    while (idx > 0) {
      idx = (idx - 1) / 2;
      MinMax[idx] = min(MinMax[idx * 2 + 1], MinMax[idx * 2 + 2]);
      MinMax[idx + n] = max(MinMax[idx * 2 + 1 + n], MinMax[idx * 2 + 2 + n]);
    }
  }

  int get_min(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r == -1)
      r = n;
    if (r <= a || b <= l)
      return inf;
    if (a <= l && r <= b)
      return MinMax[k];
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
      return MinMax[k + n];
    int vl = get_max(a, b, k * 2 + 1, l, (l + r) / 2);
    int vr = get_max(a, b, k * 2 + 2, (l + r) / 2, r);
    return max(vl, vr);
  }
};

int main() {
  omajinai;
  int N, d;
  cin >> N >> d;

  SegTree x_seg, y_seg;
  x_seg.init(N), y_seg.init(N);

  vector<int> X(N), Y(N);
  vector<pii> hoge(N);

  rep(i, N) {
    int x, y, b;
    cin >> x >> y >> b;
    X[i] = x, Y[i] = y;
    hoge[i] = pii(b, i);
  }

  ll ans = -inf;

  rep(i, N) {
    int b = hoge[i].first;
    int idx = upper_bound(all(hoge), pii(b + d, inf)) - hoge.begin();
    int min_x = x_seg.get_min(i, idx);
    int max_x = x_seg.get_max(i, idx);
    int min_y = y_seg.get_min(i, idx);
    int max_y = y_seg.get_max(i, idx);
    ans = max(ans, 1ll * (max_x - min_x) * (max_y - min_y));
  }

  cout << ans << endl;

  return 0;
}