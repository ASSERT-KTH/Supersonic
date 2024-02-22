#include <queue>
#include <vector>
#include <iostream>

#define rep(i, b) for (int i = 0; i < b; i++)
#define m_t 60
#define max (3 * m_t * (m_t + 1) + 1)
#define zero (max / 2)
#define mp make_pair

int dx[6] = {0, 1, -1, 1, -1, 0};
int dy[6] = {1, 1, 0, 0, -1, -1};
std::vector<int> field(max);

int main() {
  int t, n;
  while (std::cin >> t >> n, t) {
    field.assign(max, 1);
    int x, y;
    rep(i, n) {
      std::cin >> x >> y;
      y = y * (m_t + 1 - abs(y)) / 2;
      field[zero + x + y] = 0;
    }
    int sx, sy;
    std::cin >> sx >> sy;
    x = sx;
    y = sy * (m_t + 1 - abs(sy)) / 2;
    field[zero + x + y] = 0;
    int ans = 0;
    std::queue<std::pair<std::pair<int, int>, int>> rt;
    rt.push(mp(mp(sx, sy), 1));
    while (!rt.empty()) {
      ans++;
      int cx = rt.front().first.first;
      int cy = rt.front().first.second;
      int ct = rt.front().second;
      rt.pop();
      if (ct <= t) {
        rep(i, 6) {
          int nx = cx + dx[i];
          int ny = (cy + dy[i]) * (m_t + 1 - abs(cy + dy[i])) / 2;
          if (field[zero + nx + ny]) {
            field[zero + nx + ny] = 0;
            rt.push(mp(mp(nx, cy + dy[i]), ct + 1));
          }
        }
      }
    }
    std::cout << ans << std::endl;
  }
}