#include <cctype>
#include <cstdio>
#include <cstring>
#include <bitset>
#include <queue>
#include <vector>
using namespace std;

bitset<1 << 24> vis;
vector<int> wall;

int tm0;

inline bool check(int u, int v) {
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
  vis[start] = true;
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
            if (!vis[v]) {
              if (check(u, v)) {
                if (v == goal) {
                  return tm;
                }
                vis[v] = true;
                q.push(v);
              }
            }
          }
    }
  }
}

int main() {
  int w, h;
  while (scanf("%d%d%*d ", &w, &h), w) {
    for (int i = 0; i < h; ++i) {
      char line[20];
      scanf("%s", line);
      for (int j = 0; j < w; ++j) {
        if (line[j] == '#') {
          wall.push_back(i << 4 | j);
        } else {
          if (isupper(line[j])) {
            int pos = (i << 4 | j) << (line[j] - 'A') * 8;
            wall.push_back(pos);
          }
        }
      }
    }
    int goal = wall.back();
    int start = wall.front();
    wall.pop_back();
    wall.erase(wall.begin());
    int tm = solve(start, goal);
    printf("%d\n", tm - tm0);
    tm0 = tm + 1;
    if (tm0 > 55000) {
      vis.reset();
      tm0 = 0;
    }
  }
}