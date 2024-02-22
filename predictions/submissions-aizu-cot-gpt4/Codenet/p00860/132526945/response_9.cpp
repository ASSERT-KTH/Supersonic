#include <cctype>
#include <cstdio>
#include <cstring>
#include <deque>
#include <set>
using namespace std;
set<int> vis;
char c[16][20];
int tm0;
inline bool check(int u, int v) {
  for (int i = 0; i < 24; i += 8) {
    int p1 = v >> i & 255;
    if (p1) {
      int j = i == 16 ? 0 : i + 8;
      if (c[p1 >> 4][p1 & 15] == '#') {
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
  const int dif[4] = {-1, 1, -16, 16};
  deque<int> q;
  q.push_back(start);
  q.push_back(-1);
  int tm = tm0 + 1;
  vis.insert(start);
  while (!q.empty()) {
    int u = q.front();
    q.pop_front();
    if (u < 0) {
      if(!q.empty()) q.push_back(-1);
      ++tm;
    } else {
      for (int i1 = u & 255 ? 3 : 0; i1 >= 0; --i1)
        for (int i2 = u >> 8 & 255 ? 3 : 0; i2 >= 0; --i2)
          for (int i3 = u >> 16 ? 3 : 0; i3 >= 0; --i3) {
            int v = u + dif[i1] + (dif[i2] << 8) + (dif[i3] << 16);
            if (vis.count(v) > 0) {
              continue;
            }
            if (check(u, v)) {
              if (v == goal) {
                return tm;
              }
              vis.insert(v);
              q.push_back(v);
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
        if (isupper(c[i][j])) {
          goal |= (i << 4 | j) << (c[i][j] - 'A') * 8;
        } else if (islower(c[i][j])) {
          start |= (i << 4 | j) << (c[i][j] - 'a') * 8;
        }
      }
    }
    int tm = solve(start, goal);
    printf("%d\n", tm - tm0);
    tm0 = tm + 1;
    if (tm0 > 55000) {
      vis.clear();
      tm0 = 0;
    }
  }
}