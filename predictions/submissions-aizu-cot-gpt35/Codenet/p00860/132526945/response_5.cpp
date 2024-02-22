#include <queue>

using namespace std;

short vis[1 << 24];
short wall[1 << 24];

inline bool check(int u, int v) {
  int diff = v & ~u;
  return (diff & wall[v]) == 0;
}

int solve(int start, int goal) {
  const int dif[5] = {0, -1, 1, -16, 16};
  queue<int> q;
  q.push(start);
  q.push(-1);
  int tm = 0;
  vis[start] = 1;
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
            if (vis[v] > 0) {
              continue;
            }
            if (check(u, v)) {
              if (v == goal) {
                return tm;
              }
              vis[v] = 1;
              q.push(v);
            }
          }
    }
  }
}

int main() {
  int w, h;
  do {
    scanf("%d%d%*d ", &w, &h);
    for (int i = 0; i < h; ++i) {
      fgets(c[i], 20, stdin);
    }
    int goal = 0;
    int start = 0;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (c[i][j] == '#') {
          wall[i << 4 | j] = 1;
        } else {
          wall[i << 4 | j] = 0;
          if (isupper(c[i][j])) {
            goal |= (i << 4 | j) << (c[i][j] - 'A') * 8;
          } else if (islower(c[i][j])) {
            start |= (i << 4 | j) << (c[i][j] - 'a') * 8;
          }
        }
      }
    }
    int tm = solve(start, goal);
    printf("%d\n", tm);
  } while (w != 0);
}