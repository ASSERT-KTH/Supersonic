#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
#define rep(i, x) for (int i = 0; i < (int)(x); ++i)
using vi = vector<int>;
using pii = pair<int, int>;
constexpr int inf = 1e9;

int w, h;
int n;
int x1[1005], x2[1005];
int y1[1005], y2[1005];
bool fld[1005 * 6 + 2][1005 * 6 + 2];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int compress(int *x1, int *x2, int w) {
  vi xs;
  rep(i, n) {
    for (int d = -1; d <= 1; ++d) {
      int tx1 = x1[i] + d, tx2 = x2[i] + d;
      if (0 <= tx1 && tx1 <= w)
        xs.push_back(tx1);
      if (0 <= tx2 && tx2 <= w)
        xs.push_back(tx2);
    }
  }
  sort(xs.begin(), xs.end());
  xs.erase(unique(xs.begin(), xs.end()), xs.end());
  rep(i, n) {
    x1[i] = lower_bound(xs.begin(), xs.end(), x1[i]) - xs.begin();
    x2[i] = lower_bound(xs.begin(), xs.end(), x2[i]) - xs.begin();
  }
  return xs.size();
}

int main() {
  while (scanf("%d%d", &w, &h), w) {
    scanf("%d", &n);
    memset(fld, 0, sizeof fld);
    rep(i, n) { scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]); }
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
      q.push(pii(y, x));
      while (!q.empty()) {
        pii p = q.front();
        q.pop();
        rep(i, 4) {
          int ny = p.first + dy[i], nx = p.second + dx[i];
          if (ny < 0 || ny >= h - 1 || nx < 0 || nx >= w - 1 || fld[ny][nx])
            continue;
          fld[ny][nx] = true;
          q.push(pii(ny, nx));
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}