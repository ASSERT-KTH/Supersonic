#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int compress(int *x1, int *x2, int w, int n) {
  vector<int> xs;
  for (int i = 0; i < n; ++i) {
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
  for (int i = 0; i < n; ++i) {
    x1[i] = lower_bound(xs.begin(), xs.end(), x1[i]) - xs.begin();
    x2[i] = lower_bound(xs.begin(), xs.end(), x2[i]) - xs.begin();
  }
  return xs.size();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int xw, xh, n;
  int dx[4] = {-1, 0, 1, 0};
  int dy[4] = {0, -1, 0, 1};
  while (cin >> xw >> xh, xw) {
    cin >> n;
    vector<int> xx1(n), xx2(n), yy1(n), yy2(n);
    memset(fld, 0, sizeof fld);
    for (int i = 0; i < n; ++i) {
      cin >> xx1[i] >> yy1[i] >> xx2[i] >> yy2[i];
    }
    int w = compress(&xx1[0], &xx2[0], xw, n);
    int h = compress(&yy1[0], &yy2[0], xh, n);
    vector<bool> grid((xh-1) * (xw-1), false);
    for (int i = 0; i < n; ++i) {
      for (int y = yy1[i]; y <= yy2[i] - 1; ++y) {
        for (int x = xx1[i]; x <= xx2[i] - 1; ++x) {
          grid[y * (xw-1) + x] = true;
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < (xh-1) * (xw-1); ++i) {
      if (grid[i])
        continue;
      ans++;
      vector<pair<int, int>> q;
      q.push_back(make_pair(i / (xw-1), i % (xw-1)));
      while (!q.empty()) {
        pair<int, int> p = q[0];
        q.erase(q.begin());
        for (int j = 0; j < 4; ++j) {
          int ny = p.first + dy[j], nx = p.second + dx[j];
          if (ny < 0 || ny >= h - 1 || nx < 0 || nx >= w - 1 || grid[ny * (xw-1) + nx])
            continue;
          grid[ny * (xw-1) + nx] = true;
          q.push_back(make_pair(ny, nx));
        }
      }
    }
    cout << ans << endl;
  }
}