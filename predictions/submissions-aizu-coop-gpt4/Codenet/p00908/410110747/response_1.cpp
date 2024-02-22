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
public:
  bool operator()(const bb &l, const bb &r) { return l.turn > r.turn; }
};
int memo2[60][60][4];
int main() {
  // Initialize the global array once
  for (int i = 0; i < 60; ++i) {
    for (int j = 0; j < 60; ++j) {
      for (int k = 0; k < 4; ++k) {
        memo2[i][j][k] = 999999;
      }
    }
  }
  while (1) {
    int H, W;
    cin >> H >> W;
    if (!H)
      break;
    vector<vector<int>> field(H + 2, vector<int>(W + 2, true));
    priority_queue<bb, vector<bb>, Compare> que;
    {
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
    // Rest of the code remains the same...