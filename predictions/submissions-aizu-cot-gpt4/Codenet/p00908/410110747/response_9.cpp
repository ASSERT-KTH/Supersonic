#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dx2[4] = {-1, 0, 2, 1};
const int dy2[4] = {0, 2, 1, -1};

struct aa {
  int x;
  int y;
  int turn;
};

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

constexpr int MAX = 60;
constexpr int INF = 999999;
int memo2[MAX][MAX][4];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  while (1) {
    for (int i = 0; i < MAX; ++i) {
      for (int j = 0; j < MAX; ++j) {
        for (int k = 0; k < 4; ++k) {
          memo2[i][j][k] = INF;
        }
      }
    }
    int H, W;
    std::cin >> H >> W;
    if (!H)
      break;
    std::vector<std::vector<int>> field(H + 2, std::vector<int>(W + 2, true));
    std::priority_queue<bb, std::vector<bb>, Compare> que;
    {
      int kx = 99, ky = 99;
      int ox[2];
      int oy[2];
      int num = 0;
      for (int i = 0; i < H; ++i) {
        std::string st;
        std::cin >> st;
        for (int j = 0; j < W; ++j) {
          if (st[j] == 'X') {
            kx = std::min(kx, j + 1);
            ky = std::min(ky, i + 1);
            field[i + 1][j + 1] = false;
          } else if (st[j] == 'o') {
            field[i + 1][j + 1] = false;
          } else if (st[j] == '.') {
            field[i + 1][j + 1] = false;
            ox[num] = j + 1;
            oy[num] = i + 1;
            num++;
          }
        }
      }
      if (kx == 1 && ky == 1) {
        std::cout << 0 << "\n";
        continue;
      }
      for (int way = 0; way < 4; ++way) {
        int amin = INF;
        bool ok = true;
        for (int op = 0; op < 2; ++op) {
          int atime = 0;
          for (int lu = 0; lu < 2; ++lu) {
            const int fx = ox[op ^ lu];
            const int fy = oy[op ^ lu];
            int gx = kx + dx2[way];
            int gy = ky + dy2[way];
            if (lu == 1) {
              gx += dx[(way + 1) % 4];
              gy += dy[(way + 1) % 4];
            }
            if (field[gy][gx])
              ok = false;
            for (int ax = 0; ax < 2; ++ax) {
              for (int ay = 0; ay < 2; ++ay) {
                field[ky + ay][kx + ax] = true;
              }
            }
            atime += getdis(field, fx, fy, gx, gy);
            for (int ax = 0; ax < 2; ++ax) {
              for (int ay = 0; ay < 2; ++ay) {
                field[ky + ay][kx + ax] = false;
              }
            }
          }
          amin = std::min(amin, atime);
        }
        if (!ok)
          continue;
        else {
          memo2[kx][ky][way] = amin;
          que.push(bb{kx, ky, way, amin});
        }
      }
    }
    int ans = -1;
    while (!que.empty()) {
      bb atop(que.top());
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
        int amin = INF;
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
          amin = std::min(amin, atime);
        }
        if (!ok)
          continue;
        else {
          if (memo2[fkx][fky][tway] > fturn + amin) {
            memo2[fkx][fky][tway] = fturn + amin;
            que.push(bb{fkx, fky, tway, fturn + amin});
          }
        }
      }
      {
        const int nkx = fkx + dx[fway];
        const int nky = fky + dy[fway];
        const int nway = (fway + 2) % 4;
        if (memo2[nkx][nky][nway] > fturn + 1) {
          memo2[nkx][nky][nway] = fturn + 1;
          que.push(bb{nkx, nky, nway, fturn + 1});
        }
      }
    }
    std::cout << ans << "\n";
  }
  return 0;
}