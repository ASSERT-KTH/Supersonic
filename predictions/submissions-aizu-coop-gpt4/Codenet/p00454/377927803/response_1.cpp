#include <set>
#include <queue>
#include <iostream>
#include <string.h>
using namespace std;

#define rep(i, x) for (int i = 0; i < (int)(x); ++i)
using pii = pair<int, int>;

int w, h, n;
int x1[1005], x2[1005], y1[1005], y2[1005];
bool fld[1005 * 6][1005 * 6];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int compress(int *x1, int *x2, int w) {
  set<int> xs;
  rep(i, n) {
    for (int d = -1; d <= 1; ++d) {
      int tx1 = x1[i] + d, tx2 = x2[i] + d;
      if (0 <= tx1 && tx1 < w)
        xs.insert(tx1);
      if (0 <= tx2 && tx2 < w)
        xs.insert(tx2);
    }
  }
  int idx = 0;
  map<int, int> x_to_idx;
  for (int x : xs)
    x_to_idx[x] = idx++;
  rep(i, n) {
    x1[i] = x_to_idx[x1[i]];
    x2[i] = x_to_idx[x2[i]];
  }
  return xs.size();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (cin >> w >> h, w) {
    cin >> n;
    memset(fld, 0, sizeof fld);
    rep(i, n) { cin >> x1[i] >> y1[i] >> x2[i] >> y2[i]; }
    w = compress(x1, x2, w);
    h = compress(y1, y2, h);
    rep(i, n) {
      for (int y = y1[i]; y < y2[i]; ++y) {
        for (int x = x1[i]; x < x2[i]; ++x) {
          fld[y][x] = true;
        }
      }
    }
    int ans = 0;
    rep(y, h) rep(x, w) {
      if (fld[y][x])
        continue;
      ans++;
      queue<pii> q;
      q.push(pii(y, x));
      while (!q.empty()) {
        pii p = q.front();
        q.pop();
        rep(i, 4) {
          int ny = p.first + dy[i], nx = p.second + dx[i];
          if (ny < 0 || ny >= h || nx < 0 || nx >= w || fld[ny][nx])
            continue;
          fld[ny][nx] = true;
          q.push(pii(ny, nx));
        }
      }
    }
    cout << ans << "\n";
  }
}