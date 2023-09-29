#include <cctype>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
constexpr int MAX_VIS_SIZE = 1 << 24;
constexpr int MAX_C_SIZE1 = 16;
constexpr int MAX_C_SIZE2 = 20;
constexpr int MAX_WALL_SIZE = 256;
constexpr int MAX_DIF_SIZE = 5;
unsigned short vis[MAX_VIS_SIZE];
char c[MAX_C_SIZE1][MAX_C_SIZE2];
bool wall[MAX_WALL_SIZE];
int tm0;
inline bool check(int u, int v) {
  for (int i = 0; i < 24; i += 8) {
    int p1 = v >> i & 255;
    if (p1) {
      int j = i == 16 ? 0 : i + 8;
      if (wall[p1]) {
        return false;
      }
      int p2 = (v >> j) & 255;
      if (p1 == p2) {
        return false;
      }
      if (p1 == (u >> j & 255) && p2 == (u >> i & 255)) {
        return false;
      }
    }
  }
  return true;
}
int solve(int start, int goal) {
  const int dif[MAX_DIF_SIZE] = {0, -1, 1, -16, 16};
  queue<int> q;
  q.push(start);
  q.push(-1);
  int tm = tm0 + 1;
  vis[start] = tm;
  while (1) {
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
            if (check(u, v)) {
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
      fgets(c[i], 20, stdin);
    }
    int goal = 0;
    int start = 0;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        int shifted = i << 4 | j;
        wall[shifted] = c[i][j] == '#';
        if (!wall[shifted]) {
          if (isupper(c[i][j])) {
            goal |= shifted << (c[i][j] - 'A') * 8;
          } else if (islower(c[i][j])) {
            start |= shifted << (c[i][j] - 'a') * 8;
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