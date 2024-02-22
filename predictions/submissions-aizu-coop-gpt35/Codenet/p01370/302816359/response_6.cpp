#include <iostream>
#include <queue>
#include <bitset>

struct Coordinate {
  int x;
  int y;
  int time;
};

const int m_t = 60;
const int max_size = 3 * m_t * (m_t + 1) + 1;
const int zero = max_size / 2;

int dx[6] = {0, 1, -1, 1, -1, 0};
int dy[6] = {1, 1, 0, 0, -1, -1};

int main() {
  int t, n;
  while (std::cin >> t >> n, t) {
    std::bitset<max_size> field;
    field.set();
    
    int x, y;
    for (int i = 0; i < n; i++) {
      std::cin >> x >> y;
      y = y * (m_t * 2 + m_t * 2 + 1 - std::abs(y)) / 2;
      field[zero + x + y] = 0;
    }
    
    int sx, sy;
    std::cin >> sx >> sy;
    x = sx;
    y = sy * (m_t * 2 + m_t * 2 + 1 - std::abs(sy)) / 2;
    field[zero + x + y] = 0;
    
    int ans = 0;
    std::queue<Coordinate> rt;
    rt.push({sx, sy, 0});
    
    while (!rt.empty()) {
      ans++;
      Coordinate current = rt.front();
      rt.pop();
      
      if (current.time < t) {
        for (int i = 0; i < 6; i++) {
          int nx = current.x + dx[i];
          int ny = (current.y + dy[i]) * (m_t * 2 + m_t * 2 + 1 - std::abs(current.y + dy[i])) / 2;
          int index = zero + nx + ny;
          if (field[index]) {
            field[index] = 0;
            rt.push({nx, current.y + dy[i], current.time + 1});
          }
        }
      }
    }
    
    std::cout << ans << std::endl;
  }
}