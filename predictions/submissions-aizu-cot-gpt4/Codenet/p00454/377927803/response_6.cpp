#include <algorithm>
#include <array>
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
#include <unordered_set>
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

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vpii = vector<pii>;

constexpr int inf = 1e9;
constexpr ll linf = 3e18;
constexpr double eps = 1e-9;
int w, h;
int n;
array<int, 1005> x1, x2;
array<int, 1005> y1, y2;
bool fld[1005 * 6 + 2][1005 * 6 + 2];
array<int, 4> dx = {-1, 0, 1, 0};
array<int, 4> dy = {0, -1, 0, 1};

int compress(array<int, 1005> &x1, array<int, 1005> &x2, int w) {
  unordered_set<int> xs;
  rep(i, n) {
    for (int d = -1; d <= 1; ++d) {
      int tx1 = x1[i] + d, tx2 = x2[i] + d;
      if (0 <= tx1 && tx1 <= w)
        xs.insert(tx1);
      if (0 <= tx2 && tx2 <= w)
        xs.insert(tx2);
    }
  }
  vi xs_sorted(xs.begin(), xs.end());
  sort(xs_sorted.begin(), xs_sorted.end());
  rep(i, n) {
    x1[i] = lower_bound(xs_sorted.begin(), xs_sorted.end(), x1[i]) - xs_sorted.begin();
    x2[i] = lower_bound(xs_sorted.begin(), xs_sorted.end(), x2[i]) - xs_sorted.begin();
  }
  return xs.size();
}

int main() {
  omajinai;
  while (cin >> w >> h, w) {
    cin >> n;
    memset(fld, 0, sizeof fld);
    rep(i, n) { cin >> x1[i] >> y1[i] >> x2[i] >> y2[i]; }
    w = compress(x1, x2, w);
    h = compress(y1, y2, h);
    rep(i, n) {
      for (int y = y1[i]; y <= y2[i] - 1; ++y) {
        for (int x = x1[i]; x <= x2[i] - 1; ++x) {
          fld[y][x] = true;
        }
      }
    }
    int ans = 0;
    rep(y, h - 1) rep(x, w - 1) {
      if (fld[y][x])
        continue;
      ans++;
      queue<pii> q;
      q.emplace(y, x);
      while (!q.empty()) {
        pii p = q.front();
        q.pop();
        rep(i, 4) {
          int ny = p.fst + dy[i], nx = p.scd + dx[i];
          if (ny < 0 || ny >= h - 1 || nx < 0 || nx >= w - 1 || fld[ny][nx])
            continue;
          fld[ny][nx] = true;
          q.emplace(ny, nx);
        }
      }
    }
    cout << ans << '\n';
  }
}