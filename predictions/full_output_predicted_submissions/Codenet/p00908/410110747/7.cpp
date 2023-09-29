#include "bits/stdc++.h"
using namespace std;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dx2[4] = {-1, 0, 2, 1};
const int dy2[4] = {0, 2, 1, -1};
struct aa {
  int x;
  int y;
  int turn;
};
inline int getdis(const vector<vector<int>> &field, const int fx, const int fy,
           const int gx, const int gy) {
  int ans = 999999;
  queue<aa> que;
  vector<vector<int>> memo(field.size(), vector<int>(field[0].size(), 999999));
  que.push(aa{fx, fy, 0});
  while (!que.empty()) {
    aa atop(que.front());
    que.pop();
    if (atop.x == gx && atop.y == gy) {
      ans = atop.turn;
      break;
    }
    for (int i = 0; i < 4; ++i) {
      const int nextx = atop.x + dx[i];
      const int nexty = atop.y + dy[i];
      if (!field[nexty][nextx]) {
        if (atop.turn + 1 < memo[nexty][nextx]) {
          memo[nexty][nextx] = atop.turn + 1;
          que.push(aa{nextx, nexty, atop.turn + 1});
        }
      }
    }
  }
  return ans;
}
struct bb {
  int kx;
  int ky;
  int opway;
  int turn;
};
class Compare {