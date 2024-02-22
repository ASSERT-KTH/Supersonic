#include <algorithm>
#include <climits>
#include <vector>
using namespace std;
#define all(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair
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
  void update(int idx, int val, vector<int>& seg, bool isMax) {
    idx += n - 1;
    seg[idx] = val;
    while (idx > 0) {
      idx = (idx - 1) / 2;
      seg[idx] = isMax ? max(seg[idx * 2 + 1], seg[idx * 2 + 2]) : min(seg[idx * 2 + 1], seg[idx * 2 + 2]);
    }
  }
  int get(int a, int b, int k = 0, int l = 0, int r = -1, bool isMax = false) {
    if (r == -1)
      r = n;
    if (r <= a || b <= l)
      return isMax ? -inf : inf;
    if (a <= l && r <= b)
      return isMax ? Max[k] : Min[k];
    int vl = get(a, b, k * 2 + 1, l, (l + r) / 2, isMax);
    int vr = get(a, b, k * 2 + 2, (l + r) / 2, r, isMax);
    return isMax ? max(vl, vr) : min(vl, vr);
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, d;
  cin >> N >> d;
  SegTree seg;
  seg.init(N);
  vpii hoge(N);
  for (int i = 0; i < N; ++i) {
    int x, y, b;
    cin >> x >> y >> b;
    hoge[i] = make_pair(b, x << 16 | y);
  }
  sort(all(hoge));
  for (int i = 0; i < N; ++i) {
    int x = hoge[i].second >> 16, y = hoge[i].second & 0xFFFF;
    seg.update(i, x, seg.Min, false);
    seg.update(i, y, seg.Min, false);
    seg.update(i, x, seg.Max, true);
    seg.update(i, y, seg.Max, true);
  }
  ll ans = -inf;
  for (int i = 0; i < N; ++i) {
    int b = hoge[i].first;
    int idx = upper_bound(all(hoge), pii(b + d, inf)) - hoge.begin();
    int min_x = seg.get(i, idx, 0, 0, -1, false);
    int max_x = seg.get(i, idx, 0, 0, -1, true);
    int min_y = seg.get(i, idx, 0, 0, -1, false);
    int max_y = seg.get(i, idx, 0, 0, -1, true);
    ans = max(ans, 1ll * (max_x - min_x) * (max_y - min_y));
  }
  cout << ans << '\n';
  return 0;
}