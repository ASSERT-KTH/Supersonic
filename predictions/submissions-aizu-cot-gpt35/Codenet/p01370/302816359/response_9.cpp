#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int m_t = 60;
const int max = 3 * m_t * (m_t + 1) + 1;
const int zero = max / 2;

int dx[6] = {0, 1, -1, 1, -1, 0};
int dy[6] = {1, 1, 0, 0, -1, -1};

int main() {
  int t, n;
  while (cin >> t >> n, t) {
    vector<int> field(max, 1);
    int x, y;
    for (int i = 0; i < n; i++) {
      cin >> x >> y;
      y = y * (2 * m_t + 2 * m_t + 1 - abs(y)) / 2;
      field[zero + x + y] = 0;
    }
    int sx, sy;
    cin >> sx >> sy;
    x = sx;
    y = sy * (2 * m_t + 2 * m_t + 1 - abs(sy)) / 2;
    field[zero + x + y] = 0;
    int ans = 0;
    queue<pair<pair<int, int>, int>> rt;
    rt.push(make_pair(make_pair(sx, sy), 0));
    while (!rt.empty()) {
      ans++;
      const int cx = rt.front().first.first;
      const int cy = rt.front().first.second;
      const int ct = rt.front().second;
      rt.pop();
      if (ct < t) {
        for (int i = 0; i < 6; i++) {
          const int nx = cx + dx[i];
          const int ny = (cy + dy[i]) * (2 * m_t + 2 * m_t + 1 - abs(cy + dy[i])) / 2;
          if (field[zero + nx + ny]) {
            field[zero + nx + ny] = 0;
            rt.push(make_pair(make_pair(nx, cy + dy[i]), ct + 1));
          }
        }
      }
    }
    cout << ans << endl;
  }
}