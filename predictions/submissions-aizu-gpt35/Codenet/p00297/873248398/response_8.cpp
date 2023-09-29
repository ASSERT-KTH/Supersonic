#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
#define fst first
#define scd second
#define PB push_back
#define MP make_pair
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define omajinai                                                               \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0)
#define rep(i, x) for (int i = 0; i < (int)(x); ++i)
#define rep1(i, x) for (int i = 1; i <= (int)(x); ++i)
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
template <typename T> T &max(T &a, T &b) {
  if (a >= b)
    return a;
  return b;
}
template <typename T> T &min(T &a, T &b) {
  if (a < b)
    return a;
  return b;
}
template <typename T> bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T> bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T> T get() {
  T a;
  cin >> a;
  return a;
}
template <typename T> T rev(T a) {
  reverse(all(a));
  return a;
}
template <typename T> vector<T> &sort(vector<T> &a) {
  sort(all(a));
  return a;
}
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
    Max.resize(2 * n);
    Min.resize(2 * n);
  }
  void min_update(int idx, int val) {
    idx += n;
    Min[idx] = val;
    while (idx > 1) {
      idx >>= 1;
      Min[idx] = min(Min[idx << 1], Min[(idx << 1) | 1]);
    }
  }
  void max_update(int idx, int val) {
    idx += n;
    Max[idx] = val;
    while (idx > 1) {
      idx >>= 1;
      Max[idx] = max(Max[idx << 1], Max[(idx << 1) | 1]);
    }
  }
  int get_min(int a, int b) {
    int res = inf;
    for (a += n, b += n; a < b; a >>= 1, b >>= 1) {
      if (a & 1)
        chmin(res, Min[a++]);
      if (b & 1)
        chmin(res, Min[--b]);
    }
    return res;
  }
  int get_max(int a, int b) {
    int res = -inf;
    for (a += n, b += n; a < b; a >>= 1, b >>= 1) {
      if (a & 1)
        chmax(res, Max[a++]);
      if (b & 1)
        chmax(res, Max[--b]);
    }
    return res;
  }
};
int X[200020], Y[200020];
signed main() {
  omajinai;
  int N, d;
  cin >> N >> d;
  SegTree x_seg, y_seg;
  x_seg.init(N), y_seg.init(N);
  vpii hoge;
  rep(i, N) {
    int x, y, b;
    cin >> x >> y >> b;
    X[i] = x, Y[i] = y;
    hoge.PB(pii(b, i));
  }
  sort(all(hoge));
  rep(i, N) {
    x_seg.min_update(i, X[hoge[i].scd]);
    x_seg.max_update(i, X[hoge[i].scd]);
    y_seg.min_update(i, Y[hoge[i].scd]);
    y_seg.max_update(i, Y[hoge[i].scd]);
  }
  ll ans = -inf;
  rep(i, N) {
    int b = hoge[i].fst;
    int idx = upper_bound(all(hoge), pii(b + d, inf)) - hoge.begin();
    int min_x = x_seg.get_min(i, idx);
    int max_x = x_seg.get_max(i, idx);
    int min_y = y_seg.get_min(i, idx);
    int max_y = y_seg.get_max(i, idx);
    ans = max(ans, 1ll * (max_x - min_x) * (max_y - min_y));
  }
  cout << ans << endl;
}
