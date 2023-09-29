#include <bits/stdc++.h>
using namespace std;
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
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dx2[4] = {-1, 0, 2, 1};
const int dy2[4] = {0, 2, 1, -1};
int memo2[60][60][4];
int getdis(const vector<vector<int>> &field, const int fx, const int fy,
           const int gx, const int gy) {
  queue<aa> que;
  vector<vector<int>> memo(field.size(), vector<int>(field[0].size(), INT_MAX));
  que.push(aa{fx, fy, 0});
  while (!que.empty()) {
    aa atop(que.front());
    que.pop();
    if (atop.x == gx && atop.y == gy) {
      return atop.turn;
    }
    for (int i = 0; i < 4; ++i) {
      const int nextx = atop.x + dx[i];
      const int nexty = atop.y + dy[i];
      if (!field[nexty][nextx] && atop.turn + 1 < memo[nexty][nextx]) {
        memo[nexty][nextx] = atop.turn + 1;
        que.push(aa{nextx, nexty, atop.turn + 1});
      }
    }
  }
  return INT_MAX;
}
int main() {
  while (1) {
    fill(&memo2[0][0][0], &memo2[0][0][0]+sizeof(memo2)/sizeof(int), INT_MAX);
    int H, W;
    cin >> H >> W;
    if (!H) break;
    vector<vector<int>> field(H + 2, vector<int>(W + 2, true));
    priority_queue<bb, vector<bb>, Compare> que;
    int kx = 99, ky = 99, ox[2], oy[2], num=0;
    for (int i = 0; i < H; ++i) {
      string st;
      cin >> st;
      for (int j = 0; j < W; ++j) {
        if (st[j] == 'X') {
          kx = min(kx, j + 1);
          ky = min(ky, i + 1);
        } else if (st[j] == '.') {
          ox[num] = j + 1;
          oy[num] = i + 1;
          num++;
        }
        field[i + 1][j + 1] = (st[j] == 'o');
      }
    }
    if (kx == 1 && ky == 1) {
      cout << 0 << endl;
      continue;
    }
    for (int way = 0; way < 4; ++way) {
      int amin = INT_MAX;
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
          fill(&field[0][0], &field[0][0]+sizeof(field)/sizeof(int), true);
          atime += getdis(field, fx, fy, gx, gy);
          fill(&field[0][0], &field[0][0]+sizeof(field)/sizeof(int), false);
        }
        amin = min(amin, atime);
      }
      if (!ok) continue;
      memo2[kx][ky][way] = amin;
      que.push(bb{kx, ky, way, amin});
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
        if (fway == tway) continue;
        int amin = INT_MAX;
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
            fill(&field[0][0], &field[0][0]+sizeof(field)/sizeof(int), true);
            atime += getdis(field, fx, fy, gx, gy);
            fill(&field[0][0], &field[0][0]+sizeof(field)/sizeof(int), false);
          }
          amin = min(amin, atime);
        }
        if (!ok) continue;
        if (memo2[fkx][fky][tway] > fturn + amin) {
          memo2[fkx][fky][tway] = fturn + amin;
          que.push(bb{fkx, fky, tway, fturn + amin});
        }
      }
      const int nkx = fkx + dx[fway];
      const int nky = fky + dy[fway];
      const int nway = (fway + 2) % 4;
      if (memo2[nkx][nky][nway] > fturn + 1) {
        memo2[nkx][nky][nway] = fturn + 1;
        que.push(bb{nkx, nky, nway, fturn + 1});
      }
    }
    cout << ans << endl;
  }
  return 0;
}