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
#define y1 hogwhoasjfd
#define fst first
#define scd second
#define PB push_back
#define MP make_pair
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define omajinai ios::sync_with_stdio(false); cin.tie(0)
#define rep(i, x) for (int i = 0; i < (int)(x); ++i)
#define rep1(i, x) for (int i = 1; i <= (int)(x); ++i)
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vpii = vector<pii>;
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> p) {
  os << "(" << p.fst << ", " << p.scd << ")";
  return os;
}
template <class T> ostream &operator<<(ostream &os, const vector<T> v) {
  rep(i, v.size()) {
    if (i)
      os << ", ";
    os << v[i];
  }
  return os;
}
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
constexpr int inf = 1e9;
constexpr ll linf = 3e18;
constexpr double eps = 1e-9;
int w, h;
int n;
int x1[1005], x2[1005];
int y1[1005], y2[1005];
bool** fld;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};
int compress(int *x1, int *x2, int w) {
  vi xs;
  rep(i, n) {
    xs.push_back(max(0,x1[i]-1));
    xs.push_back(min(w,x1[i]+1));
    xs.push_back(max(0,x2[i]-1));
    xs.push_back(min(w,x2[i]+1));
  }
  sort(all(xs));
  xs.erase(unique(all(xs)), end(xs));
  rep(i, n) {
    x1[i] = lower_bound(all(xs), x1[i]) - begin(xs);
    x2[i] = lower_bound(all(xs), x2[i]) - begin(xs);
  }
  return xs.size();
}
int main() {
  omajinai;
  while (cin >> w >> h, w) {
    cin >> n;
    w = compress(x1, x2, w);
    h = compress(y1, y2, h);
    fld = new bool*[h];
    for(int i = 0; i < h; ++i) {
      fld[i] = new bool[w];
      memset(fld[i], 0, sizeof(bool) * w);
    }
    rep(i, n) {
      for (int y = y1[i]; y <= y2[i] - 1; ++y) {
        for (int x = x1[i]; x <= x2[i] - 1; ++x) {
          fld[y][x] = true;
        }
      }
    }
    ...
    for(int i = 0; i < h; ++i) {
      delete[] fld[i];
    }
    delete[] fld;
  }
}