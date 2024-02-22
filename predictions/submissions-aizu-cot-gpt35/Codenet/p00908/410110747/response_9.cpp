#include <iostream>
#include <vector>
#include <queue>
#include <string>
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
  int ans = -1;
  queue<aa> que;
  vector<vector<int>> memo(field.size(), vector<int>(field[0].size(), -1));
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

int main() {
  while (1) {
    int H, W;
    cin >> H >> W;
    if (!H)
      break;
    vector<vector<int>> field(H + 2, vector<int>(W + 2, false));
    vector<vector<vector<int>>> memo2(H + 2, vector<vector<int>>(W + 2, vector<int>(4, -1)));

    for (int i = 1; i <= H; ++i) {
      string st;
      cin >> st;
      for (int j = 1; j <= W; ++j) {
        if (st[j - 1] == 'X') {
          field[i][j] = true;
        }
      }
    }

    if (field[1][1]) {
      cout << 0 << endl;
      continue;
    }

    for (int k = 0; k < 4; ++k) {
      memo2[1][1][k] = 0;
    }

    queue<bb> que;
    que.push(bb{1, 1, 0, 0});

    int ans = -1;

    while (!que.empty()) {
      bb atop(que.front());
      que.pop();
      const int fkx = atop.kx;
      const int fky = atop.ky;
      const int fway = atop.opway;
      const int fturn = atop.turn;
      if (fkx == 1 && fky == 1) {
        ans = fturn;
        break;
      }
      for (int tway = 0; tway < 4; ++tway) {
        if (fway == tway)
          continue;
        int amin = -1;
        bool ok = true;
        for (int op = 0; op < 2; ++op) {
          int atime = 0;
          for (int lu = 0; lu < 2; ++lu) {
            int fx = fkx + dx2[fway];
            int fy = fky + dy2[fway];
            int gx = fkx + dx2[tway];
            int gy = fky + dy2[tway];
            if (lu == 1) {
              gx += dx[(tway + 1) % 4];
              gy += dy[(tway + 1) % 4];
            }
            if (op ^ lu) {
              fx += dx[(fway + 1) % 4];
              fy += dy[(fway + 1) % 4];
            }
            if (field[gy][gx])
              ok = false;
            for (int ax = 0; ax < 2; ++ax) {
              for (int ay = 0; ay < 2; ++ay) {
                field[fky + ay][fkx + ax] = true;
              }
            }
            atime += getdis(field, fx, fy, gx, gy);
            for (int ax = 0; ax < 2; ++ax) {
              for (int ay = 0; ay < 2; ++ay) {
                field[fky + ay][fkx + ax] = false;
              }
            }
          }
          amin = (amin == -1) ? atime : min(amin, atime);
        }
        if (!ok)
          continue;
        else {
          if (memo2[fkx][fky][tway] == -1 || memo2[fkx][fky][tway] > fturn + amin) {
            memo2[fkx][fky][tway] = fturn + amin;
            que.push(bb{fkx, fky, tway, fturn + amin});
          }
        }
      }
      {
        const int nkx = fkx + dx[fway];
        const int nky = fky + dy[fway];
        const int nway = (fway + 2) % 4;
        if (memo2[nkx][nky][nway] == -1 || memo2[nkx][nky][nway] > fturn + 1) {
          memo2[nkx][nky][nway] = fturn + 1;
          que.push(bb{nkx, nky, nway, fturn + 1});
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}