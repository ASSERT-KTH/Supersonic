#include <cctype>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
static unsigned short vis[1 << 24]; // static to ensure zero initialization
bool wall[256];
int tm0;
inline bool check(int u, int v) {
  for (int i = 0; i < 24; i += 8) {
    const int p1 = v >> i & 255;
    if (p1) {
      const int j = i == 16 ? 0 : i + 8;
      if (wall[p1]) {
        return false;
      }
      const int p2 = (v >> (j % 24)) & 255;
      if (p1 == p2 || (p1 == (u >> (j % 24) & 255) && p2 == (u >> (i % 24) & 255))) {
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
  vis[start] = ++tm0;
  while (1) {
    const int u = q.front();
    q.pop();
    if (u < 0) {
      if (q.empty()) {
        return -1;
      }
      q.push(-1);
      ++tm0;
    } else {
      for (int i1 = u & 255 ? 4 : 0; i1 >= 0; --i1)
        for (int i2 = u >> 8 & 255 ? 4 : 0; i2 >= 0; --i2)
          for (int i3 = u >> 16 ? 4 : 0; i3 >= 0; --i3) {
            const int v = u + dif[i1] + (dif[i2] << 8) + (dif[i3] << 16);
            if (vis[v] >= tm0 || !check(u, v)) {
              continue;
            }
            if (v == goal) {
              return tm0;
            }
            vis[v] = tm0;
            q.push(v);
          }
    }
  }
}
int main() {
  int w, h;
  char c[16][20];
  while (scanf("%d%d%*d ", &w, &h), w) {
    for (int i = 0; i < h; ++i) {
      fgets(c[i], 20, stdin);
    }
    int goal = 0;
    int start = 0;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        const int idx = i << 4 | j;
        if (c[i][j] == '#') {
          wall[idx] = true;
        } else {
          wall[idx] = false;
          if (isupper(c[i][j])) {
            goal |= idx << (c[i][j] - 'A') * 8;
          } else if (islower(c[i][j])) {
            start |= idx << (c[i][j] - 'a') * 8;
          }
        }
      }
    }
    const int tm = solve(start, goal);
    printf("%d\n", tm - tm0 + 1);
    if (tm0 > 55000) {
      memset(vis, 0, sizeof vis);
      tm0 = 0;
    }
  }
}