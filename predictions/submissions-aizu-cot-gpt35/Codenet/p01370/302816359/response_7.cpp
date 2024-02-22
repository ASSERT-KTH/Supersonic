#include <iostream>
#include <queue>
#include <vector>

struct Position {
  int x;
  int y;
  int moves;
};

constexpr int m_t = 60;
constexpr int max = 3 * m_t * (m_t + 1) + 1;
constexpr int zero = max / 2;
constexpr int dx[6] = {0, 1, -1, 1, -1, 0};
constexpr int dy[6] = {1, 1, 0, 0, -1, -1};

int main() {
  int t, n;
  while (std::cin >> t >> n, t) {
    std::vector<bool> field(max, true);
    int x, y;
    for (int i = 0; i < n; i++) {
      std::cin >> x >> y;
      y = y * (2 * m_t + 1 - abs(y)) / 2;
      field[zero + x + y] = false;
    }
    int sx, sy;
    std::cin >> sx >> sy;
    x = sx;
    y = sy * (2 * m_t + 1 - abs(sy)) / 2;
    field[zero + x + y] = false;

    int ans = 0;
    std::queue<Position> rt;
    rt.push({sx, sy, 0});
    while (!rt.empty()) {
      ans++;
      Position pos = rt.front();
      rt.pop();
      if (pos.moves < t) {
        for (int i = 0; i < 6; i++) {
          int nx = pos.x + dx[i];
          int ny = (pos.y + dy[i]) * (2 * m_t + 1 - abs(pos.y + dy[i])) / 2;
          if (field[zero + nx + ny]) {
            field[zero + nx + ny] = false;
            rt.push({nx, pos.y + dy[i], pos.moves + 1});
          }
        }
      }
    }
    std::cout << ans << std::endl;
  }

  return 0;
}