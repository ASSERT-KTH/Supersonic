#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAX_H = 16;
const int MAX_W = 20;

unsigned short vis[1 << 24];
char grid[MAX_H][MAX_W];
bool wall[256];
int tm0;

bool is_valid_move(int u, int v) {
  for (int i = 0; i < 24; i += 8) {
    int p1 = v >> i & 255;
    if (p1) {
      int j = i == 16 ? 0 : i + 8;
      if (wall[p1]) {
        return false;
      }
      int p2 = (v >> j % 24) & 255;
      if (p1 == p2) {
        return false;
      }
      if (p1 == (u >> j % 24 & 255) && p2 == (u >> i % 24 & 255)) {
        return false;
      }
    }
  }
  return true;
}

int solve(int start, int goal) {
  const int dif[5] = {0, -1, 1, -16, 16};
  queue<int> q;
  q.push(start);
  q.push(-1);
  int tm = tm0 + 1;
  vis[start] = tm;
  while (true) {
    int u = q.front();
    q.pop();
    if (u < 0) {
      q.push(-1);
      ++tm;
    } else {
      for (int i1 = u & 255 ? 4 : 0; i1 >= 0; --i1)
        for (int i2 = u >> 8 & 255 ? 4 : 0; i2 >= 0; --i2)
          for (int i3 = u >> 16 ? 4 : 0; i3 >= 0; --i3) {
            int v = u + dif[i1] + (dif[i2] << 8) + (dif[i3] << 16);
            if (vis[v] > tm0) {
              continue;
            }
            if (is_valid_move(u, v)) {
              if (v == goal) {
                return tm;
              }
              vis[v] = tm;
              q.push(v);
            }
          }
    }
  }
}

int main() {
  int w, h;
  while (scanf("%d%d%*d ", &w, &h), w) {
    for (int i = 0; i < h; ++i) {
      fgets(grid[i], MAX_W, stdin);
    }
    int goal = 0;
    int start = 0;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (grid[i][j] == '#') {
          wall[i << 4 | j] = true;
        } else {
          wall[i << 4 | j] = false;
          if (isupper(grid[i][j])) {
            goal |= (i << 4 | j) << (grid[i][j] - 'A') * 8;
          } else if (islower(grid[i][j])) {
            start |= (i << 4 | j) << (grid[i][j] - 'a') * 8;
          }
        }
      }
    }
    int tm = solve(start, goal);
    printf("%d\n", tm - tm0);
    tm0 = tm + 1;
    if (tm0 > 55000) {
      memset(vis, 0, sizeof vis);
      tm0 = 0;
    }
  }
}