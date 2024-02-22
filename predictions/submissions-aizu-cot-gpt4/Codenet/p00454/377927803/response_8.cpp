#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

constexpr int inf = 1e9;
constexpr long long linf = 3e18;
constexpr double eps = 1e-9;
constexpr int dx[4] = {-1, 0, 1, 0};
constexpr int dy[4] = {0, -1, 0, 1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int w, h, n;
  while (cin >> w >> h, w) {
    cin >> n;

    vector<int> x1(n), x2(n), y1(n), y2(n);
    vector<vector<bool>> fld(h, vector<bool>(w, false));

    for (int i = 0; i < n; ++i) {
      cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    }

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
}