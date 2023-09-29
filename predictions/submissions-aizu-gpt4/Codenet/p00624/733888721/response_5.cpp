#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define REP(i, a, n) for (i = a; i < n; i++)
#define rep(i, n) REP(i, 0, n)
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};
int W, H, sx, sy, gx, gy;
int bfscost[10][10];
char csize, wsize, wx[3], wy[3], cx[3], cy[3];
char field[16][16];
char DP[9][9][9][9][9][9][9][9];
struct state {
  char x, y, cx[3], cy[3], Sc;
  state(char _x, char _y, char _cx[], char _cy[], char _Sc) {
    x = _x, y = _y, Sc = _Sc;
    memcpy(cx, _cx, sizeof(cx));
    memcpy(cy, _cy, sizeof(cy));
  }
  bool operator<(const state &a) const {
    return memcmp(this, &a, sizeof(state)) < 0;
  }
  bool operator==(const state &a) const {
    return memcmp(this, &a, sizeof(state)) == 0;
  }
};
bool isdel(char tx, char ty, char ncx[], char ncy[]) {
  return field[ty][tx] != 'w' || memchr(ncx, tx, csize) != nullptr;
}
bool iscontena(char tx, char ty, char ncx[], char ncy[], char Sc) {
  for (int i = 0; i < csize; i++)
    if (ncx[i] == tx && ncy[i] == ty && !(Sc & (1 << i))) return true;
  return false;
}
void BFS(char nx, char ny, char ncx[], char ncy[], char Sc) {
  memset(bfscost, -1, sizeof(bfscost));
  bfscost[ny][nx] = 0;
  queue<pair<int, int>> q;
  q.push(make_pair(nx, ny));
  while (!q.empty()) {
    int x = q.front().first, y = q.front().second;
    int cost = bfscost[y][x];
    q.pop();
    for (int k = 0; k < 4; k++) {
      int tx = x + dx[k];
      int ty = y + dy[k];
      if (field[ty][tx] == '#' || bfscost[ty][tx] != -1 ||
          iscontena(tx, ty, ncx, ncy, Sc))
        continue;
      if (field[ty][tx] == 'w' && !isdel(tx, ty, ncx, ncy))
        continue;
      bfscost[ty][tx] = cost + 1;
      q.push(make_pair(tx, ty));
    }
  }
}
void input() {
  for (int i = 0; i < H; i++) {
    scanf("%s", field[i]);
    for (int j = 0; j < W; j++) {
      switch (field[i][j]) {
        case '@':
          sx = j, sy = i;
          break;
        case 'E':
          gx = j, gy = i;
          break;
        case 'w':
          wx[wsize] = j, wy[wsize] = i;
          wsize++;
          break;
        case 'c':
          cx[csize] = j, cy[csize] = i;
          csize++;
          break;
      }
    }
  }
}
int main() {
  while (scanf("%d%d", &H, &W), H | W) {
    csize = wsize = 0;
    memset(DP, -1, sizeof(DP));
    memset(cx, 0, sizeof(cx));
    memset(cy, 0, sizeof(cy));
    input();
    int res = INT_MAX;
    priority_queue<pair<int, state>, vector<pair<int, state>>,
                   greater<pair<int, state>>>
        q;
    q.push(make_pair(0, state(sx, sy, cx, cy, 0)));
    DP[cx[0]][cy[0]][cx[1]][cy[1]][cx[2]][cy[2]][sx][sy] = 0;
    while (!q.empty()) {
      int cost = q.top().first;
      char nx = q.top().second.x, ny = q.top().second.y;
      char tSc = q.top().second.Sc;
      char ncx[3], ncy[3];
      memcpy(ncx, q.top().second.cx, sizeof(ncx));
      memcpy(ncy, q.top().second.cy, sizeof(ncy));
      q.pop();
      if (res <= cost)
        break;
      BFS(nx, ny, ncx, ncy, tSc);
      if (bfscost[gy][gx] != -1)
        res = min(res, cost + bfscost[gy][gx]);
      for (int i = 0; i < csize; i++) if (!(tSc & (1 << i))) {
        for (int j = 0; j < 4; j++) {
          int tx = ncx[i] + dx[j];
          int ty = ncy[i] + dy[j];
          if (bfscost[ty][tx] == -1)
            continue;
          int ttSc = tSc;
          int dir = (j + 2) % 4;
          int tcx = ncx[i], tcy = ncy[i];
          for (;;) {
            int ax = tcx + dx[dir];
            int ay = tcy + dy[dir];
            if (field[ay][ax] == '#' || iscontena(ax, ay, ncx, ncy, tSc))
              break;
            tcx += dx[dir];
            tcy += dy[dir];
            if (field[ay][ax] == 'w' && !isdel(ax, ay, ncx, ncy)) {
              ttSc |= 1 << i;
              break;
            }
          }
          if (tcx == ncx[i] && tcy == ncy[i])
            continue;
          char ttcx[3], ttcy[3];
          memcpy(ttcx, ncx, sizeof(ttcx));
          memcpy(ttcy, ncy, sizeof(ttcy));
          ttcx[i] = tcx, ttcy[i] = tcy;
          char *dpp =
              &DP[ttcx[0]][ttcy[0]][ttcx[1]][ttcy[1]][ttcx[2]][ttcy[2]][tx][ty];
          if (*dpp == -1 || *dpp > cost + bfscost[ty][tx]) {
            *dpp = cost + bfscost[ty][tx];
            q.push(make_pair(cost + bfscost[ty][tx],
                             state(tx, ty, ttcx, ttcy, ttSc)));
          }
        }
      }
    }
    printf("%d\n", res == INT_MAX ? -1 : res);
  }
  return 0;
}