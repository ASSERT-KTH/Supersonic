#include <iostream>
#include <set>
#include <queue>
#include <cstring>
using namespace std;

int w, h;
int n;
int x1[1005], x2[1005];
int y1[1005], y2[1005];
bool fld[1005 * 6 + 2][1005 * 6 + 2];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int compress(int *x1, int *x2, int w, set<int>& xs) {
  for (int i = 0; i < n; ++i) {
    for (int d = -1; d <= 1; ++d) {
      int tx1 = x1[i] + d, tx2 = x2[i] + d;
      if (0 <= tx1 && tx1 <= w)
        xs.insert(tx1);
      if (0 <= tx2 && tx2 <= w)
        xs.insert(tx2);
    }
  }
  int idx = 0;
  for (auto it = xs.begin(); it != xs.end(); ++it) {
    *it = idx++;
  }
  for (int i = 0; i < n; ++i) {
    x1[i] = xs.find(x1[i])->second;
    x2[i] = xs.find(x2[i])->second;
  }
  return idx;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  while (cin >> w >> h, w) {
    cin >> n;
    memset(fld, 0, sizeof fld);
    set<int> xs, ys;
    for (int i = 0; i < n; ++i) {
      cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
      xs.insert(x1[i]);
      xs.insert(x2[i]);
      ys.insert(y1[i]);
      ys.insert(y2[i]);
    }
    w = compress(x1, x2, w, xs);
    h = compress(y1, y2, h, ys);
    for (int i = 0; i < n; ++i) {
      for (int y = y1[i]; y <= y2[i] - 1; ++y) {
        for (int x = x1[i]; x <= x2[i] - 1; ++x) {
          fld[y][x] = true;
        }
      }
    }
    int ans = 0;
    for (int y = 0; y < h - 1; ++y) {
      for (int x = 0; x < w - 1; ++x) {
        if (fld[y][x])
          continue;
        ans++;
        queue<pair<int, int>> q;
        q.push(make_pair(y, x));
        while (!q.empty()) {
          pair<int, int> p = q.front();
          q.pop();
          for (int i = 0; i < 4; ++i) {
            int ny = p.first + dy[i], nx = p.second + dx[i];
            if (ny < 0 || ny >= h - 1 || nx < 0 || nx >= w - 1 || fld[ny][nx])
              continue;
            fld[ny][nx] = true;
            q.push(make_pair(ny, nx));
          }
        }
      }
    }
    cout << ans << endl;
  }

  return 0;
}