#include <iostream>
#include <vector>
#include <queue>
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

int getdis(const vector<vector<int>>& field, const int fx, const int fy,
           const int gx, const int gy) {
  int ans = 999999;
  queue<aa> que;
  int memo[field.size()][field[0].size()];
  memset(memo, 999999, sizeof(memo));
  que.push(aa{fx, fy, 0});
  while (!que.empty()) {
    aa atop = que.front();
    que.pop();
    if (atop.x == gx && atop.y == gy) {
      ans = atop.turn;
      break;
    }
    for (int i = 0; i < 4; ++i) {
      const int nextx = atop.x + dx[i];
      const int nexty = atop.y + dy[i];
      if (nextx >= 0 && nextx < field[0].size() && nexty >= 0 && nexty < field.size() && !field[nexty][nextx]) {
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
public:
  bool operator()(const bb& l, const bb& r) {
    return l.turn > r.turn;
  }
};

int main() {
  while (1) {
    int H, W;
    cin >> H >> W;
    if (!H) break;

    vector<vector<int>> field(H + 2, vector<int>(W + 2, false));
    priority_queue<bb, vector<bb>, Compare> que;

    int memo2[H + 2][W + 2][4];
    memset(memo2, 999999, sizeof(memo2));

    int kx = 99, ky = 99;
    int ox[2];
    int oy[2];
    int num = 0;
    for (int i = 0; i < H; ++i) {
      string st;
      cin >> st;
      for (int j = 0; j < W; ++j) {
        if (st[j] == 'X') {
          kx = min(kx, j + 1);
          ky = min(ky, i + 1);
          field[i + 1][j + 1] = true;
        } else if (st[j] == 'o') {
          field[i + 1][j + 1] = true;
        } else if (st[j] == '.') {
          field[i + 1][j + 1] = true;
          ox[num] = j + 1;
          oy[num] = i + 1;
          num++;
        }
      }
    }

    if (kx == 1 && ky == 1) {
      cout << 0 << endl;
      continue;
    }

    for (int way = 0; way < 4; ++way) {
      int amin = 999999;
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
          if (field[gy][gx]) ok = false;
          for (int ax = 0; ax < 2; ++ax) {
            for (int ay = 0; ay < 2; ++ay) {
              field[ky + ay][kx + ax] = false;
            }
          }
          atime += getdis(field, fx, fy, gx, gy);
          for (int ax = 0; ax < 2; ++ax) {
            for (int ay = 0; ay < 2; ++ay) {
              field[ky + ay][kx + ax] = true;
            }
          }
        }
        amin = min(amin, atime);
      }
      if (!ok) continue;
      else {
        memo2[kx][ky][way] = amin;
        que.push(bb{kx, ky, way, amin});
      }
    }

    int ans = -1;
    while (!que.empty()) {
      bb atop = que.top();
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
        if (fway == tway) continue;
        int amin = 999999;
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
            if (field[gy][gx]) ok = false;
            for (int ax = 0; ax < 2; ++ax) {
              for (int ay = 0; ay < 2; ++ay) {