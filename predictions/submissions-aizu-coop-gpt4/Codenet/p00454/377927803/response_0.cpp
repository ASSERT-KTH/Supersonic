#include <algorithm>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <cstring>
using namespace std;

#define rep(i, x) for (int i = 0; i < (int)(x); ++i)
#define all(a) a.begin(), a.end()
using pii = pair<int, int>;

int w, h;
int n;
int x1[1005], x2[1005];
int y1[1005], y2[1005];
bool fld[1005 * 6 + 2][1005 * 6 + 2];

int compress(int *x1, int *x2, int w) {
  vector<int> xs;
  rep(i, n) {
    for (int d = -1; d <= 1; ++d) {
      int tx1 = x1[i] + d, tx2 = x2[i] + d;
      if (0 <= tx1 && tx1 <= w)
        xs.push_back(tx1);
      if (0 <= tx2 && tx2 <= w)
        xs.push_back(tx2);
    }
  }
  sort(all(xs));
  xs.erase(unique(all(xs)), end(xs));
  
  unordered_map<int, int> xs_map;
  int idx = 0;
  for(int x : xs)
    xs_map[x] = idx++;

  rep(i, n) {
    x1[i] = xs_map[x1[i]];
    x2[i] = xs_map[x2[i]];
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
      for (int y = y1[i]; y <= y2[i] - 1; ++y) {
        for (int x = x1[i]; x <= x2[i] - 1; ++x) {
          fld[y][x] = true;
        }
      }
    }
    int ans = 0;
    vector<pii> q;
    int head = 0; // Our manual queue head index
    rep(y, h - 1) rep(x, w - 1) {
      if (fld[y][x])
        continue;
      ans++;
      q.push_back(pii(y, x));
      fld[y][x] = true;
      while (head < q.size()) {
        pii p = q[head++];
        int ny, nx;
        ny = p.first - 1, nx = p.second;
        if (ny >= 0 && !fld[ny][nx]) {
          q.push_back(pii(ny, nx));
          fld[ny][nx] = true;
        }
        ny = p.first, nx = p.second - 1;
        if (nx >= 0 && !fld[ny][nx]) {
          q.push_back(pii(ny, nx));
          fld[ny][nx] = true;
        }
        ny = p.first + 1, nx = p.second;
        if (ny < h - 1 && !fld[ny][nx]) {
          q.push_back(pii(ny, nx));
          fld[ny][nx] = true;
        }
        ny = p.first, nx = p.second + 1;
        if (nx < w - 1 && !fld[ny][nx]) {
          q.push_back(pii(ny, nx));
          fld[ny][nx] = true;
        }
      }
    }
    cout << ans << endl;
  }
}