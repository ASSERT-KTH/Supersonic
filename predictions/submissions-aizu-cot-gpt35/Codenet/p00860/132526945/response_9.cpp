#include <cstdio>
#include <array>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

bool wall[256];
std::array<std::array<char, 20>, 16> c;
std::vector<unsigned short> vis;

bool check(const std::tuple<int, int, int>& u, const std::tuple<int, int, int>& v) {
  for (int i = 0; i < 24; i += 8) {
    int p1 = std::get<1>(v) >> i & 255;
    if (p1) {
      int j = i == 16 ? 0 : i + 8;
      if (wall[p1]) {
        return false;
      }
      int p2 = (std::get<1>(v) >> j % 24) & 255;
      if (p1 == p2) {
        return false;
      }
      if (p1 == (std::get<1>(u) >> j % 24 & 255) && p2 == (std::get<1>(u) >> i % 24 & 255)) {
        return false;
      }
    }
  }
  return true;
}

int solve(int start, int goal) {
  const std::array<int, 5> dif = {0, -1, 1, -16, 16};
  std::queue<std::tuple<int, int, int>> q;
  q.push(std::make_tuple(start, -1, 0));
  int tm = 1;
  vis[start] = tm;
  while (true) {
    auto u = q.front();
    q.pop();
    if (std::get<0>(u) < 0) {
      q.push(std::make_tuple(-1, -1, std::get<2>(u) + 1));
      ++tm;
    } else {
      for (int i1 = std::get<0>(u) & 255 ? 4 : 0; i1 >= 0; --i1)
        for (int i2 = std::get<0>(u) >> 8 & 255 ? 4 : 0; i2 >= 0; --i2)
          for (int i3 = std::get<0>(u) >> 16 ? 4 : 0; i3 >= 0; --i3) {
            int v = std::get<0>(u) + dif[i1] + (dif[i2] << 8) + (dif[i3] << 16);
            if (vis[v] > 0) {
              continue;
            }
            if (check(u, std::make_tuple(v, 0, 0))) {
              if (v == goal) {
                return std::get<2>(u) + 1;
              }
              vis[v] = 1;
              q.push(std::make_tuple(v, 0, std::get<2>(u) + 1));
            }
          }
    }
  }
}

int main() {
  int w, h;
  while (scanf("%d%d%*d ", &w, &h), w) {
    for (int i = 0; i < h; ++i) {
      std::getline(std::cin, c[i]);
    }
    int goal = 0;
    int start = 0;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (c[i][j] == '#') {
          wall[i << 4 | j] = true;
        } else {
          wall[i << 4 | j] = false;
          if (std::isupper(c[i][j])) {
            goal |= (i << 4 | j) << (c[i][j] - 'A') * 8;
          } else if (std::islower(c[i][j])) {
            start |= (i << 4 | j) << (c[i][j] - 'a') * 8;
          }
        }
      }
    }
    int tm = solve(start, goal);
    puts(std::to_string(tm).c_str());
    if (tm > 55000) {
      vis.assign(1 << 24, 0);
    }
  }
}