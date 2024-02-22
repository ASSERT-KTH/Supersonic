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
  int memo[60][60] = {999999};
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
      if (atop.turn + 1 < memo[nexty][nextx]) {
        memo[nexty][nextx] = atop.turn + 1;
        que.push(aa{nextx, nexty, atop.turn + 1});
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
  bool operator()(const bb& l, const bb& r) { return l.turn > r.turn; }
};

int memo2[60][60][4];

int main() {
  while (true) {
    for (int i = 0; i < 60; ++i) {
      for (int j = 0; j < 60; ++j) {
        for (int k = 0; k < 4; ++k) {
          memo2[i][j][k] = 999999;
        }
      }
    }
    int H, W;
    cin >> H >> W;
    if (H == 0)
      break;
    int field[62][62] = {true};
    priority_queue<bb, vector<bb>, Compare> que;
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
          if (field[gy][gx])
            ok = false;
          for (int ax = 0; ax < 2; ++ax) {
            for (int ay = 0; ay < 2; ++ay) {
              field[ky + ay][kx + ax] = true;
            }
          }
          atime += getdis(field, fx, fy, gx, gy);