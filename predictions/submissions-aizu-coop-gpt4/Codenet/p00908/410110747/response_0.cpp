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
int getdis(const vector<vector<int>> &field, const int fx, const int fy,
           const int gx, const int gy) {
  // ...
}
struct bb {
  int kx;
  int ky;
  int opway;
  int turn;
};
class Compare {
public:
  bool operator()(const bb &l, const bb &r) { return l.turn > r.turn; }
};
int memo2[60][60][4];

// Reset memo2 to default state
void reset_memo2() {
  for (int i = 0; i < 60; ++i) {
    for (int j = 0; j < 60; ++j) {
      for (int k = 0; k < 4; ++k) {
        memo2[i][j][k] = 999999;
      }
    }
  }
}

int main() {
  while (1) {
    reset_memo2();
    // ...
    while (!que.empty()) {
      bb atop(que.top());
      que.pop();
      const int fkx = atop.kx;
      const int fky = atop.ky;
      const int fway = atop.opway;
      const int fturn = atop.turn;

      int fkx_dx2_fway = fkx + dx2[fway];
      int fky_dy2_fway = fky + dy2[fway];
      
      // ...
      for (int tway = 0; tway < 4; ++tway) {
        if (fway == tway)
          continue;
        // ...
        for (int op = 0; op < 2; ++op) {
          // ...
          for (int lu = 0; lu < 2; ++lu) {
            int fx = fkx_dx2_fway;
            int fy = fky_dy2_fway;
            int gx = fkx + dx2[tway];
            int gy = fky + dy2[tway];
            // ...
            if (field[gy][gx]) {
              ok = false;
              break;
            }
            // ...
          }
          if (!ok) break;
        }
        // ...
      }
      // ...
    }
    // ...
  }
  return 0;
}