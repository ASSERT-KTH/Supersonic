#include "bits/stdc++.h"
using namespace std;
const int d[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
const int d2[4][2] = {{-1, 0}, {0, 2}, {2, 1}, {1, -1}};

struct aa {
  int x, y, turn;
};

struct bb {
  int kx, ky, opway, turn;
};

class Compare {
public:
  bool operator()(const bb &l, const bb &r) { return l.turn > r.turn; }
};

int memo2[60][60][4];

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
      const int nextx = atop.x + d[i][0];
      const int nexty = atop.y + d[i][1];
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

int main() {
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
        for (int j = 0; j < W; ++j) {
          char ch;
          cin >> ch;
          if (ch == 'X') {
            kx = min(kx, j + 1);
            ky = min(ky, i + 1);
            field[i + 1][j + 1] = false;
          } else if (ch == 'o') {
            field[i + 1][j + 1] = false;
          } else if (ch == '.') {
            field[i + 1][j + 1] = false;
            ox[num] = j + 1;
            oy[num] = i + 1;
            num++;
          }
        }
      }

      // remaining code as it is...
    }
    // remaining code as it is...
  }
  return 0;
}