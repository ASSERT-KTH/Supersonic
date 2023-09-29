#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
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
    if (x != a.x)
      return x < a.x;
    if (y != a.y)
      return y < a.y;
    if (Sc != a.Sc)
      return Sc < a.Sc;
    if (memcmp(cx, a.cx, sizeof(cx)) != 0)
      return memcmp(cx, a.cx, sizeof(cx)) < 0;
    return memcmp(cy, a.cy, sizeof(cy)) < 0;
  }
};
bool isdel(char tx, char ty, char ncx[], char ncy[]) {
  if (field[ty][tx] != 'w')
    return true;
  rep(i, csize) if (ncx[i] == tx && ncy[i] == ty) return true;
  return false;
}
bool iscontena(char tx, char ty, char ncx[], char ncy[], char Sc) {
  rep(i,
      csize) if (ncx[i] == tx && ncy[i] == ty && !(Sc & (1 << i))) return true;
  return false;
}
void BFS(char nx, char ny, char ncx[], char ncy[], char Sc) {
  int i, j, k;
  memset(bfscost, -1, sizeof(bfscost));
  bfscost[ny][nx] = 0;
  queue<pair<int, int>> q;
  q.push(make_pair(nx, ny));
  while (!q.empty()) {
    int x = q.front().first, y = q.front().second;
    int cost = bfscost[y][x];
    q.pop();
    rep(k, 4) {
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
  int i, j;
  rep(i, H) {
    scanf("%s", field[i]);
    rep(j, W) {
      if (field[i][j] == '@')
        sx = j, sy = i;
      if (field[i][j] == 'E')
        gx = j, gy = i;
      if (field[i][j] == 'w') {
        wx[wsize] = j, wy[wsize] = i;
        wsize++;
      }
      if (field[i][j] == 'c') {
        cx[csize] = j, cy[csize] = i;
        csize++;
      }
    }
  }
}
int main() {
  int i, j, k;
  while (scanf("%d%d", &H, &W), H | W) {
    csize = wsize = 0;
    memset(DP, -1, sizeof(DP));
    rep(i, 3) cx[i] = cy[i] = 0;
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
      rep(i, csize) if (!(tSc & (1 << i))) {
        rep(j, 4) {
          int tx = ncx[i] + dx[j];
          int ty = ncy[i] + dy[j];
          if (bfscost[ty][tx] == -1)
            continue;
          int ttSc = tSc;
          int dir = (j + 2) % 4;
          int tcx = ncx[i], tcy = ncy[i];
          for (;;) {
            int ay = tcy + dy[dir];
            int ax = tcx + dx[dir];
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