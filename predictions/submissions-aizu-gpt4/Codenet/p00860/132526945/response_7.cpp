#include <cctype>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

constexpr unsigned int MAX_VISIT = 1 << 24;
constexpr unsigned int MAX_WALL = 256;
constexpr unsigned int MAX_I = 16;
constexpr unsigned int MAX_J = 20;

unsigned short vis[MAX_VISIT];
char c[MAX_I][MAX_J];
bool wall[MAX_WALL];
int tm0;

inline bool check(int u, int v) {
  static constexpr int SHIFT[] = {0, 8, 16};
  for (int i = 0; i < 3; ++i) {
    int p1 = v >> SHIFT[i] & 255;
    if (p1) {
      int j = (i + 1) % 3;
      if (wall[p1]) {
        return false;
      }
      int p2 = (v >> SHIFT[j]) & 255;
      if (p1 == p2) {
        return false;
      }
      if (p1 == (u >> SHIFT[j] & 255) && p2 == (u >> SHIFT[i] & 255)) {
        return false;
      }
    }
  }
  return true;
}

int solve(int start, int goal) {
  static const int dif[5] = {0, -1, 1, -16, 16};
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
      static const int SHIFT[] = {0, 8, 16};
      for (int i = 0; i < 3; ++i) {
        int mask = (u >> SHIFT[i]) & 255;
        for (int j = mask ? 4 : 0; j >= 0; --j) {
          int v = u + dif[j] << SHIFT[i];
          if (vis[v] <= tm0 || !check(u, v)) {
            continue;
          }
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
        int ij = i << 4 | j;
        if (c[i][j] == '#') {
          wall[ij] = true;
        } else {
          wall[ij] = false;
          if (isalpha(c[i][j])) {
            int shift = (toupper(c[i][j]) - 'A') * 8;
            int mask = ij << shift;
            if (isupper(c[i][j])) {
              goal |= mask;
            } else {
              start |= mask;
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