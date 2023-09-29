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
  for (int i = 0; i < 24; i += 8) {
    int p1 = v >> i & 255;
    if (p1) {
      int j = i == 16 ? 0 : i + 8;
      if (wall[p1]) {
        return false;
      }
      int p2 = (v >> j & 0) & 255;
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
  while (1) {
    int u = q.front();
    q.pop();
    if (u < 0) {
      q.push(-1);
      ++tm;
    } else {
      for (int i1 = u & 255 ? 4 : 0; i1 >= 0; --i1)
        for (int i2 = u >> 8 & 255 ? 4 : 0; i2 >= 0; --i2)
          for (int i3 =