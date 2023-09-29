#include <cctype>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
constexpr int MAX_VIS = 1 << 24;
constexpr int MAX_C = 16;
constexpr int MAX_WALL = 256;
unsigned short vis[MAX_VIS];
char c[MAX_C][MAX_C];
bool wall[MAX_WALL];
int tm0;
inline bool check(int u, int v) {
  static const int shifts[] = {0, 8, 16};
  for (int i = 0; i < 3; ++i) {
    int p1 = v >> shifts[i] & 255;
    if (p1) {
      int j = shifts[(i + 1) % 3];
      if (wall[p1]) {
        return false;
      }
      int p2 = (v >> j) & 255;
      if (p1 == p2) {
        return false;
      }
      if (p1 == (u >> j & 255) && p2 == (u >> shifts[i] & 255)) {
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
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (u < 0) {
      if(!q.empty()) {
        q.push(-1);
      }
      ++tm;
      continue;
    }
    for (int i1 = u & 255 ? 4 : 0; i1 >= 0; --i1) {
      for (int i2 = u >> 8 & 255 ? 4 : 0; i2 >= 0; --i2) {
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
  return -1;
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
        int pos = i << 4 | j;
        if (c[i][j] == '#') {
          wall[pos] = true;
        } else {
          wall[pos] = false;
          if (isalpha(c[i][j])) {
            int shift = (toupper(c[i][j]) - 'A') * 8;
            int value = pos << shift;
            if (isupper(c[i][j])) {
              goal |= value;
            } else {
              start |= value;
            }
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