#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
constexpr int MAX_VIS = 1 << 24;
constexpr int MAX_H = 16;
constexpr int MAX_W = 20;
unsigned short vis[MAX_VIS];
char c[MAX_H][MAX_W];
bool wall[256];
int tm0;
inline int get_block(int v, int i) { return (v >> i) & 255; }
inline bool check(int u, int v) {
  for (int i = 0; i < 24; i += 8) {
    int p1 = get_block(v, i);
    if (p1) {
      int j = (i + 8) % 24;
      if (wall[p1]) return false;
      int p2 = get_block(v, j);
      if (p1 == p2 || (p1 == get_block(u, j) && p2 == get_block(u, i))) return false;
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
    int u = q.front(); q.pop();
    if (u < 0) {
      q.push(-1);
      ++tm;
    } else {
      for (int i1 = get_block(u, 0) ? 4 : 0; i1 >= 0; --i1)
        for (int i2 = get_block(u, 8) ? 4 : 0; i2 >= 0; --i2)
          for (int i3 = get_block(u, 16) ? 4 : 0; i3 >= 0; --i3) {
            int v = u + dif[i1] + (dif[i2] << 8) + (dif[i3] << 16);
            if (vis[v] > tm0) continue;
            if (check(u, v)) {
              if (v == goal) return tm;
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
    for (int i = 0; i < h; ++i) fgets(c[i], MAX_W, stdin);
    int goal = 0, start = 0;
    for (int i = 0; i < h; ++i)
      for (int j = 0; j < w; ++j) {
        int pos = i << 4 | j;
        if (c[i][j] == '#') wall[pos] = true;
        else {
          wall[pos] = false;
          if (isupper(c[i][j])) goal |= pos << (c[i][j] - 'A') * 8;
          else if (islower(c[i][j])) start |= pos << (c[i][j] - 'a') * 8;
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