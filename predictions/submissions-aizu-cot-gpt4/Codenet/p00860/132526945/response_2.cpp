#include <cctype>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
unsigned short vis[1 << 24];
char c[16][20];
bool wall[256];
int tm0;
inline bool check(int u, int v) {
  int p1 = v & 255;
  if (p1) {
    if (wall[p1] || p1 == ((v >> 8) & 255) || (p1 == (u & 255) && ((v >> 8) & 255) == (u >> 8 & 255))) {
      return false;
    }
  }
  p1 = v >> 8 & 255;
  if (p1) {
    if (wall[p1] || p1 == ((v >> 16) & 255) || (p1 == (u >> 8 & 255) && ((v >> 16) & 255) == (u >> 16 & 255))) {
      return false;
    }
  }
  p1 = v >> 16 & 255;
  if (p1) {
    if (wall[p1] || p1 == (u & 255) || (p1 == (u >> 16 & 255) && (u & 255) == (u >> 16 & 255))) {
      return false;
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
  while (1) {
    int u = q.front();
    q.pop();
    if (u < 0) {
      q.push(-1);
      ++tm;
    } else {
      int i1 = 0, i2 = 0, i3 = 0;
      if (u & 255) i1 = 4;
      if (u >> 8 & 255) i2 = 4;
      if (u >> 16) i3 = 4;
      for (; i1 >= 0; --i1)
        for (; i2 >= 0; --i2)
          for (; i3 >= 0; --i3) {
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
        switch (c[i][j]) {
          case '#':
            wall[i << 4 | j] = true;
            break;
          default:
            wall[i << 4 | j] = false;
            if (isupper(c[i][j])) {
              goal |= (i << 4 | j) << (c[i][j] - 'A') * 8;
            } else if (islower(c[i][j])) {
              start |= (i << 4 | j) << (c[i][j] - 'a') * 8;
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